
= Nefryで標準スイッチを使ってみる


この章では、Nefry BTに標準で取り付けられているスイッチの扱い方を紹介します。今回はスイッチを押したら前章の内蔵フルカラーLEDのカラーが変化する仕組みを試してみます。


== スイッチの位置


今回扱うスイッチの位置を確認します。



//image[04DefaultSW_01][今回あつかうスイッチの位置]{
//}




このようにUSB接続口に近いところに両サイドにスイッチがあるうちの、@<strong>{「SW」と刻印された方がスイッチ} です。「Reset」とある方はNefryを再起動するスイッチです。



このSWと刻印されたスイッチ（以下「SWスイッチ」）の反応をプログラムで分かるようにして、スイッチを押すとフルカラーLEDのカラーが変化するようにします。


== プログラムの書き込み


//image[04DefaultSW_02][次のコードに差し替えたウインドウ]{
//}




このコードは https://github.com/Nefry-Community/TutorialExample/tree/master/examples にある、 04DefaultSW のサンプルからコピー＆ペーストすることが可能です。


=== コードの説明

//emlist[][c]{
#include <Nefry.h>

void setup() {
  // SW有効化
  Nefry.enableSW();
  // LEDが白に光る（起動時の光り方）
  Nefry.setLed(255, 255, 255);
}
//}


@<tt>{Nefry.enableSW();} によってSW有効化、つまりSWスイッチを使うよという宣言をします。 起動したときにプログラムが動き出したことを示すため、@<tt>{Nefry.setLED(255, 255, 255)} でフルカラーLEDを白に光らせます。（R・G・Bが全て255だと白になります。）


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


続いて、普段待っているときのループ部分の説明です。@<tt>{Nefry.readSW()} でSWスイッチの状態を取得することができます。



@<strong>{ボタンを押したあとに離したタイミング} で @<tt>{Nefry.readSW()} が1を返すので「ボタンを押した」と判定できます。if @<tt>{(Nefry.readSW() == 1)}となりますが、プログラム内では1になること（true, falseのうちtrueなこと）を省略できるので if @<tt>{(Nefry.readSW())} で判定することができます。



そのときに、 @<tt>{Nefry.setLed(255, 0, 0);} LEDが赤に光らせ、 @<tt>{Nefry.ndelay(1000);} で1秒続いたあと、 @<tt>{Nefry.setLed(0, 0, 255);} 青に戻します。


== 確認


実際に書き込んで確認してみましょう。



//image[04DefaultSW_03][起動したときの動き]{
//}




無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるフルカラーLEDが起動時は白く光ります。



//image[04DefaultSW_04][スイッチを押してすぐ離したときの動き]{
//}




スイッチを押してすぐ離したときは赤に光ります。その後、待っていると青の点灯に戻ります。



お疲れ様でした。

