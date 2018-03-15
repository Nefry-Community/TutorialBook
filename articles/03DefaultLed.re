
= NefryでLEDを制御してみる

//comment{
  コードの書き方を伝える章
//}

このページではNefry BTでLEDを制御する方法を紹介します。
Nefry BTをArduino IDEで開発するにあたり、前の章を見てセットアップを済ませておいてください。

== Nefry BTをPCのUSBポートにさしてください。
 * Nefry BTをPCのUSBポートにさしてください。
 * メニューの@<tt>{ツール} > @<tt>{シリアルポート} > @<tt>{/dev/cu.usbserial-xxxxxx} を選択します。環境によっては @<tt>{/dev/tty.usbserial-xxxxxx}などの場合もあります。



（Windowsだと表記が違うようです。 ）

== プログラムの書き込み


メニューの@<tt>{ファイル} > @<tt>{新規ファイル}を選択します。



次のようなウインドウが表示されます。



//image[ide01][コード書き込み前]{
//}




初期状態で書かれている現状のコードを削除して、次のコードに差し替えましょう。


//emlist{
#include <Nefry.h>
//フルカラーLED　ランダムにカラーが変わります。
#define SEED_PIN A0

void setup() {
  randomSeed(analogRead(SEED_PIN));
}

int red,green,blue;
void loop() {
  red=random(255);//random関数は0-255の数値をランダムに返します。
  green=random(255);
  blue=random(255);
  Nefry.setLed(red,green,blue);//LEDがランダムに点灯します。
  String color="Red:";color+=red;
  color+=" Green:";color+=green;
  color+=" Blue:";color+=blue;
  Nefry.ndelay(1000);//1秒待つ
}
//}


@<tt>{A0}を指定していますが、乱数のSeed用に使っているだけで内蔵のLEDが@<tt>{A0}という訳ではないです。



//image[ide02][コード貼り付け後]{
//}



== プログラムの保存とボードに書き込み

//comment{
  手厚く書く
//}

左上の@<tt>{→}ボタンを押してボード（Nefry BT）にプログラムを書き込みます。


== 確認


無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるLEDがカラフルに光ります。



お疲れ様でした。
