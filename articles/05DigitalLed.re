
= GPIOを使って制御してみよう

この章では、Nefry BTのGPIOを使ってLEDを点滅させる仕組みを説明します。

GPIO（General Purpose Input/Output）とは、デジタル信号を出し入れする仕組みのことです。GPIOを使うことで、さまざまなセンサからデジタル信号の読み取り（入力）ができたり、Nefry BTからモーターやLEDにデジタル信号を送り（出力）動かしたり光らせたりすることができます。

Nefry BTの内蔵フルカラーLEDを利用したLチカ@<fn>{lchika}は、@<chap>{03DefaultLed}を参照して試してみましょう。


== Nefry BTのGPIOの位置
//image[05DigitalLED_01][Nefry BTのGPIOの位置][scale=0.8]{
//}
Nefry BTではGPIOを使えるGPIOピンとGroveポートが搭載されています。

GPIOピンでD0とD1がありますが、その二つのピンはディスプレイの制御（I2C通信）のために使用されているため正常に動作しないことがあります（Nefry BT R2で修正しました）。

ですので、今回はアナログピン（A1）でGPIO制御をしてみましょう。

== Nefry BT R2に、LEDを取り付ける。
//image[05DigitalLED_02][LEDのアソード・カソード][scale=0.8]{
//}
電子工作で使用するこのようなLEDを使って作業を進めます。

LEDの2本の配線から足の長短を確認してきましょう。足の長い方はカソードと言って+側に差し込みます。足の短い方はアノードと言って-側に差し込みます。

//image[05DigitalLED_03][Nefry R2の場合のLEDの足の差し込み方][scale=0.8]{
//}
Nefry BT R2 のA1ピンソケットにLEDの足の長い方を、隣のGNDピンソケットに足の短い方をとりつけます。

//image[05DigitalLED_04][Nefry BT R2 に差し込んだ状態][scale=0.8]{
//}
Nefry BT R2 に差し込んだ状態です。これでLEDの準備は完了です。

Nefry BTのリビジョンによってはA1ピンソケットの刻印位置が違うかもしれませんが、刻印にしたがってとりつけてください。

== プログラムの書き込み
次のコードでLEDが1秒ごと点滅します。

//image[05DigitalLED_05][プログラム][scale=0.6]{
//}
このコードは、Arduino IDE のメニューからファイル ＞ スケッチ例 に移動し Nefry TutorialBook Example ＞ DigitalLed で呼び出すことができます。

=== コードの説明

//emlist{
// LEDを光らせるアナログピン番号
#define LED_PIN A1
// 待ち時間（ミリ秒） 1000ミリ秒 = 1秒
#define DELAY_TIME 1000
//}

まずはじめに、 @<code>{#define LED_PIN A1} で準備しておきます。 @<code>{#define} は定義した文字列を定数や式などで置き換えるよという書き方です。
この場合、「LED_PINという文字列はA1という定数で置き換えるよ」という働きをしています。このあと、LEDを光らせるためのアナログピン番号として使います。

A1という記述は変数（値の箱）ですが、中身にはアナログピン番号の数字が決まっている定数です。
Nefry側であらかじめA1は○○番ピンと事前に準備していて、私たちが準備せずともすぐに使用できます。

@<code>{#define DELAY_TIME 1000} はこの場合、「DELAY_TIMEという文字列は1000という数字で置き換えるよ」という働きをしています。このあと、この値は待ち時間として使います。

//emlist{
void setup() {
  // LEDを光らせるピンを出力に指定
  pinMode(LED_PIN, OUTPUT);
}
//}

setupでは起動時の処理としてGPIOとしての電気信号がどう出入りするかの指示を出します。
@<code>{pinMode(LED_PIN, OUTPUT);} によって、LED_PINつまりA1ピンソケットは、電気信号が出力されるように動作します。

//emlist{
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
//}

繰り返し動作するloop部分では @<code>{digitalWrite(LED_PIN, HIGH);} によって、LEDを光らせるピンにデジタル出力の HIGH = ON を指示しています。
 @<code>{delay(DELAY_TIME);} によって、DELAY_TIME の時間つまり今回は1秒だけ待ちます。

続いて、 @<code>{digitalWrite(LED_PIN, LOW);} によって、LEDを光らせるピンにデジタル出力の LOW = OFF を指示しています。
その後、ONのときと同様に @<code>{delay(DELAY_TIME);} によって、1秒待ったあと繰り返します。

内部的にはこのように動作して、LEDが1秒光って1秒消えるという点滅します。

== 確認
実際に書き込んで確認してみましょう。

//image[05DigitalLED_06][LEDが点滅する流れ][scale=0.8]{
//}
無事にプログラム書き込みが終わると、先ほどつなげたLEDが点滅します。

== 試してみよう
この章でGPIOピンでLED点灯を制御させることができました。

次のステップとして問題を2つほど出すのでぜひ試してみてください。

 * Q1
 ** LEDの点滅する間隔をランダムにする
 * Q2
 ** 2つのGPIOピンを使ってLEDを2つ光らせる

解答例は、Nefry TutorialBook Example ＞ DigitalLed Answer ＞ DigitalLed_Q1・Q2をご覧ください。

//footnote[lchika][LEDをチカチカ（点滅）させること]
