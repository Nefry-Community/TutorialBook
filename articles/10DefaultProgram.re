
= NefryでIoTを体験しよう

この章ではNefryでIoTを体験するためにIFTTTとLINEと連携するプログラムを実際に動かしてみようと思います。

このプログラムは購入時にあらかじめ書き込まれているので、前のプログラミング編を行っていない場合はすぐ試すことができます。

前のプログラミング編を行った場合はこの章の最後にプログラムがあるのでそちらを確認して書き込んでください。

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
    Nefry.enableSW();                   //SW有効化
    Nefry.setProgramName("NefryBT Default Program");
  }

  void loop() {
    if (Nefry.readSW()) {               //SWを押した時
      if (!SecretKey.equals("") && !Event.equals("")) {
        if (!IFTTT.send(Event, SecretKey)) {//IFTTTにデータを送信
          Nefry.setLed(255, 0, 0);        //Errの時、赤色点灯
        }
      }
      if (!LineAuth.equals("")) {
        if (SendMessageLINE.equals(""))SendMessageLINE = "Welcome to the NefryBT world!";
        LineNotify.send(LineAuth,SendMessageLINE);                     //LINE送信
      }
      Nefry.ndelay(1000);               //送信後1秒間待つ
    }
    Nefry.setLed(random(255), random(255), random(255));
    Nefry.ndelay(500);               //送信後0.5秒間待つ
  }
//}
