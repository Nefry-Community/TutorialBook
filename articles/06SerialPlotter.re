= シリアルモニタ・シリアルプロッタを使って Nefry BT の動作を見てみよう


この章ではArduino IDE のシリアルモニタ・シリアルプロッタという機能を使って、Nefry BT の中で起こっていることを表示する仕組みを説明します。


== シリアルモニタ・シリアルプロッタとは


シリアルモニタ・シリアルプロッタのシリアルというのはシリアル通信のことです。シリアル通信は Nefry BTとコンピュータと通信するために使われる通信方法です。文字列や数字などさまざまなデータを送ることが可能です。



//image[06SerialPlotter_01][シリアル通信の流れ][scale=0.8]{
//}




たとえば、 このようにNefry BTからコンピュータに数字の10をシリアル通信で送る場合、 @<code>{Serial.println(10);} を書きます。
これを受け取ったコンピュータ側は、USB経由のシリアル通信を行い、数字の10を受け取ります。



前半の @<code>{Serial} の部分はシリアル通信をするクラス（この場合、シリアル通信するプログラムが集まったもの）で、そこから、改行付きでデータを送るのが @<code>{println} です。
今回は10という数字を送るので @<code>{println(10)} となります。



//image[06SerialPlotter_02][シリアルモニタの例][scale=0.8]{
//}




シリアルモニタは、シリアル通信のデータをポート単位で待ち構えて、データが来るとデータの内容をテキストで表示します。とりあえず、Nefry BTで自分のプラグラムの何かしら挙動をつかみたい時は、とりあえずシリアル通信で該当のデータを出力しておくと、データの流れが把握しやすいでしょう。



//image[06SerialPlotter_03][シリアルプロッタの例][scale=0.8]{
//}




シリアルプロッタは、シリアル通信のデータをポート単位で待ち構えて、できる限り数字に置き換えて折れ線グラフで表示します。シリアルモニタと比べてデータの変化を把握しやすいツールです。


== Nefry BT の準備


Nefry BT の準備です。
USBを差し込み、@<href>{02ArduinoSetting,Arduino設定} を参考にして差し込まれたポートをチェックして、シリアルモニタ・シリアルプロッタがNefry BTからくるデータを待ち構えられるようにしておきましょう。



//image[06SerialPlotter_04][差し込まれたポートをチェック][scale=0.6]{
//}



== プログラムの書き込み


今回のプログラムの書き込みます。



//image[06SerialPlotter_05][今回のプログラム][scale=0.6]{
//}




このコードは、Arduino IDE のメニューからファイル ＞ スケッチ例 に移動し Nefry TutorialBook Example ＞ SerialPlotter で呼び出すことができます。


== コードの説明

//emlist{
#include <Nefry.h>

void setup() {
  // SW有効化
  Nefry.enableSW();
  // LEDが白に光る（起動時の光り方）
  Nefry.setLed(255, 255, 255);
}
//}


@<code>{#include <Nefry.h>} は、いままでのとおり、Nefryライブラリの準備です。SW有効化、起動時に白く光るように設定しています。


//emlist{
void loop() {
  // SWを押した時を判定する Nefry.readSW
  if (Nefry.readSW()) {
    // LEDが赤に光る
    Nefry.setLed(255, 0, 0);
    // ボタンを押した時は1という値を知らせる
    Serial.println(10);
    // 押されたら1秒待つ
    Nefry.ndelay(1000);
    // 青に戻る
    Nefry.setLed(0, 0, 255);
    // ボタンを離したら0という値を知らせる
    // Serial.println(0);
  }
//}


繰り返し動作するloop部分では、 @<href>{04DefaultLed,デフォルトのフルカラーLED} の処理に加えて、今回はSWを押した時に @<code>{Serial.println(10);} PCに対してシリアル通信で10という数字を送っています。


//emlist{
  // 通常時は0を知らせ続ける
  Serial.println(0);
}
//}


また、SWを押していないときは、0を送り続けています。



これを書き込んでNefryの動作は準備完了です。


== シリアルモニタ


まず、シリアルモニタを動かしてみましょう



//image[06SerialPlotter_06][ツールからシリアルモニタを選択する][scale=0.4]{
//}




メニュー から @<tt>{ツール} > @<tt>{シリアルモニタ} をクリックします。



//image[06SerialPlotter_07][なにも動かしていないときのシリアルモニタ][scale=0.8]{
//}




シリアルモニタが表示されます。なにも動かしていないときは0が送られ続けています。



//image[06SerialPlotter_08][ボタンを押したときのシリアルモニタ][scale=0.8]{
//}




ボタンを押してみると 10 の値が流れてきます。


== シリアルプロッタ


続いて、シリアルプロッタを動かしてみましょう



//image[06SerialPlotter_09][ツールからシリアルプロッタを選択する][scale=0.4]{
//}




メニュー から @<tt>{ツール} > @<tt>{シリアルプロッタ} をクリックします。



//image[06SerialPlotter_10][ボタンを押したときのシリアルプロッタ][scale=0.8]{
//}




ボタンを押してみると 10 の値が流れてきてグラフが反応します。



== 試してみよう

この章でシリアルモニタ・シリアルプロッタの使い方を確認できました。

次のステップとして問題を2つほど出すのでぜひ試してみてください。

 * Q1
  ** ランダム関数を使って押したときの値をランダムにしてシリアルプロッタのグラフの動きを確認
 * Q2
 ** 押している時は0で押していない時は10と値を反転させるよう変更してシリアルプロッタのグラフの動きを確認

解答例は、Nefry TutorialBook Example ＞ SerialPlotter Answer ＞ SerialPlotter_Q1・Q2 をご覧ください。

