= NefryでIoTを体験しよう

この章ではNefryでIoTを体験していきます。Nefryでどのようなことができるのか掴んでいただけるはずです！

== どんなことが体験できるの？

詳しい紹介はこの先の章で順に解説されますので、ここではシンプルにどのようなことができるのか紹介していこうと思います。
今回のプログラムでは2つのサービスを使ってIoTを体験していきます。

=== IFTTT

IFTTTというサービスを橋渡しにFacebookやGoogle、Mailなど他にも300以上ものサービスと連携することができます。

簡単な連携で多種多様なことができるようになるため非常にオススメのサービスです。

本書ではNefryのスイッチを押したらTwitterにメッセージを送るパターンを紹介します。

//image[ifttt][IFTTTサイト][scale=0.8]{
//}


=== LINE Notify

LINE Notifyとは色々なサービスからLINEにメッセージを送るサービスです。

手軽に個人やグループにメッセージを送れるため、Nefryとの相性もバッチリです。

本書ではNefryのスイッチを押したらLINEにメッセージが届くパターンを紹介します。

//image[linenotify][LINE Notify][scale=0.8]{
//}

どちらのサービスも手軽に体験できるのでぜひ両方試してみてください。

== プログラム情報

プログラムを書き込む場合は前のプログラミング編を参考に環境を整えた上で実施してください。
購入後にプログラムを書き換えていない場合はこの手順は不要です。

前のプログラミング編等で書き換えを行った場合は次のプログラムをNefryに書き込んでください。

このプログラムはNefry BTライブラリ1.2.1以降の場合、サンプルコードが同封されているのでそちらから開くことをお勧めします。

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

ここではデフォルトプログラムがどのように作られているのか簡単に紹介していきます。
上のプログラムがどのような意味があるのか気になる場合はこちらをご覧ください。

早く動かしてみたい場合は次の章に進んでも問題ありません。

//emlist{
Nefry.setStoreTitle("SecretKey", 0); //Nefry DataStoreのタイトルを指定
Nefry.setStoreTitle("Event", 1);    //Nefry DataStoreのタイトルを指定
Nefry.setStoreTitle("LINE Auth", 2); //Nefry DataStoreのタイトルを指定
Nefry.setStoreTitle("LINEMessage", 3);    //Nefry DataStoreのタイトルを指定

SecretKey = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
Event = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
LineAuth = Nefry.getStoreStr(2);   //Nefry DataStoreからデータを取得
SendMessageLINE = Nefry.getStoreStr(3);       //Nefry DataStoreからデータを取得
//}


まずはじめに、 @<code>{Nefry.setStoreTitle} 関数でNefryの便利な機能のひとつの「DataStore」を準備します。
この関数ではDataStoreで表示するタイトルと文字を入力する場所を設定します。
@<code>{#Nefry.getStoreStr}関数でDataStoreに入力された文字を取得することができます。
今回の場合はそれぞれ変数にデータを入れて、必要な時にそのデータを使えるようにしています。
IFTTTとLINEを連携させるためには４つ必要なデータがあるのでそれぞれ４回繰り返しています。

//image[datastore][DataStore][scale=0.8]{
//}

//emlist{
Nefry.enableSW();                   //スイッチ有効化
Nefry.setProgramName("NefryBT Default Program");//プログラム名登録
//}

@<code>{Nefry.enableSW()} 関数でNefryについているスイッチをいつ押されても大丈夫なように常時確認するようにします。

@<code>{Nefry.setProgramName} 関数でプログラム名を登録することができます。
もちろん登録しなくても大丈夫ですが、このプログラムがなにをするものなのかを確認することができ、便利なので入力しておきます。


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

次に繰り返し行われる@<code>{void loop()}関数の紹介をします。
ここではスイッチを押されたときに限り、IFTTTやLINEにメッセージを送信します。
@<code>{if (Nefry.readSW())}ここでスイッチが押されたときの判定を行い、押された場合に次のIFTTTやLINEの処理を行います。

 * IFTTT
@<code>{if (!SecretKey.equals("") && !Event.equals("")) )}ここでIFTTTに必要なデータがDataStoreで入力されているかどうかの判定を行い、入力されている場合、IFTTTと通信を行います。

@<code>{if (!IFTTT.send(Event, SecretKey)) }ここでIFTTTと通信結果の判定を行い、通信ができなかった場合にLEDを赤く光らせる判定を行います。

 * LINE
@<code>{if (!LineAuth.equals("")}ここでLINEと通信するときに必要となるトークンがDataStoreで入力されているかの判定を行います。入力されている場合にLINEの通信を行います。

@<code>{if (SendMessageLINE.equals(""))}合わせて、LINEで送るメッセージがDataStoreで入力されているのかの判定を行い、入力がない場合に@<code>{SendMessageLINE = "Welcome to the NefryBT world!"}を実行してメッセージを挿入します。

@<code>{LineNotify.send(LineAuth,SendMessageLINE)}関数でLINEにメッセージを送信します。

後は0.5秒ごとにLEDをランダムに光らせるようになっています。

以上がプログラムの全容になります。
