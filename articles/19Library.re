= Nefryライブラリ紹介

この章ではNefry BTの便利なライブラリの一部をご紹介します。
詳しい使いかたについては、Nefry事例本をご覧ください。

== Ambientライブラリ（NefryAmbient.h）

Ambient（@<href>{https://ambidata.io/}）は、主にマイコンボードなどからのデータを簡単に可視化できるサービスです。

サンプルコードは@<tt>{NefryLibrary/ambient}から確認することができます。

//image[ambient_top][Ambientのホームページ][scale=0.8]{
//}

Ambientライブラリは、@<code>{NefryAmbient.h}をincludeすることで使えるようになります。

@<code>{begin()}関数で、データを送信したいチャネルのIDとライトキーを設定します。
その後@<code>{set()}でデータを詰めて@<code>{send()}を呼ぶことでデータをAmbientに送信できます。

サンプルコードでは、A0ピンのアナログ入力値を読み取り、Ambientに送信しています。

@<code>{begin()}関数で必要になる、チャネルIDとライトキーは「Myチャネル」から確認できます。

//image[ambient_detail][Myチャネル][scale=0.8]{
//}

== Microsoft Azure IoT Hubライブラリ（NefryAzureIoTHub.h）

IoT Hub（@<href>{https://azure.microsoft.com/ja-jp/services/iot-hub/}）とは、Microsoft Azureで提供されているIoT向けのバックエンドサービスです。

サンプルコードは@<tt>{NefryLibrary/azureiothub}から確認することができます。


//image[azureiothub_top][Microsoft Azure IoT Hubホームページ][scale=0.8]{
//}

IoT Hubライブラリは、@<code>{NefryAzureIoTHub.h}をincludeすることで使えるようになります

@<code>{begin()}関数で、接続文字列というIoT Hub用のアクセスキーを設定し、@<code>{setCallback()}関数でIoT Hubからのメッセージを受け取る関数の設定を行っています。
データをIoT Hubに送信するときは、@<code>{connect()}関数で接続してから、@<code>{DataElement}インスタンスに送信したい値を詰めて、@<code>{push()}関数で送信します。

サンプルコードでは、A0ピンのアナログ入力値を読み取り、Azure IoT Hubに送信しています。

@<code>{begin()}関数で必要な接続文字列は、IoT Hub内のデバイスエクスプローラーを開き、登録したデバイスを選択すると次のような画面が表示され確認することができます。
登録したデバイスごとに接続文字列が異なるので注意が必要です。

//image[azureiothub_detail][デバイスエクスプローラー][scale=0.8]{
//}

== FASTSENSINGライブラリ（NefryFastSensing.h）
FASTSENSING（@<href>{https://fastsensing.com/ja/}）は、専用のデバイスやマイコンボードからのセンサーデータを受信し、グラフ化や異常検知をしてくれるサービスです。

サンプルコードは@<tt>{NefryLibrary/fastsensing}から確認することができます。
//image[fastsensing_top][Fastsensingのホームページ][scale=0.8]{
//}

FASTSENSINGライブラリは、@<tt>{NefryFastSensing.h}をincludeすることで使えるようになります

@<code>{begin()}関数で、データを送信したいデバイスと３つのチャンネルを設定します。
その後@<code>{setValue()}関数でデータを詰めて@<code>{push()}関数を呼ぶことでデータをFASTSENSINGに送信できます。

サンプルコードでは、A0ピンのアナログ入力値を読み取り、FASTSENSINGに送信しています。

@<code>{begin()}関数で必要なトークンは、FASTSENSINGのデバイスタブから@<tt>{開発用スタブデバイス}をクリックすると次のような画面が表示され確認することができます。
//image[fastsensing_detail][スタブデバイスの詳細][scale=0.8]{
//}

== ThingSpeakライブラリ（NefryThingSpeak.h）
ThingSpeak（@<href>{https://thingspeak.com/}）は、マイコンなどからのセンサーデータを収集し、グラフ化やMATLABを使って分析を行えるだけでなく、Twitterなどの別のサービスへのアクションを行えるサービスです。

サンプルコードは@<tt>{NefryLibrary/thingspeak}から確認することができます。
//image[thingspeak_top][ThingSpeakのホームページ][scale=0.8]{
//}

ThingSpeakはチャネルを作ると1つのチャネルにつき最大8つデータを別々にアップロードすることができます。

ThingSpeakライブラリは、@<code>{NefryThingSpeak.h}をincludeすることで使えるようになります

@<code>{begin()}関数で、チャンネルIDを設定し、@<code>{setWriteAPIKey()}関数でライトAPIキーの設定します。
その後@<code>{writeField()}関数を呼ぶことでデータをThingSpeakに送信できます。

サンプルコードでは、A0ピンのアナログ入力値を読み取り、ThingSpeakに送信しています。

設定で必要な情報は、ThingSpeakにデータをアップロードする際は、次の画面のようにThingSpeakのサイトのAPI Keysを確認することができます。
//image[thingspeak_detail][ThingSpeakのAPIキー][scale=0.8]{
//}

== Firebaseライブラリ（NefryFireBase.h）
Firebase（@<href>{https://firebase.google.com/?hl=ja}）は、モバイルとウェブアプリケーションの開発プラットフォームです。

このFirebaseライブラリでは、リアルタイムデータベースへの読み書きを可能にします。

サンプルコードは@<tt>{NefryLibrary/firebase}から確認することができます。
//image[firebase_top][Firebaseのホームページ][scale=0.7]{
//}

Firebaseライブラリは、@<code>{NefryFireBase.h}をincludeすることで使えるようになります

@<code>{begin()}関数で、ホスト名とシークレットキーを設定します。

データをFirebaseに送信するときは、@<code>{DataElement}インスタンスに送信したい値を詰めて、@<code>{write()}関数で送信します。

サンプルコードでは、A0ピンのアナログ入力値を読み取り、Firebaseに送信しています。

設定で必要な情報は、Firebaseのページ上でリアルタイムデータベースを作成すると、@<tt>{begin()}関数で必要なホストを取得できます。
//image[firebase_database_host][Firebaseのデータベースのホスト名][scale=0.7]{
//}

もうひとつ必要なシークレットキーは、プロジェクトの設定＞サービスアカウント＞データベースのシークレットで確認ができます。
//image[firebase_database_secret][Firebaseのデータベースのシークレット][scale=0.7]{
//}

設定をすると次のようにFirebaseのデータベースに値が送信されたのを確認することができます。
//image[firebase_database_result][Firebaseのデータベースにデータを送信した例][scale=0.7]{
//}

== ティスプレイ（Nefry_Display）

ティスプレイライブラリは、@<code>{NefryDisplay.h}をincludeすることで使えるようになります。

=== 簡単な使い方


たとえば、@<code>{NefryDisplay#print()}を使うと、簡単にディスプレイに好きな文字列を表示することができます。


//image[display1][サンプルコード（NefryLibrary/display1）の例][scale=0.8]{
//}




もし@<code>{NefryDisplay#print()}に、ディスプレイの横幅より長い文字列を入力しても、自動でスクロール表示してくれます。



//image[display2][サンプルコード（NefryLibrary/display2）の例][scale=0.8]{
//}




ただし、ディスプレイに表示できるのは3行までで、4行以上表示しようとすると、最後に表示しようとした3行分が表示されます。


//image[display3][サンプルコード（NefryLibrary/display3）の例][scale=0.8]{
//}




たとえば、「P」「O」「K」「I」「O」と表示しようとしたときは、最後の3行である @<strong>{「K」「I」「O」} だけが表示されます。



このように、@<code>{NefryDisplay#print()}は非常に便利な関数です。実行中のプログラムのログを表示したり、表示した文字列が3行より少ない場合にお勧めです。


=== 高度な使い方


もう少し、凝った表示をしたいときは、@<code>{NefryDisplay#autoScrollFunc()}で表示したい要素を記述した関数を渡す方法があります。



たとえば、好きな位置に文字列を表示させたいときは、@<code>{NefryDisplay#drawString()}を使って関数を記述し、その関数を@<code>{NefryDisplay#autoScrollFunc()}に渡します。


//image[display4][サンプルコード（NefryLibrary/display4）の例][scale=0.8]{
//}




このように、「POKIO」という文字を好きな位置に配置できました。
@<code>{NefryDisplay#autoScrollFunc()}を使う場合は@<tt>{Nefry PrintDialog}という固定で表示される文字列もないので、ディスプレイ全体をフルに使うことができます。



もちろん、文字列以外にも図形を表示できます。
@<code>{NefryDisplay#drawString()}の代わりに、@<code>{NefryDisplay#drawCircle()}や@<code>{NefryDisplay#drawHorizontalLine()}などを使って図形を描くことができます。


//image[display5][サンプルコード（NefryLibrary/display5）の例][scale=0.8]{
//}




このように、少し凝った表示も簡単に実装することができます。
