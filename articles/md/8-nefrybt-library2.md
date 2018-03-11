このページではNefry BTの便利なライブラリをご紹介します。

## Ambientライブラリ（NefryAmbient.h）
Ambient（https://ambidata.io/）は、主にマイコンボードなどからのデータを無料で簡単に可視化できるサービスです。


![Ambientホームページ](ambient_top)


Ambientライブラリは、`NefryAmbient.h`をincludeすることで使えるようになります。


```
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
```


`begin()`関数で、データを送信したいチャネルのIDとライトキーを設定し、その後`set()`でデータを詰めて`send()`を呼ぶだけでデータをAmbientにアップデートできます。上記の例では、A0ピンのアナログ入力値を読み取り、Ambientに送信しています。


![Myチャネル](ambient_detail)


上記の関数で必要になる、チャネルIDとライトキーは「Myチャネル」から確認できます。


## Microsoft Azure IoT Hubライブラリ（Nefry_AzureIoTHub）
IoT Hub（https://azure.microsoft.com/ja-jp/services/iot-hub/）とは、Microsoft Azureで提供されているIoT向けのバックエンドサービスのことです。


![Microsoft Azure IoT Hubホームページ](azureiothub_top)


Nefry BTでは、`NefryAzureIoTHub.h`をincludeすることで、データをIoT Hubにアップロードできます。


```
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
```


接続文字列というIoT Hub用のアクセスキーでNefry BTは通信を行うため、`setup()`内で初期化を行っています。データをIoT Hubに送信するときは、都度`Azure.connect()`で接続してから、`DataElement`インスタンスに送信したい値を詰めて、`Azure.push()`で送信します。


![デバイスエクスプローラー](azureiothub_detail)


接続文字列は、IoT Hub内のデバイスエクスプローラーを開き、登録したデバイスを選択すると上のような画面が表示され確認することができます。登録したデバイスごとに接続文字列が異なるので注意が必要です。


## ティスプレイ（Nefry_Display）

## Fast Sensingライブラリ（Nefry_FastSensing）

## Firebaseライブラリ（Nefry_FireBase）

## Firmataライブラリ（Nefry_Firmata）
