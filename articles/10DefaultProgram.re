= デフォルトプログラムでIoTを体験しよう

この章からは、Nefry BTにデフォルトで書き込まれているプログラムでIoTを体験していきます。Nefry BTで、どのようなことができるのか掴むことができるはずです！

== どんなことが体験できるの？
まず@<chap>{10DefaultProgram}では、デフォルトプログラムでどのようなことが体験できるのかと、プログラムの内容を解説します。@<chap>{11NefryWiFi}からは、実際に体験する手順を紹介します。

デフォルトプログラムでは、2つのサービスを使ったIoT体験ができます。

=== IFTTT
IFTTTというWebサービスを橋渡しに、FacebookやGMail、Twitterなど、300以上のさまざまなサービスとNefry BTを連携することができます。

//image[ifttt][IFTTT公式サイト][scale=0.8]{
//}
IFTTTを使うとプログラミングなしで多種多様な連携ができるようになるので、今回に限らず非常にオススメのサービスです。

本書ではNefry BTのスイッチを押したらTwitterに投稿をする方法を紹介します。

=== LINE Notify
LINE Notifyを使うと、色々なサービスからLINEにメッセージを送ることができます。

//image[linenotify][LINE Notify][scale=0.8]{
//}
手軽に個人やグループにLINEのメッセージを送れるため、IoTとの相性もバッチリです。

本書ではNefry BTのスイッチを押したらLINEにメッセージが届く方法を紹介します。

どちらのサービスもプログラムなしで手軽に体験できるので、ぜひ両方試してみてください。

===[column] Nefry BTに何のプログラムが書き込まれているか確認する方法

@<chap>{11NefryWiFi}を参考にして設定画面を開くと、画像の赤で囲われた部分にプログラム名が表示されます。

//image[program][書き込まれているプログラム名の確認][scale=0.8]{
//}
デフォルトプログラムの場合、「Nefry BT Default Program」と表示されていますのでそれを見て確認してください。

===[/column]

== デフォルトプログラムの書き込み
第Ⅰ部のプログラミング編などでプログラムの書き換えを行った場合は、デフォルトプログラムを書き込み直します。Nefry BTの開発環境を整えた上で実施してください。

Nefry BT購入後にプログラムを書き換えていない場合は、この手順は不要です。

次のプログラムをNefryに書き込んでください。このプログラムは、Arduino IDE のメニューからファイル ＞ スケッチ例 に移動し Nefry TutorialBook Example ＞ NefryBTdefaultprogram で呼び出すことができます。

//emlist[デフォルトプログラム][c]{
  #include <NefryIFTTT.h>
  #include <NefryLineNotify.h>
  #include <WiFiClientSecure.h>

  String Event, SecretKey, LineAuth, SendMessageLINE;

  void setup() {
    Nefry.setStoreTitle("SecretKey", 0); //Nefry DataStoreのタイトルを指定
    Nefry.setStoreTitle("Event", 1);    //Nefry DataStoreのタイトルを指定
    Nefry.setStoreTitle("LINE Auth", 2); //Nefry DataStoreのタイトルを指定
    Nefry.setStoreTitle("LINEMessage", 3);    //Nefry DataStoreのタイトルを指定

    SecretKey = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
    Event = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
    LineAuth = Nefry.getStoreStr(2);   //Nefry DataStoreからデータを取得
    SendMessageLINE = Nefry.getStoreStr(3);       //Nefry DataStoreからデータを取得

    Nefry.enableSW();                   //スイッチ有効化
    Nefry.setProgramName("NefryBT Default Program");//プログラム名登録
  }

  void loop() {
    if (Nefry.readSW()) {               //スイッチを押した時
      if (!SecretKey.equals("") && !Event.equals("")) {
        if (!IFTTT.send(Event, SecretKey)) {//IFTTTにデータを送信
          Nefry.setLed(255, 0, 0);        //Errの時、赤色点灯
        }
      }
      if (!LineAuth.equals("")) {
        if (SendMessageLINE.equals(""))
          SendMessageLINE = "Welcome to the NefryBT world!";
        LineNotify.send(LineAuth,SendMessageLINE);        //LINE送信
      }
      delay(1000);               //送信後1秒間待つ
    }
    Nefry.setLed(random(255), random(255), random(255));
    delay(500);               //送信後0.5秒間待つ
  }
//}

=== プログラム解説
ここではデフォルトプログラムがどのような制御をしているか簡単に紹介していきます。

Nefry BTを早く動かしてみたい場合は、次の章に進んでも問題ありません。

==== void setup関数内の処理
まず始めに、起動時に実行される@<code>{void setup} 関数内の処理を紹介します。
ここでは処理に必要な名前の設定や読み込みの準備をしています。

//emlist{
Nefry.setStoreTitle("SecretKey", 0); //Nefry DataStoreのタイトルを指定
Nefry.setStoreTitle("Event", 1);    //Nefry DataStoreのタイトルを指定
Nefry.setStoreTitle("LINE Auth", 2); //Nefry DataStoreのタイトルを指定
Nefry.setStoreTitle("LINEMessage", 3);    //Nefry DataStoreのタイトルを指定
//}

@<code>{Nefry.setStoreTitle} 関数でNefryの便利な機能のひとつの「DataStore」を準備します。
この関数ではDataStoreで表示するタイトルと文字を入力する場所を設定します。

//emlist{
SecretKey = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
Event = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
LineAuth = Nefry.getStoreStr(2);   //Nefry DataStoreからデータを取得
SendMessageLINE = Nefry.getStoreStr(3);       //Nefry DataStoreからデータを取得
//}

@<code>{Nefry.getStoreStr} 関数でDataStoreに入力された文字を取得することができます。
今回の場合はそれぞれ変数にデータを入れて、必要な時にそのデータを使えるようにしています。
IFTTTとLINEを連携させるためには４つ必要なデータがあるのでそれぞれ４回繰り返しています。

//image[datastore][Webコンソール上のDataStore設定箇所][scale=0.8]{
//}

//emlist{
Nefry.enableSW();                   //スイッチ有効化
Nefry.setProgramName("NefryBT Default Program");//プログラム名登録
//}

@<code>{Nefry.enableSW} 関数でNefry BTについているスイッチをいつ押されても大丈夫なように常時確認するようにします。

@<code>{Nefry.setProgramName} 関数でプログラム名を登録することができます。
登録しなくても大丈夫ですが、このプログラムが何をするものなのかを確認することができ、便利なので入力しておきます。

==== void loop関数内の処理
次に、繰り返し行われる@<code>{void loop}関数の紹介をします。

//emlist{
void loop() {
  if (Nefry.readSW()) {               //スイッチを押した時
    if (!SecretKey.equals("") && !Event.equals("")) {
      if (!IFTTT.send(Event, SecretKey)) {//IFTTTにデータを送信
        Nefry.setLed(255, 0, 0);        //Errの時、赤色点灯
      }
    }
    if (!LineAuth.equals("")) {
      if (SendMessageLINE.equals(""))
        SendMessageLINE = "Welcome to the NefryBT world!";
      LineNotify.send(LineAuth,SendMessageLINE);       //LINE送信
    }
    delay(1000);               //送信後1秒間待つ
  }
  Nefry.setLed(random(255), random(255), random(255));
  delay(500);               //送信後0.5秒間待つ
}
//}


ここではスイッチを押されたときに限り、IFTTTやLINE Notifyにメッセージを送信します。

@<code>{if (Nefry.readSW()} の部分でスイッチが押されたかどうかの判定を行い、押された場合に条件内の次の処理へ進みます。

==== IFTTTの処理
@<code>{if (!SecretKey.equals("") && !Event.equals("")) )} で、IFTTTに必要なデータがDataStoreで入力されているかどうかの判定を行います。入力されている場合は、条件内のIFTTTの処理へ進みます。

@<code>{if (!IFTTT.send(Event, SecretKey)) } で、IFTTTと通信結果の判定を行い、通信ができなかった場合にLEDを赤く光らせます。

==== LINE Notifyの処理
@<code>{if (!LineAuth.equals(""))} で、LINE Notifyと通信するときに必要となるトークンがDataStoreで入力されているかの判定を行います。入力されている場合は、条件内のLINE Notifyの処理へ進みます。

@<code>{if (SendMessageLINE.equals(""))} で、LINE Notifyで送るメッセージがDataStoreで入力されているのかの判定を行います。入力がない場合は@<code>{SendMessageLINE = "Welcome to the NefryBT world!"} の部分を実行してデフォルトメッセージを挿入します。

@<code>{LineNotify.send(LineAuth,SendMessageLINE)} 関数でLINE Notifyにメッセージを送信します。

後は0.5秒ごとにLEDをランダムなカラーに光らせるようになっています。
