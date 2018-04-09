
= 内蔵フルカラーLEDを使ってみよう
この章ではNefry BTの内蔵フルカラーLEDを操作する方法を仕組みを説明します。

Nefry BTにプログラムを書き込むにあたり、前の章までのArduino IDEのセットアップと書き込み方を確認しておいてください。


== 内蔵フルカラーLEDの位置
//image[03DefaultLed_01][内蔵フルカラーLEDの位置][scale=0.8]{
//}

== プログラムの書き込み
//image[03DefaultLed_02][次のコードに差し替えたウインドウ][scale=0.6]{
//}
Nefry BTの内臓LEDを光らせるコードです。このコードはスケッチ例から呼び出すことが可能です。


//image[03DefaultLed_04][スケッチ例の操作][scale=0.6]{
//}
Arduino IDE のメニューからファイル ＞ スケッチ例 に移動し Nefry TutorialBook Example ＞ DefaultLed で呼び出すことができます。


=== コードの説明
コードの説明をします。

//emlist{
#include <Nefry.h>
//}
まず、 @<code>{#include <Nefry.h>} によってNefry向けのライブラリを読み込んでいます。今回のフルカラーLEDの制御も含めていろいろな機能を使えるようになります。


//emlist{
void setup() {

}
//}
setupでくくられた部分には、起動時に行いたい動作を書き込みますが、今回はなにもしないので書き込みません。

//emlist{
// フルカラーLEDの色要素（赤 red,緑 green,青 blue）をいれる値の箱（変数）をつくる
int red,green,blue;
//}
以降は、起動後に繰り返す loop 部分の動きを作っていきます。



まず、Nefryでは @<code>{Nefry.setLED(R, G, B)} という関数でRGB（赤・青・緑）要素をそれぞれ指定できるので、@<code>{int red, green, blue;} でそれぞれを入れる値の箱を作ります。

//emlist{
void loop() {
  // random関数は0-255の数値をランダムに返します

  // フルカラーLEDの赤要素をランダムに指定
  red = random(255);
  // フルカラーLEDの緑要素をランダムに指定
  green = random(255);
  // フルカラーLEDの青要素をランダムに指定
  blue = random(255);
//}
繰り返し動作する loop の前半はrandom関数を使って、フルカラーLEDの赤・緑・青要素ををランダムに指定してカラフルに色が表示できる準備をします。

このあと、フルカラーLEDの色を実際に指定するために、フルカラーLEDの赤要素なら redという名前の値の箱（変数）、変数 green ならフルカラーLEDの緑要素を、変数 blue ならフルカラーLEDの青要素を入れています。

//emlist{
  // LEDがランダムに点灯します
  Nefry.setLed(red,green,blue);

  // 1秒待つ
  Nefry.ndelay(1000);
}
//}
いよいよ、繰り返し動作する loop の後半です。

先ほどの red  , green , blue を @<code>{Nefry.setLed(red,green,blue);} という記述で指示するとフルカラーLEDのカラーが変更されます。

最後に @<code>{Nefry.ndelay(1000);} で1秒プログラムを待つことができるので、繰り返し動作する loop は1秒ごとに動作する仕組みで電源をOFFにするまで動きつづけます。

== 確認
実際に書き込んで確認してみましょう。

//image[03DefaultLed_03][内蔵してあるフルカラーLEDがカラフルに光ります][scale=0.8]{
//}
無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるフルカラーLEDがカラフルに光ります。

== 試してみよう
この章で内蔵フルカラーLEDを操作することができました。

次のステップとして問題を2つほど出すのでぜひ試してみてください。

 * Q1
 ** 内蔵フルカラーLEDの光らせ方を現状の1秒からすごく早く200msecに変える
 * Q2
 ** 内蔵フルカラーLEDをカラーを青・赤・黄色とループで変えてみる

解答例は、Nefry TutorialBook Example ＞ DefaultLed Answer ＞ DefaultLed_Q1・Q2をご覧ください。
