+++
author = "wami"
author_username = "わみ"
weight = 26
slug = "nefrybt-tutorial"
title = "Nefry BTチュートリアル"
title_eng = "Nefry BT tutorial"
description = "Nefry BTのチュートリアル"
draft = false
doctype = ["nefrybt"]
date = "2018-01-23T01:02:41+09:00"
+++

NefryBTのハンズオンの記事になります。Arduinoも触ったことのないような初心者を対象としています。

[NefryBTでできること](https://qiita.com/wamisnet/items/306ce54840ab2382d753)は別の記事にまとまっています。

## NefryBTの開発環境を整えよう！

### Arduino IDEをインストールしよう

- Windows：[Nefryの環境を整えよう](http://nefry.studio/ArduinoIDE%E3%81%AE%E7%92%B0%E5%A2%83%E3%82%92%E6%95%B4%E3%81%88%E3%82%88%E3%81%86/)
- Mac：[Arduino IDEをPCにインストール](https://dotstud.io/docs/arduinoide-setup/)

### ArduinoIDEにNefryBTの環境を構築しよう
Nefry BTのライブラリバージョンは、 メジャーバージョン、マイナーバージョン、パッチバージョンに分かれています。

- メジャーバージョン - 大きな変更
- マイナーバージョン - 機能追加などの更新
- パッチバージョン - バグ修正など

例えばv1.2.3の場合、最初の1がメジャーバージョン、次の2がマイナーバージョン、最後の3がパッチバージョンとしています。

また、 安定版と開発版を分けていて、マイナーバージョンが偶数か奇数かで分けています。安定版がv1.2系、開発版がv1.1系などとなります。その次は安定版が1.4系、開発版がv1.3系となり、以降も偶数と奇数でのアップデートとなります。

参考 : [NefryBTのライブラリ](https://dotstud.io/docs/nefrybt-library/)

基本的には偶数のものをインストールしてください。現在(2018/1/21)では1.2.0が最も最新です。

参考：[Nefry BT向けのArduino IDEセットアップ方法](https://dotstud.io/docs/nefrybt-arduino-ide-setup/)

## ArduinoIDEでプログラムを書くために知っておくこと
先ほどの手順でインストールしたArduinoIDEを使ってNefryBTの上で動くプログラムを作成します。

### Arduinoのプログラムって？
NefryBTのプログラムはArduinoのプログラムと同じようにかけます。

ArduinoIDEが起動するとプログラムを入力するところに初めからこのようなプログラムが書いてあります。

```c++
void setup(){

}

void loop(){

}
```
![](https://wamisnet.github.io/pic/ren/pic015.png)

簡単に説明していきます。

```c++
void setup()
```
ここの部分では起動時に一度だけ行われる処理を書きます。 例えば、入出力ピンの設定や温度センサなどセンサ類の初期設定などを入力します。

```c++
void loop()
```
ここの部分では起動中ずっと繰り返し行われる処理を書きます。 例えば、LEDの点滅やセンサーデータの取得などを入力します。

NefryBTではこのsetupとloopをうまく活用してプログラムを書いていきます。

![](https://wamisnet.github.io/pic/ren/pic025.png)

参考 : [Nefryのプログラムを書こう](http://nefry.studio/Nefry%E3%81%AE%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%A0%E3%82%92%E6%9B%B8%E3%81%93%E3%81%86/)

## LEDを点滅させてみよう！
Arduinoの基礎を学んだところでLEDを点滅させるLチカと呼ばれるハードウエア入門してみましょう！

まずは一度だけLEDを点滅させてみましょう！
一度だけなので```void setup()```にLEDを点滅させるプログラムを書きます。
LEDの制御をするためには、```digitalWrite```という関数を呼び出し、制御します。
>関数の詳細については[こちら](http://www.musashinodenpa.com/arduino/ref/index.php?f=0&pos=2025)

関数の引数を確認すると、```digitalWrite(LED,LOW);```としたときに消灯、```digitalWrite(LED,HIGH);```としたときに点灯となります。
それをプログラムで表現してみます。

```c++
#define LED D6
//LEDをD6につないでください
void setup() {
  pinMode(LED, OUTPUT);//あらかじめLEDを制御できるように出力モードにしておきます
  digitalWrite(LED,HIGH);
  delay(5000);//5秒待つ
  digitalWrite(LED,LOW);
  delay(5000);
}

void loop() {
}
```

一度だけLチカできたでしょうか？
見損ねた場合、リセットボタンを押すとプログラムを再度初めから行うことができます。

それでは次のステップとして、LEDを何度も点滅させてみましょう！
何度もなので、今度は```void loop()```の中で同じ処理を書いてみます。

```c++
#define LED D6
//LEDをD6につないでください
void setup() {
  pinMode(LED, OUTPUT);//あらかじめLEDを制御できるように出力モードにしておきます
}

void loop() {
  digitalWrite(LED,HIGH);
  delay(5000);//5000ms//5秒待つ
  digitalWrite(LED,LOW);
  delay(5000);
}
```

Arduinoがどのようなものなのか少しでも理解できたでしょうか？
`void setup()`や`void loop()`をNefryBTのプログラムを作っていくので知っておいてください。
せっかくなのでdelayの秒数を変更してみたりして、あそんでみましょう。

余談なのですが、もっとLEDのON,OFFの間隔を狭くするとLEDの明るさをコントロールすることもできます。

```c++
#define LED D6
//LEDをD6につないでください
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED,HIGH);//あらかじめLEDを制御できるように出力モードにしておきます
  delayMicroseconds(100);//100us//10にも変更してみましょう
  digitalWrite(LED,LOW);
  delayMicroseconds(100);
}
```

## NefryBTの設定をしてみよう！

NefryシリーズではWiFiの設定やモジュールの設定が簡単にできるようになっています。

- 参考：WiFiの設定：[Nefry BTのWi-Fiセットアップ](https://dotstud.io/docs/nefrybt-wifi-setup/)
- 参考：モジュール設定の話：[Nefry BTのSSIDを変更する](https://dotstud.io/docs/nefrybt-change-ssid/)
- 参考：データストアの設定：[Nefry BTで変数を使う](https://sekaiokaeru.com/tips/nefrybt-variables)

## Nefryクラウドを使ってネットワークからNefryBTを動かしてみる

NefryBTではNefryクラウドを使うことで外部からの信号をきっかけにNefryBTを動かすことができます。

参考：[Nefryクラウド(仮)をつくってみた](https://qiita.com/wamisnet/items/38d6a5ac8332b090d0c2)

上の記事を参考に登録して、ユーザ名とAPIKeyを取得します。取得出来たものを下のプログラムのユーザ名とAPIKeyにそれぞれ入力してNefryBTに書き込みましょう！

```c++:NefryCloud.ino
#include <Nefry.h>
#include <NefryCloud.h>

NefryCloud nefryCloud;

void onpush(String message);

void setup() {
  nefryCloud.begin("user","apikey");//サイトで登録したuser,メールで受け取ったapikeyを入力してください
  nefryCloud.on(onpush);
  pinMode(LED, OUTPUT);//あらかじめLEDを制御できるように出力モードにしておきます
}

void loop() {
  nefryCloud.loop();
}

void onpush(String message) {//Nefryクラウド(仮)から通知が来ます
  Nefry.print("onpush : ");
  Nefry.println(message);
  if(message.equals("on")){
    //onという文字列がきたときに処理をする
    digitalWrite(LED,HIGH);
    delay(5000);//5秒待つ
    digitalWrite(LED,LOW);
    delay(5000);
  }
}
```

無事に書き込めたら、URLをブラウザから叩いてみましょう！
ユーザ名とサイトで取得したAPIKeyを置き換えて下のURLを叩いてください。
今回のプログラムではONという文字を受け取ったときにLEDを光るようにしているので```data=on```といった形でデータを合わせて送ります。

GETメソッド ```http://cloud.nefry.studio:1880/nefrysetting/setdata?user=ユーザ名&key=サイトで取得したAPIKey&data=on```


具体例としてWebページを作成してそこのページでボタンを押したら動かすこともできます。　

参考：[Nefry BTのLEDをWebから制御する #nefry](https://qiita.com/n0bisuke/items/ff0d1ddf41eaa13fd72a)

## IFTTTと連携してNefryBTからスマートフォンやTwitterに通知を飛ばしてみよう

こちらの記事を参考に進めていきます。

参考：[Nefry BTとIFTTTを連携する](https://dotstud.io/docs/nefrybt-ifttt/)

## GroveセンサとつないでIFTTTにセンサの値をおくってみよう！

こちらの記事を参考に進めていきます。

参考：[Nefry BTでほぼノンプログラムな湿度管理したい](https://qiita.com/tokutoku393/items/d4c91a28485bf568828c)
