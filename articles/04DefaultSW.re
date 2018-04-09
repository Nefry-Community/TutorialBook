
= Nefryで標準スイッチを使ってみる


この章では、Nefry BTに標準で取り付けられているスイッチの扱い方を紹介します。今回はスイッチを押したら前章の内蔵フルカラーLEDのカラーが変化する仕組みを試してみます。


== スイッチの位置


今回扱うスイッチの位置を確認します。



//image[04DefaultSW_01][今回あつかうスイッチの位置][scale=0.8]{
//}




このようにUSB接続口に近いところに両サイドにスイッチがあるうちの、@<strong>{「SW」と刻印された方がスイッチ} です。「Reset」とある方はNefryを再起動するスイッチです。



このSWと刻印されたスイッチ（以下「SWスイッチ」）の反応をプログラムで分かるようにして、スイッチを押すとフルカラーLEDのカラーが変化するようにします。


== プログラムの書き込み


//image[04DefaultSW_02][次のコードに差し替えたウインドウ][scale=0.6]{
//}




このコードは、Arduino IDE のメニューからファイル ＞ スケッチ例 に移動し Nefry TutorialBook Example ＞ DefaultSW で呼び出すことができます。


=== コードの説明

//emlist{
#include <Nefry.h>

void setup() {
  // SW有効化
  Nefry.enableSW();
  // LEDが白に光る（起動時の光り方）
  Nefry.setLed(255, 255, 255);
}
//}


@<code>{Nefry.enableSW();} によってSW有効化、つまりSWスイッチを使うよという宣言をします。
起動したときにプログラムが動き出したことを示すため、@<code>{Nefry.setLED(255, 255, 255)} でフルカラーLEDを白に光らせます。（R・G・Bが全て255だと白になります。）


//emlist{
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


続いて、普段待っているときのループ部分の説明です。
@<code>{Nefry.readSW()} でSWスイッチの状態を取得することができます。



@<strong>{ボタンを押したあとに離したタイミング} で @<code>{Nefry.readSW()} が1を返すので「ボタンを押した」と判定できます。
 @<code>{if(Nefry.readSW() == 1)}となりますが、プログラム内では1になること（true, falseのうちtrueなこと）を省略できるので @<code>{if(Nefry.readSW())} で判定することができます。



そのときに、 @<code>{Nefry.setLed(255, 0, 0);} LEDが赤に光らせ、 @<code>{Nefry.ndelay(1000);} で1秒続いたあと、 @<code>{Nefry.setLed(0, 0, 255);} 青に戻します。


== 確認


実際に書き込んで確認してみましょう。



//image[04DefaultSW_03][起動したときの動き][scale=0.8]{
//}




無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるフルカラーLEDが起動時は白く光ります。



//image[04DefaultSW_04][スイッチを押してすぐ離したときの動き][scale=0.8]{
//}




スイッチを押してすぐ離したときは赤に光ります。その後、待っていると青の点灯に戻ります。



== 試してみよう

この章で標準スイッチを操作することができました。

次のステップとして問題を2つほど出すのでぜひ試してみてください。

 * Q1
 ** 標準スイッチの押す回数によって光る回数が増えていく
 * Q2
 ** 一度標準スイッチを押したら内蔵LEDが点灯し、もう一度押すと消える仕組みにする

解答例は、Nefry TutorialBook Example ＞ DefaultSW Answer ＞ DefaultSW_Q1・Q2をご覧ください。
