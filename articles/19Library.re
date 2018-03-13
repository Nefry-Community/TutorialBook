

このページではNefry BTの便利なライブラリの一部をご紹介します。


== Ambientライブラリ（NefryAmbient.h）


Ambient（https://ambidata.io/）は、主にマイコンボードなどからのデータを無料で簡単に可視化できるサービスです。



//image[ambient_top][Ambientのホームページ]{
//}




Ambientライブラリは、@<tt>{NefryAmbient.h}をincludeすることで使えるようになります。


//emlist{
#include <NefryAmbient.h> // Ambientライブラリを使うのに必要

#define CHANNEL_ID xxxx // データを送りたいAmbientのチャネルのID（数値）
#define WRITE_KEY "yyyy" // そのチャネルのリードキー（文字列）
NefryAmbient nefryAmbient;

void setup() {
  nefryAmbient.begin(CHANNEL_ID, WRITE_KEY); //Ambientを使えるように初期設定をする
}

void loop() {
  int analog;
  analog = analogRead(A0);//A0ピンの状態を取得します。
  Nefry.print("Analog:"); Nefry.println(analog); //アナログの値を表示する
  nefryAmbient.set(1, analog); //field,dataの順にセットします。
  nefryAmbient.send();//Ambientにデータを送信します。
  Nefry.ndelay(1000);//1秒待つ
}
//}


@<tt>{begin()}関数で、データを送信したいチャネルのIDとライトキーを設定し、その後@<tt>{set()}でデータを詰めて@<tt>{send()}を呼ぶだけでデータをAmbientにアップデートできます。上記の例では、A0ピンのアナログ入力値を読み取り、Ambientに送信しています。



//image[ambient_detail][Myチャネル]{
//}




上記の関数で必要になる、チャネルIDとライトキーは「Myチャネル」から確認できます。


== Microsoft Azure IoT Hubライブラリ（Nefry_AzureIoTHub）


IoT Hub（https://azure.microsoft.com/ja-jp/services/iot-hub/）とは、Microsoft Azureで提供されているIoT向けのバックエンドサービスのことです。



//image[azureiothub_top][Microsoft Azure IoT Hubホームページ]{
//}




Nefry BTでは、@<tt>{NefryAzureIoTHub.h}をincludeすることで、データをIoT Hubにアップロードできます。


//emlist{
#include <NefryAzureIoTHub.h> // Microsoft Azure IoT Hubライブラリを使うのに必要
#include <Nefry.h>

#define CONNECTION_STRING "HostName=pokiiio.azure-devices.net;DeviceId=pokiiio-nefry;SharedAccessKey=xxxxxx" // 接続文字列

void setup() {
  while(!Azure.begin(CONNECTION_STRING)){ // 接続文字列を使ってIoT Hubとの接続を初期化する
    Nefry.println("Azure begin Fault");
    delay(1000);
  }
  Azure.setCallback(azureCallback); // IoT Hubからのメッセージを受信する関数を指定する
}

void azureCallback(String s) {
  Nefry.print("Azure Message arrived [");
  Nefry.print(s);
  Nefry.println("] ");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Azure.connect(); // IoT Hubに接続する
    DataElement a = DataElement();
    a.setValue("EspAnalog", analogRead(A0)); // A0ピンのアナログ値を読み取る
    Azure.push(&a); // そのデータをIoT Hubに送信する
    Nefry.println("pushed");
    delay(2000);
  } else {
    Nefry.println("Not connected to the Internet");
    delay(250);
  }
}
//}


接続文字列というIoT Hub用のアクセスキーでNefry BTは通信を行うため、@<tt>{setup()}内で初期化を行っています。データをIoT Hubに送信するときは、都度@<tt>{Azure.connect()}で接続してから、@<tt>{DataElement}インスタンスに送信したい値を詰めて、@<tt>{Azure.push()}で送信します。



//image[azureiothub_detail][デバイスエクスプローラー]{
//}




接続文字列は、IoT Hub内のデバイスエクスプローラーを開き、登録したデバイスを選択すると上のような画面が表示され確認することができます。登録したデバイスごとに接続文字列が異なるので注意が必要です。


== Fastsensingライブラリ（Nefry_FastSensing）


Fastsensing（https://fastsensing.com/ja/）は、専用のデバイスやマイコンボードからのセンサーデータを受信し、グラフ化や異常検知をしてくれるサービスです。



//image[fastsensing_top][Fastsensingのホームページ]{
//}




通常は専用のデバイスからセンサーデータをアップロードするのですが、ファストセンシング・ディベロッパー・プログラム（https://fastsensing.com/ja/developer/）をつかって、さまざまなマイコンボードからデータをアップロードすることができます。



//image[fastsensing_developer_program][ファストセンシング・ディベロッパー・プログラム]{
//}




ファストセンシング・ディベロッパー・プログラムのページ上の@<tt>{スタブデバイスの追加}のリンクから、Fastsensingのコンソールに遷移でき、仮想のデバイスを登録することができます。



//image[fastsensing_add_stub_device][スタブデバイスの追加]{
//}




ここから@<tt>{スタブデバイス}を追加すると、1つのデバイスに対して3つの独立したチャネルが割り当てられて、それぞれのチャネルに対してセンサーデータをアップロードすることができます。



//image[fastsensing_detail][スタブデバイスの詳細]{
//}




コンソール（https://console.fastsensing.com/devices）に登録した@<tt>{スタブデバイス}が表示されいるので、それを選択するとデバイスの詳細画面が表示されます。そこで、デバイスと各チャネルのトークンが表示されます。Nefry BTのFastsensingライブラリでは、これらのトークンをつかってセンサーデータをアップロードします。


//emlist{
#include <NefryFastSensing.h> // FastSensingライブラリを使うのに必要
#define DEVICE_TOKEN xxxx // デバイスのトークン
#define CHANNEL1_TOKEN xxxx // チャネル1のトークン
#define CHANNEL2_TOKEN xxxx // チャネル2のトークン
#define CHANNEL3_TOKEN xxxx // チャネル3のトークン


NefryFastSensing fastSensing; // Fastsensingと通信するために必要なインスタンス
float floatData = 0;
float intData = 0;

void setup() {
  fastSensing.begin(DEVICE_TOKEN, CHANNEL1_TOKEN, CHANNEL2_TOKEN, CHANNEL3_TOKEN);
}

void loop() {
  fastSensing.setValue(0, floatData); // Fastsensingに送るデータをセットします
  fastSensing.setValue(1, intData); // 一つ目の引数はチャネル（0〜2）を指定しています

  fastSensing.push(); // セットしたデータをFastsensingに送信します

  floatData += 0.1;
  intData++;
  delay(10000);
}
//}

== ThingSpeakライブラリ（Nefry_ThingSpeak）


ThingSpeak（https://thingspeak.com/）は、マイコンなどからのセンサーデータを収取し、グラフ化やMATLABを使って分析を行えるだけでなく、Twitterなどの別のサービスへのアクションを行えるサービスです。



//image[thingspeak_top][ThingSpeakのホームページ]{
//}




ThingSpeakにセンサーデータをアップロードするには、まずチャネルを作成する必要があります。



//image[thingspeak_channel_detail][ThingSpeakのチャネル設定]{
//}




チャネルを作るとフィールドの設定ができ、1つのチャネルにつき最大8つのフィールドを持つことができ、それぞれのフィールドに別々のデータをアップロードすることができます。



//image[thingspeak_detail][ThingSpeakのAPIキー]{
//}




Nefry BTからThingSpeakにデータをアップロードする際は、チャネルのIDとライトAPIキーが必要となります。同じチャネルのフィールドであれば、同じライトキーを使うことになります。


//emlist{
#include <NefryThingSpeak.h>

void setup() {
  //ThingSpeakの初期設定を行います。WriteKeyも設定します
  NefryThingSpeak.begin();
  NefryThingSpeak.setWriteAPIKey(1);
}

void loop() {
  // ThingSpeakにデータを送信します。
  // ThingSpeak.writeField( Field番号,データ);
  NefryThingSpeak.writeField(1, random(1000));//データを送信します
  delay(20000); // ThingSpeakには15秒間隔でデータを送信すること
}
//}


TODO:最新のコードを使う


== Firebaseライブラリ（Nefry_FireBase）


Firebase（https://firebase.google.com/?hl=ja）は、モバイルとウェブアプリケーションの開発プラットフォームです。その中でもNefry BTのFirebaseライブラリでは、リアルタイムデータベースへの読み書きを可能にします。



//image[firebase_top][Firebaseのホームページ]{
//}




Firebaseのページ上でリアルタイムデータベースを作成すると、ホスト名が割り振られます。Firebaseライブラリではこのホストにアクセスします。



//image[firebase_database_host][Firebaseのデータベースのホスト名]{
//}




リアルタイムデータベースへアクセスするのに必要なシークレットは、プロジェクトの設定＞サービスアカウント＞データベースのシークレットで確認ができます。



//image[firebase_database_secret][Firebaseのデータベースのシークレット]{
//}




これらの情報を使って、Nefry BTからFirebaseへアクセスします。A0ピンのアナログ値をリアルタイムデータベースにアップロードするプログラムの例は以下のとおりです。


//emlist{
#include<NefryFireBase.h> // Firebaseライブラリを使うのに必要
#define HOST xxxxx // Firebaseで作成したデータベースのホスト名
#define SECRET xxxxx // データベースへアクセスするためのシークレット

NefryFireBase firebase; // Firebaseと通信するために必要なインスタンス

void setup() {
  firebase.begin(HOST, SECRET); // Firebaseとの接続を初期化
}

void loop() {
  DataElement elem = DataElement();
  elem.setValue("A0", analogRead(A0)); // "A0"というキーで、A0ピンのアナログ値をセット
  firebase.write("Nefry", &elem); // セットした値を"Nefry"というグループに追加
  delay(1000);
}
//}


このコードを実行すると、リアルタイムデータベース上には以下のような情報が保存されます。



//image[firebase_database_result][Firebaseのデータベースにデータを送信した例]{
//}



== ティスプレイ（Nefry_Display）

== Firmataライブラリ（Nefry_Firmata）
