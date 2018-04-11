# LEDでGPIO制御してみる

この章ではNefry BTにGPIOを使ってGrove LEDを点滅する仕組みを説明します。

GPIOとはデジタル信号を出し入れする仕組みのことです。GPIOをつかうことで、Nefry BTからさまざまなセンサーに合わせたデジタル信号の読み取り（入力）ができたり、Nefry BTからデジタル信号を送り（出力）モーターを動かしたりLEDを光らせることができます。

事前に、Nefry BTに組み込まれているフルカラーLEDを利用したLチカを [こちらのドキュメント](/docs/03DefaultLed) を参照して試してみましょう。

## Nefry BTのGPIOの位置

Nefry BTではGPIOを使える以下のGPIOピンとGroveポートが搭載されています。

![Nefry BTのGPIOの位置](05DigitalLED_01.jpg)

Nefry BTのピンでD0とD1がありますが、そのふたつのピンはディスプレイの制御（I2C通信）のために使用されているため正常に動作しないことがあります。（←Nefry BT R2で修正しました。）

ですので、今回はアナログピン（A1）でGPIO制御をしてみましょう。

## Nefry BT R2に、LEDを取り付ける。

電子工作で使用するこのようなLEDを使って作業を進めます。

![LEDのアソード・カソード](05DigitalLED_02.jpg)

LEDの2本の配線から足の長短を確認してきましょう。足の長い方はカソードと言って+側に差し込みます。足の短い方はアノードと言って-側に差し込みます。

![Nefry R2の場合のLEDの足の差し込み方](05DigitalLED_03.png)

Nefry BT R2 のA1ピンソケットにLEDの足の長い方を、隣のGNDピンソケットに足の短い方をとりつけます。

![Nefry BT R2 に差し込んだ状態](05DigitalLED_04.jpg)

Nefry BT R2 に差し込んだ状態です。これでLEDの準備は完了です。

Nefry BTの製造バージョンによってはA1ピンソケットとGNDピンソケットの刻印位置が違うかもしれませんが、刻印にしたがってとりつけてください。

## プログラムの書き込み

次のコードでLEDが1秒ごと点滅します。

![プログラム](05DigitalLED_05.png)

このコードは https://github.com/Nefry-Community/TutorialExample/tree/master/examples にある、 05DigitalLed のサンプルからコピー＆ペーストすることが可能です。

### コードの説明

```c
// LEDを光らせるアナログピン番号
#define LED_PIN A1
// 待ち時間（ミリ秒） 1000ミリ秒 = 1秒
#define DELAY_TIME 1000
```

まずはじめに、 ```#define LED_PIN A1``` で準備しておきます。 ```#define``` は定義した文字列を定数や式などで置き換えるよという書き方です。この場合、「LED_PINという文字列はA1という定数で置き換えるよ」という働きをしています。このあと、LEDを光らせるためのアナログピン番号として使います。

A1という記述は変数（値の箱）ですが、中身にはアナログピン番号の数字が決まっている定数です。Nefry側であらかじめA1は○○番ピンと事前に準備していて、私たちが準備せずともすぐに使用できます。

```#define DELAY_TIME 1000``` はこの場合、「DELAY_TIMEという文字列は1000という数字で置き換えるよ」という働きをしています。このあと、この値は待ち時間として使います。

```c
void setup() {
  // LEDを光らせるピンを出力に指定
  pinMode(LED_PIN, OUTPUT);
}
```

setupでは起動時の処理としてGPIOとしての電気信号がどう出入りするかの指示を出します。  ```pinMode(LED_PIN, OUTPUT);``` によって、LED_PINつまりA1ピンソケットは、電気信号が出力されるように動作します。

```c
void loop() {
  // LEDを光らせるピンにデジタル出力の HIGH = ON を指示
  digitalWrite(LED_PIN, HIGH);
  // DELAY_TIME の時間だけ待つ
  delay(DELAY_TIME);
  // LEDを光らせるピンにデジタル出力の LOW = OFF を指示
  digitalWrite(LED_PIN, LOW);
  // DELAY_TIME の時間だけ待つ
  delay(DELAY_TIME);
}
```

繰り返し動作するloop部分では ```digitalWrite(LED_PIN, HIGH);``` によって、LEDを光らせるピンにデジタル出力の HIGH = ON を指示しています。 ```delay(DELAY_TIME);``` によって、DELAY_TIME の時間つまり今回は1秒だけ待ちます。

続いて、 ```digitalWrite(LED_PIN, LOW);``` によって、LEDを光らせるピンにデジタル出力の LOW = OFF を指示しています。その後、ONのときと同様に ```delay(DELAY_TIME);``` によって、1秒待ったあと繰り返します。

このように内部的には動作して、LEDが1秒光って1秒消えるという点滅します。

## 確認

実際に書き込んで確認してみましょう。

![LEDが点滅する流れ](05DigitalLED_06.jpg)

無事にプログラム書き込みが終わると、先ほどつなげたLEDが点滅します。

お疲れ様でした。