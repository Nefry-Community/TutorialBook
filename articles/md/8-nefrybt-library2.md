# Nefryライブラリ紹介

この章ではNefry BTの便利なライブラリの一部をご紹介します。

## Ambientライブラリ（NefryAmbient.h）
Ambient（https://ambidata.io/）は、主にマイコンボードなどからのデータを無料で簡単に可視化できるサービスです。


![Ambientのホームページ](ambient_top)


Ambientライブラリは、`NefryAmbient.h`をincludeすることで使えるようになります。


```
// Ambientライブラリを使うのに必要
#include <NefryAmbient.h>

// データを送りたいAmbientのチャネルのID（数値）とライトキー
#define CHANNEL_ID xxxxx
#define WRITE_KEY "xxxxx"

// Ambientと通信するために必要なインスタンス
NefryAmbient nefryAmbient;

void setup() {
  //Ambientを使えるように初期設定をする
  nefryAmbient.begin(CHANNEL_ID, WRITE_KEY);
  Nefry.println("Ambient initialized");
}

void loop() {
  // A0ピンの値をセットします。第一引数はセットしたいフィールド（1〜8）です。
  nefryAmbient.set(1, analogRead(A0));

  //Ambientにデータを送信します。
  nefryAmbient.send();
  Nefry.println("Data pushed");

  Nefry.ndelay(1000);//1秒待つ
}
```


`begin()`関数で、データを送信したいチャネルのIDとライトキーを設定し、その後`set()`でデータを詰めて`send()`を呼ぶだけでデータをAmbientにアップデートできます。上記の例では、A0ピンのアナログ入力値を読み取り、Ambientに送信しています。


![Myチャネル](ambient_detail)


上記の関数で必要になる、チャネルIDとライトキーは「Myチャネル」から確認できます。


## Microsoft Azure IoT Hubライブラリ（NefryAzureIoTHub.h）
IoT Hub（https://azure.microsoft.com/ja-jp/services/iot-hub/）とは、Microsoft Azureで提供されているIoT向けのバックエンドサービスのことです。


![Microsoft Azure IoT Hubホームページ](azureiothub_top)


Nefry BTでは、`NefryAzureIoTHub.h`をincludeすることで、データをIoT Hubにアップロードできます。A0ピンのアナログ入力値を読み取りIoT Hubにアップロードするにはこのようにコーディングします。


```
// Microsoft Azure IoT Hubライブラリを使うのに必要
#include <NefryAzureIoTHub.h>

// 接続文字列
#define CONNECTION_STRING "xxxxx"

void setup() {
  // 接続文字列を使ってIoT Hubとの接続を初期化する
  while (!Azure.begin(CONNECTION_STRING)) {
    Nefry.println("Azure begin Failed");
    delay(1000);
  }
  Nefry.println("Azure initialized");

  // IoT Hubからのメッセージを受信する関数を指定する
  Azure.setCallback(azureCallback);
}

void azureCallback(String s) {
  Nefry.print("Azure Message arrived [");
  Nefry.print(s);
  Nefry.println("] ");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // IoT Hubに接続する
    Azure.connect();

    // A0ピンのアナログ値を読み取ってDataElementインスタンスに格納する
    DataElement dataElement = DataElement();
    dataElement.setValue("Nefry", analogRead(A0));

    // そのデータをIoT Hubに送信する
    Azure.push(&dataElement);
    Nefry.println("Data pushed");
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



## Fastsensingライブラリ（NefryFastSensing.h）
Fastsensing（https://fastsensing.com/ja/）は、専用のデバイスやマイコンボードからのセンサーデータを受信し、グラフ化や異常検知をしてくれるサービスです。


![Fastsensingのホームページ](fastsensing_top)


通常は専用のデバイスからセンサーデータをアップロードするのですが、ファストセンシング・ディベロッパー・プログラム（https://fastsensing.com/ja/developer/）をつかって、さまざまなマイコンボードからデータをアップロードすることができます。


![ファストセンシング・ディベロッパー・プログラム](fastsensing_developer_program)


ファストセンシング・ディベロッパー・プログラムのページ上の`スタブデバイスの追加`のリンクから、Fastsensingのコンソールに遷移でき、仮想のデバイスを登録することができます。


![スタブデバイスの追加](fastsensing_add_stub_device)


ここから`スタブデバイス`を追加すると、1つのデバイスに対して3つの独立したチャネルが割り当てられて、それぞれのチャネルに対してセンサーデータをアップロードすることができます。


![スタブデバイスの詳細](fastsensing_detail)


コンソール（https://console.fastsensing.com/devices）に登録した`スタブデバイス`が表示されいるので、それを選択するとデバイスの詳細画面が表示されます。そこで、デバイスと各チャネルのトークンが表示されます。Nefry BTのFastsensingライブラリでは、これらのトークンをつかってセンサーデータをアップロードします。


A0ピンのアナログ入力値を読み取りアップロードしてみましょう。


```
// FastSensingライブラリを使うのに必要
#include <NefryFastSensing.h>

// デバイスのトークンとチャネル1〜3のトークン
#define DEVICE_TOKEN "xxxxx"
#define CHANNEL1_TOKEN "xxxxx"
#define CHANNEL2_TOKEN "xxxxx"
#define CHANNEL3_TOKEN "xxxxx"

// Fastsensingと通信するために必要なインスタンス
NefryFastSensing fastSensing;

void setup() {
  // トークンを使って初期化
  fastSensing.begin(DEVICE_TOKEN, CHANNEL1_TOKEN, CHANNEL2_TOKEN, CHANNEL3_TOKEN);
  Nefry.println("FastSensing initialized");
}

void loop() {
  // A0ピンの値をセットします。一つ目の引数はチャネル（0〜2）を指定しています。
  fastSensing.setValue(0, analogRead(A0));

  // セットしたデータをFastsensingに送信します
  fastSensing.push();
  Nefry.println("Data pushed");

  delay(10000);
}
```




## ThingSpeakライブラリ（NefryThingSpeak.h）
ThingSpeak（https://thingspeak.com/）は、マイコンなどからのセンサーデータを収取し、グラフ化やMATLABを使って分析を行えるだけでなく、Twitterなどの別のサービスへのアクションを行えるサービスです。


![ThingSpeakのホームページ](thingspeak_top)


ThingSpeakにセンサーデータをアップロードするには、まずチャネルを作成する必要があります。


![ThingSpeakのチャネル設定](thingspeak_channel_detail)


チャネルを作るとフィールドの設定ができ、1つのチャネルにつき最大8つのフィールドを持つことができ、それぞれのフィールドに別々のデータをアップロードすることができます。


![ThingSpeakのAPIキー](thingspeak_detail)


Nefry BTからThingSpeakにデータをアップロードする際は、チャネルのIDとライトAPIキーが必要となります。同じチャネルのフィールドであれば、同じライトキーを使うことになります。


```
// ThingSpeakライブラリを使うのに必要
#include <NefryThingSpeak.h>

// ThingSpeakで作成したチャネルのID（数値）とライトキー
#define CHANNEL_ID 447668
#define WRITE_KEY "1AQGOCTGWAJGVFQN"

void setup() {
  //ThingSpeakの初期設定を行います。WriteKeyも設定します
  NefryThingSpeak.begin(CHANNEL_ID);
  NefryThingSpeak.setWriteAPIKey(WRITE_KEY);
  Nefry.println("ThingSpeak initialized");
}

void loop() {
  // A0ピンのアナログ値を読み取って、ThingSpeakに送信
  // 第一引数はセットしたいフィールド（1〜8）です。
  NefryThingSpeak.writeField(1, analogRead(A0));
  Nefry.println("Data pushed");

  delay(20000);
}
```


## Firebaseライブラリ（NefryFireBase.h）
Firebase（https://firebase.google.com/?hl=ja）は、モバイルとウェブアプリケーションの開発プラットフォームです。その中でもNefry BTのFirebaseライブラリでは、リアルタイムデータベースへの読み書きを可能にします。


![Firebaseのホームページ](firebase_top)


Firebaseのページ上でリアルタイムデータベースを作成すると、ホスト名が割り振られます。Firebaseライブラリではこのホストにアクセスします。


![Firebaseのデータベースのホスト名](firebase_database_host)


リアルタイムデータベースへアクセスするのに必要なシークレットは、プロジェクトの設定＞サービスアカウント＞データベースのシークレットで確認ができます。


![Firebaseのデータベースのシークレット](firebase_database_secret)


これらの情報を使って、Nefry BTからFirebaseへアクセスします。A0ピンのアナログ値をリアルタイムデータベースにアップロードするプログラムの例は以下のとおりです。



```
// Firebaseライブラリを使うのに必要
#include<NefryFireBase.h>

// Firebaseで作成したデータベースのホスト名とアクセスするためのシークレット
#define HOST "xxxxx"
#define SECRET "xxxxx"

// Firebaseと通信するために必要なインスタンス
NefryFireBase firebase;

void setup() {
  // Firebaseとの接続を初期化
  firebase.begin(HOST, SECRET);
  Nefry.println("Firebase initialized");
}

void loop() {
  // A0ピンのアナログ値を読み取って、DataElementインスタンスに"A0"というキーで格納する
  DataElement dataElement = DataElement();
  dataElement.setValue("A0", analogRead(A0));

  // セットした値を"Nefry"というグループに追加
  firebase.write("Nefry", &dataElement);
  Nefry.println("Data pushed");

  delay(1000);
}
```


このコードを実行すると、リアルタイムデータベース上には以下のような情報が保存されます。


![Firebaseのデータベースにデータを送信した例](firebase_database_result)



## ティスプレイ（Nefry_Display）
Nefry BTのディスプレイの表示も`NefryDisplay.h`をincludeすることでプログラム可能になります。



### 簡単な使い方


たとえば、このように`NefryDisplay#print()`を使うと、簡単にディスプレイに好きな文字列を表示することができます。


```
#include <NefryDisplay.h>

void setup() {
  NefryDisplay.print("POKIO");
  NefryDisplay.print("KEIKYU");
}

void loop() {

}
```


![ディスプレイライブラリの例](display1)



もし、ディスプレイの横幅より長い文字列を入力しても、自動でスクロール表示してくれます。


```
#include <NefryDisplay.h>

void setup() {
  NefryDisplay.print("POKIOPOKIOPOKIOPOKIO");
  NefryDisplay.print("KEIKYUKEIKYUKEIKYUKEIKYU");
}

void loop() {

}
```


![長い文字列を表示したとき](display2)


ただし、ディスプレイに表示できるのは3行までで、4行以上表示しようとすると、最後に表示しようとした3行分が表示されます。


```
#include <NefryDisplay.h>

void setup() {
  NefryDisplay.print("P");
  NefryDisplay.print("O");
  NefryDisplay.print("K");
  NefryDisplay.print("I");
  NefryDisplay.print("O");
}

void loop() {

}
```


![4行以上の文字列を表示したとき](display3)


たとえば、「P」「O」「K」「I」「O」と表示しようとしたときは、最後の3行である **「K」「I」「O」** だけが表示される事になります。


このように、`NefryDisplay#print()`は非常に便利な関数です。実行中のプログラムのログを表示したり、表示した文字列が3行以下の場合におすすめです。


### 高度な使い方


もう少し、凝った表示をしたいときは、`NefryDisplay#autoScrollFunc()`で表示したい要素を記述した関数を渡す方法があります。


たとえば、好きな位置に文字列を表示させたいときは、`NefryDisplay#drawString()`を使います。


```
#include <NefryDisplay.h>

void setup() {
  NefryDisplay.setAutoScrollFlg(true);
  NefryDisplay.autoScrollFunc(pokioPrint);
}

void loop() {

}

void pokioPrint() {
  NefryDisplay.drawString(0, 0, "POKIO");
  NefryDisplay.drawString(20, 15, "POKIO");
  NefryDisplay.drawString(40, 30, "POKIO");
  NefryDisplay.drawString(60, 45, "POKIO");
}
```


![好きな位置に文字を表示する](display4)


このように、「POKIO」という文字を好きな位置に配置できました。また、`NefryDisplay#autoScrollFunc()`を使う場合は`Nefry PrintDialog`という固定で表示される文字列もないので、ディスプレイ全体をフルに使うことができます。



もちろん、文字列以外にも図形を表示できます。


```
#include <NefryDisplay.h>

void setup() {
  NefryDisplay.setAutoScrollFlg(true);
  NefryDisplay.autoScrollFunc(pokioPrint);
}

void loop() {

}

void pokioPrint() {
  NefryDisplay.drawCircle(10, 10, 10);
  NefryDisplay.fillCircle(40, 40, 20);
  NefryDisplay.drawRect(40, 10, 20, 20);
  NefryDisplay.fillRect(70, 30, 30, 30);
  NefryDisplay.drawHorizontalLine(100, 10, 15);
  NefryDisplay.drawHorizontalLine(100, 15, 15);
  NefryDisplay.drawVerticalLine(105, 5, 15);
  NefryDisplay.drawVerticalLine(110, 5, 15);
}
```


![図形を表示する](display5)


このように、少し凝った表示も簡単に実装することができます。
