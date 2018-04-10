
= 内蔵フルカラーLEDを使ってみよう
この章ではNefry BTの内蔵フルカラーLEDを操作する方法を仕組みを説明します。

Nefry BTにプログラムを書き込むにあたり、前の章までのArduino IDEのセットアップと書き込み方を確認しておいてください。


== 内蔵フルカラーLEDの位置
今回扱う内蔵フルカラーLEDの位置を確認します。
//image[03DefaultLed_01][内蔵フルカラーLEDの位置][scale=0.8]{
//}

== プログラムの書き込み

//image[03DefaultLed_04][スケッチ例の操作方法][scale=0.6]{
//}
NefryLibraryのバージョンが1.2.1以上の場合、Arduino IDE のメニューからファイル ＞ スケッチ例 に移動し Nefry TutorialBook Example ＞ DefaultLed でこの章で使うプログラムを開きましょう。

もし見当たらない場合、@<title>{preface} のサンプルプログラムの項目を参考にプログラムを導入してください。

//image[03DefaultLed_02][ランダムな色を光らせるプログラム][scale=0.6]{
//}

Nefry BTの内臓LEDを一秒ごとに光らせるコードになります。

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

まず、NefryではLEDの色をRGB（赤・青・緑）を指定できるので、@<code>{int red, green, blue;} で変数を作ります。

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
繰り返し動作する loop の前半はrandom関数を使って、LEDの赤・緑・青をランダムに生成してカラフルに表示できるように変数に値をいれます。

//emlist{
  // LEDがランダムに点灯します
  Nefry.setLed(red,green,blue);

  // 1秒待つ
  Nefry.ndelay(1000);
}
//}
loop の後半です。

先ほどの ランダムに数値を入れた変数を使い。 @<code>{Nefry.setLed}関数に赤、緑。青の順番でそれぞれの値を渡すとLEDの色が変更されます。

最後に @<code>{Nefry.ndelay(1000);} で1秒プログラムを止めます。
これでは1秒ごとにLEDの色を変更するプログラムが完成しました。

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
