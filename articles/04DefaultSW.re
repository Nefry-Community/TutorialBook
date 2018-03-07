
= Nefryで標準スイッチを使ってみる


このページではNefry BTに標準で取り付けられているスイッチを操作すると前章の内蔵フルカラーLEDのカラーが変化する仕組みを説明します。


== スイッチの位置


今回あつかうスイッチの位置を確認します。



//image[04DefaultSW_01][今回あつかうスイッチの位置]{
//}




このようにUSB接続口に近いところに両サイドにスイッチがあるうちの、@<strong>{SWと刻印されたスイッチ} です。



このSWと刻印されたスイッチの反応をプログラムで分かるようにして、フルカラーLEDのカラーが変化するようにします。


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



//image[04DefaultSW_02][新規ファイルが開かれたウインドウ]{
//}




初期状態で書かれている現状のコードを削除して、次のコードに差し替えましょう。



//image[04DefaultSW_03][次のコードに差し替えたウインドウ]{
//}




このコードは https://github.com/Nefry-Community/TutorialExample/tree/master/examples にある、 04DefaultSW のサンプルからコピーペーストすることが可能です。


//emlist[][c]{
#include <Nefry.h>

void setup() {
  // SW有効化
  Nefry.enableSW();
  // LEDが白に光る（起動時の光り方）
  Nefry.setLed(255, 255, 255);
}

void loop() {
  // SWを押した時を判定する Nefry.readSW
  if (Nefry.readSW()) {
    // LEDが赤に光る
    Nefry.setLed(255, 0, 0);
    // 押されたら1秒待つ
    Nefry.ndelay(1000);
    // 青に戻る
    Nefry.setLed(0, 0, 255);
  }
}
//}

=== コードの説明

//quote{
詳細の説明をするかどうか
コメントで事足りているかも？

//}

//emlist[][c]{
#include <Nefry.h>

void setup() {
  // SW有効化
  Nefry.enableSW();
  // LEDが白に光る（起動時の光り方）
  Nefry.setLed(255, 255, 255);
}
//}


@<tt>{Nefry.enableSW();} によってSW有効化、つまりSWスイッチをつかうよという宣言をします。 @<tt>{Nefry.setLed(255, 255, 255);} 起動したときにフルカラーLEDが白に光ることで、プログラムが動き出したことを示しています。


//emlist[][c]{
void loop() {
  // SWを押した時を判定する Nefry.readSW
  if (Nefry.readSW()) {
    // LEDが赤に光る
    Nefry.setLed(255, 0, 0);
    // 押されたら1秒待つ
    Nefry.ndelay(1000);
    // 青に戻る
    Nefry.setLed(0, 0, 255);
  }
}
//}


つづいて、普段待っているときのループ部分の説明です。SWスイッチを押した時を判定するのは @<tt>{Nefry.readSW()} をif文で判定することで実現しています。



@<strong>{ボタンを押したあとに離したタイミング} で @<tt>{Nefry.readSW()} が1を返すので「ボタンを押した」と判定できます。そのときに、 @<tt>{Nefry.setLed(255, 0, 0);} LEDが赤に光り、 @<tt>{Nefry.ndelay(1000);} で1秒つつづいたあと、 @<tt>{Nefry.setLed(0, 0, 255);} 青に戻ります。



起動時は白く光り、1度でもボタンが押されると赤から青に戻ることで「起動したとき」「一度でもボタンを押されたとき」の状況をわかりやすくしています。


== プログラムの保存とボードに書き込み


//image[04DefaultSW_04][ボードに書き込み]{
//}




左上の  @<tt>{→} ボタンを押してボード（Nefry BT）にプログラムを書き込みます。



//image[04DefaultSW_05][左上の → ボタン]{
//}



== 確認


実際に書き込んで確認してみましょう。



//image[04DefaultSW_06][起動したときの動き]{
//}




無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるフルカラーLEDが起動時は白く光ります。



//image[04DefaultSW_07][スイッチを押してすぐ離したときの動き]{
//}




スイッチを押してすぐ離したときは赤に光ります。その後、待っていると青の点灯に戻ります。



お疲れ様でした。

