
= Nefryにプログラムを書き込む方法

この章では、Nefryにプログラムを書き込む方法を紹介します。前章のArduino IDEのセットアップを済ませておいてください。

現状Nefryへのプログラムの書き込みには2つの方法があります。

 * Arduino IDEから書き込む
 * Webコンソールから.binファイルをアップロードする

Webコンソールからのアップデートは、Nefryを直接PCへさせない場合などに活用してください。

== Arduino IDEから書き込む
=== NefryをPCのUSBポートにさしこむ
Nefry BTをPCのUSBポートにさしてください。Arduino IDEでシリアルポートの選択をします。

 * Macの場合
メニューの @<tt>{ツール} > @<tt>{シリアルポート} > @<tt>{/dev/cu.usbserial-xxxxxx} を選択します。環境によっては @<tt>{/dev/tty.usbserial-xxxxxx} などの場合もあります。

 * Windowsの場合
メニューの @<tt>{ツール} > @<tt>{シリアルポート} > @<tt>{COMxx} （xxの部分はNefry BTが挿してあるCOMポート） を選択します。

=== プログラムを書き込む
次のようなウインドウが表示されます。

//image[image1][Arduino IDEの初期ファイル][scale=0.6]{
//}

@<tt>{void setup()} 内に起動時に実行したいプログラムを、@<tt>{void loop()} 内に起動中実行したいプログラムを記述していきます。

//image[image2][プログラムのファイルを名前をつけて保存][scale=0.6]{
//}
左上の「✔︎」を押すとエラーが無いか検証し、「→」を押すとボードにプログラムを書き込みます。

== Webコンソールから.binファイルをアップロードする
=== プログラムをコンパイルする
//image[image3][02NefryProgram][scale=0.4]{
//}
Arduino IDEでプログラムを書いたあと、@<tt>{ファイル} > @<tt>{名前をつけて保存} を選び、任意の場所に保存します。

//image[image6][コンパイルしたバイナリを出力][scale=0.4]{
//}
@<tt>{スケッチ} > @<tt>{コンパイルしたバイナリを出力} を選択すると、先ほど保存した場所に.binファイルが作成されます。

=== Nefryコンソールを開く
//image[image4][設定画面][scale=0.8]{
//}
前章を参考に、NefryのWebコンソールを開きます。「Upload Sketch」を選択します。

//image[image5][Upload Sketch][scale=0.8]{
//}
先ほど保存した.binファイルをドラッグ＆ドロップ（又はファイルを選択）します。

アップロードが完了すると、Nefryが再起動しプログラムが動き出します。
