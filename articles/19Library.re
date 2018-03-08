

このページではNefry BTの便利なライブラリをご紹介します。


== Ambientライブラリ（NefryAmbient.h）


Ambient（https://ambidata.io/）はマイコンボードからのデータを簡単に可視化できるサービスです。



//image[ambient_top][Ambientホームページ]{
//}




Ambientライブラリは、@<tt>{NefryAmbient.h}をincludeすることで使えるようになります。


//emlist{
#include <NefryAmbient.h> // Ambientライブラリを使うのに必要！

#define CHANNEL_ID xxxx // データを送りたいAmbientのチャネルのID（数値）
#define WRITE_KEY "yyyy" // そのチャネルのリードキー（文字列）
NefryAmbient nefryAmbient;

void setup() {
  nefryAmbient.begin(CHANNEL_ID, WRITE_KEY); //Ambientを使えるように初期設定をします。
}

void loop() {
  int analog;
  analog = analogRead(A0);//A0ピンの状態を取得します。
  Nefry.print("Analog:"); Nefry.println(analog); //アナログの値を表示します。
  nefryAmbient.set(1, analog); //field,dataの順にセットします。
  nefryAmbient.send();//Ambientにデータを送信します。
  Nefry.ndelay(1000);//1秒待つ
}
//}


@<tt>{begin()}関数で、データを送信したいチャネルのIDとライトキーを設定し、その後@<tt>{set()}でデータを詰めて@<tt>{send()}を呼ぶだけでデータをAmbientにアップデートできます。上記の例では、A0ピンのアナログ入力値を読み取り、Ambientに送信しています。


== AzureIoTHubライブラリ（Nefry_AzureIoTHub）

== ティスプレイ（Nefry_Display）

== Fast Sensingライブラリ（Nefry_FastSensing）

== Firebaseライブラリ（Nefry_FireBase）

== Firmataライブラリ（Nefry_Firmata）
