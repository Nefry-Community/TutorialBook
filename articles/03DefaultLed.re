
= Nefryで内蔵フルカラーLEDを使ってみる

//quote{
コードの書き方を伝える章

//}


このページでは内蔵フルカラーLEDを操作する方法を仕組みを説明します。



Nefry BTをArduino IDEで開発するにあたり、前の章を見てセットアップを済ませておいてください。


== 内蔵フルカラーLEDの位置


//image[03DefaultLed_01][2018-03-07_21h57_37.jpg (124.1 kB)]{
//}




内蔵フルカラーLEDの位置


== Nefry BTをPCのUSBポートにさしてください。
 * Nefry BTをPCのUSBポートにさしてください。
 * シリアルポートの選択をします。
 ** Macの場合
 *** メニューの @<tt>{ツール} > @<tt>{シリアルポート} > @<tt>{/dev/cu.usbserial-xxxxxx} を選択します。環境によっては @<tt>{/dev/tty.usbserial-xxxxxx} などの場合もあります。
 ** Windowsの場合
 *** メニューの @<tt>{ツール} > @<tt>{シリアルポート} > @<tt>{COMxx} （xxの部分はNefryBTが挿してあるCOMポート） を選択します。


== プログラムの書き込み


メニューの @<tt>{ファイル} > @<tt>{新規ファイル} を選択します。



次のようなウインドウが表示されます。



//image[03DefaultLed_02][新規ファイルが開かれたウインドウ]{
//}




初期状態で書かれている現状のコードを削除して、次のコードに差し替えましょう。



//image[03DefaultLed_03][次のコードに差し替えたウインドウ]{
//}



//emlist[][c]{
#include <Nefry.h>

void setup() {

}

// フルカラーLEDの色要素（赤 red,緑 green,青 blue）をいれる値の箱（変数）をつくる
int red,green,blue;

void loop() {
  // random関数は0-255の数値をランダムに返します

  // フルカラーLEDの赤要素をランダムに指定
  red = random(255);
  // フルカラーLEDの緑要素をランダムに指定
  green = random(255);
  // フルカラーLEDの青要素をランダムに指定
  blue = random(255);

  // LEDがランダムに点灯します
  Nefry.setLed(red,green,blue);

  // 1秒待つ
  Nefry.ndelay(1000);
}
//}


このコードは https://github.com/Nefry-Community/TutorialExample/tree/master/examples にある、 03DefaultLed のサンプルからコピーペーストすることが可能です。


=== コードの説明


コードの説明をします。


//emlist[][c]{
#include <Nefry.h>
//}


まず、 @<tt>{#include <Nefry.h>} によってNefry BTの今回のフルカラーLEDの制御も含めていろいろな機能を使えるようになります。


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



まず、 @<tt>{int red,green,blue;} とすることで、フルカラーLEDの色要素（赤 red,緑 green,青 blue）をいれる値の箱（変数）をつくります。


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



このあと、フルカラーLEDの色を実際に指定するために、先ほど作った値の箱（変数）を使ってフルカラーLEDの赤要素なら
 red という名前の値の箱（変数）に入れていきます。変数 green ならフルカラーLEDの緑要素を、変数 blue ならフルカラーLEDの青要素を入れています。


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


== プログラムの保存とボードに書き込み


//image[03DefaultLed_04][ボードに書き込み]{
//}




左上の  @<tt>{→} ボタンを押してボード（Nefry BT）にプログラムを書き込みます。



//image[03DefaultLed_05][左上の → ボタン]{
//}



== 確認


実際に書き込んで確認してみましょう。



//image[03DefaultLed_06][image.png (51.7 kB)]{
//}




無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるフルカラーLEDがカラフルに光ります。



お疲れ様でした。

