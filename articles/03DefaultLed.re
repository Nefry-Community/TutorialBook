
= Nefryで内蔵フルカラーLEDを使ってみる


この章では内蔵フルカラーLEDを操作する方法を仕組みを説明します。



Nefry BTをArduino IDEで開発するにあたり、前の章を見てセットアップを済ませておいてください。


== 内蔵フルカラーLEDの位置


//image[03DefaultLed_01][内蔵フルカラーLEDの位置]{
//}



== プログラムの書き込み


//image[03DefaultLed_02][次のコードに差し替えたウインドウ]{
//}




このコードは https://github.com/Nefry-Community/TutorialExample/tree/master/examples にある、 03DefaultLed のサンプルからコピー＆ペーストすることが可能です。


=== コードの説明


コードの説明をします。


//emlist[][c]{
#include <Nefry.h>
//}


まず、 @<tt>{#include <Nefry.h>} によってNefry向けのライブラリを読み込んでいます。今回のフルカラーLEDの制御も含めていろいろな機能を使えるようになります。


//emlist[][c]{
void setup() {

}
//}


setupでくくられた部分には、起動時に行いたい動作を書き込みますが、今回はなにもしないので書き込みません。


//emlist{
// フルカラーLEDの色要素（赤 red,緑 green,青 blue）をいれる値の箱（変数）をつくる
int red,green,blue;
//}


以降は、起動後に繰り返す loop 部分の動きを作っていきます。



まず、Nefryでは @<tt>{Nefry.setLED(R, G, B)} という関数でRGB（赤・青・緑）要素をそれぞれ指定できるので、@<tt>{int red, green, blue;} でそれぞれを入れる値の箱を作ります。


//emlist[][c]{
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


//emlist[][c]{
  // LEDがランダムに点灯します
  Nefry.setLed(red,green,blue);

  // 1秒待つ
  Nefry.ndelay(1000);
}
//}


いよいよ、繰り返し動作する loop の後半です。



先ほどの red  , green , blue を @<tt>{Nefry.setLed(red,green,blue);} という記述で指示するとフルカラーLEDのカラーが変更されます。



最後に @<tt>{Nefry.ndelay(1000);} で1秒プログラムを待つことができるので、繰り返し動作する loop は1秒ごとに動作する仕組みで電源をOFFにするまで動きつづけます。


== 確認


実際に書き込んで確認してみましょう。



//image[03DefaultLed_03][内蔵してあるフルカラーLEDがカラフルに光ります]{
//}




無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるフルカラーLEDがカラフルに光ります。



お疲れ様でした。

