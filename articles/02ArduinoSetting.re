= Arduino IDEのセットアップ
//comment{
環境構築
//}

この章では、Arduino IDEという開発ソフトにNefry BT向けの設定を追加する方法を紹介します。@<strong>{Nefry BTの開発にはArduino IDEが必要ですので、この手順から始めてください。}


== Arduino IDEのインストール
Arduino IDEは世界中で使われている、Arduino、Arduino互換ボード向けの無料開発ソフトです。

//image[arduino_ide_download][ArduinoのサイトからIDEをダウンロード][scale=0.8]{
//}
Arduino公式サイトの「Software」のページ（https://www.arduino.cc/en/Main/Software）から、自身の環境に合わせたダウンロードリンクを選択します。

Windows用、macOS用、Linux用が用意されています。Linux用にはARM版もありますので、Raspberry Piなどにもインストール可能になっています。



//image[arduino_ide_donation][Arduinoへの寄付][scale=0.8]{
//}
ダウンロードリンクを選択すると、Arduinoへの寄付（Contribute）が求められます。無料で利用できますが、IDEへの感謝を示したい場合は寄付をしてみてはいかがでしょうか。

寄付しない場合は「@<tt>{JUST DOWNLOAD}」をクリックしてダウンロードを開始しましょう。


=== macOS向けのインストール方法
//image[arduino_ide_mac][macOSでのインストール][scale=0.8]{
//}
macOS向けのダウンロードリンクを選択した場合は、ダウンロードしたZIPファイルを解凍してアプリケーションフォルダに移動するだけでインストールが完了します。

=== Windows向けのインストール方法
Windowsの場合、インストーラ、ZIPファイル、Windows Storeからダウンロードする方法を選択できます。

==== インストーラを利用する場合
//image[arduino_ide_win_installer][Windows向けのインストーラ（EULA画面）][scale=0.6]{
//}
インストーラをダウンロードした場合は、ダウンロード後にインストーラーを起動します。上記のようなライセンス許諾の画面が表示されますので、問題がなければ@<tt>{I Agree}をクリックして次に進みます。

//image[arduino_ide_win_installer2][Windows向けのインストーラ（オプション画面）][scale=0.6]{
//}
次の画面でインストールオプションを選択できる画面に遷移しますが、特に問題がなければ@<tt>{Next}をクリックしてインストールを開始させます。次の画面でインストールの進捗が表示され、@<tt>{Completed}と表示されたらインストール完了です。

==== ZIPファイルを利用する場合
//image[arduino_ide_win_zip][Windows向けのIDEのZIPファイルを解凍][scale=0.6]{
//}
ZIPファイルをダウンロードした場合、ダウンロード後にZIPを解凍すると上記のようなファイル群が展開されます。この中の@<tt>{arduino.exe}をダブルクリックするとArduino IDEを起動することができます。

==== Windowsストアを利用する場合
//image[arduino_ide_win_app_store][WindowsストアからArduino IDEをインストールする][scale=0.6]{
//}
Windows 8.1や10をお使いであれば、Windowsストアからインストールすることができます。


=== 起動してみる
//image[arduino_ide_main][Arduino IDE メイン画面][scale=0.6]{
//}
インストールが終わったら、Arduino IDEを起動してみましょう。スプラッシュ画面が表示された後に、このような画面が表示されるはずです。

この画面にプログラムを書いていきます。

== Nerfy BT向けの設定を追加
=== ボードマネージャの追加
Arduino IDEにNefry BT向けの設定を追加します。

メニューの@<tt>{Arduino} > @<tt>{Preferences}を選択し、環境設定のダイアログを開きます。

//image[mac01][環境設定][scale=0.8]{
//}
上記のように、@<tt>{追加のボードマネージャのURL}のフォームに次のURLを追加しましょう。

//emlist{
http://nefry.studio/package_nefrybt_index.json
//}

追加できたらOKを選択します。

=== ボードマネージャを開く
//image[mac02][ボードマネージャーの開き方][scale=0.8]{
//}
メニューの@<tt>{ツール} > @<tt>{ボード} > @<tt>{ボードマネージャ}を選択します。

//image[mac03][ボードマネージャー][scale=0.8]{
//}
するとこのようなボードマネージャダイアログが表示されます。


=== Nefry BTライブラリを追加する
//image[mac04][ボードマネージャーにNefryと入力する][scale=0.8]{
//}
フォームに@<tt>{Nefry}と入力して検索すると項目が表示されます。

@<tt>{インストール}を押すとインストールが開始されます。

横のプルダウンメニューでバージョンを指定できます（2018/4/1現在 最新のバージョンは 1.2.1になります）。

//image[mac05][インストール][scale=0.8]{
//}
あとはインストールが完了するまで待つだけです。

=== Nefry BTライブラリのバージョニング
//image[nefry_version][Nefry BTのバージョン][scale=0.8]{
//}
Nefry BTのライブラリバージョンは、 メジャーバージョン、マイナーバージョン、パッチバージョンに分かれています。例えばv1.2.3の場合、最初の1がメジャーバージョン、次の2がマイナーバージョン、最後の3がパッチバージョンです。

LTS（安定）版はマイナーバージョンが偶数、開発版はマイナーバージョンが奇数となるよう分けています。例えばv1.2系はLTS版、v1.1系は開発版です。基本的には最新のLTS版を使うようにしてください。

更新についてはNefryのGitHubページ（https://github.com/Nefry-Community/arduino-esp32/）にあるリリースノートに記載がありますので、参考にしてみて下さい。

== ボードを選択
//image[mac06][ボード選択][scale=0.8]{
//}
メニューの@<tt>{ツール} > @<tt>{ボード}を選択したときに@<tt>{Nefry BT}の項目が追加されていればOKです。

お手持ちのボードのリビジョン（表記なし、R2など）に合わせて選択しましょう。

//image[mac07][ボード選択詳細][scale=0.4]{
//}
Nefry BTには無印のもの（R1）とR2が存在します（2018年4月現在）。次の項目で確認方法を紹介します。

== Nefry BTのリビジョン確認方法
Nefryには、初期NefryやNefry v2.0（https://dotstud.io/shop/nefry-connect-internet/）というバージョンも存在するので、Nefry BT内でのハードウェアアップデートはリビジョンで分類しています。
//image[device][ボード背面][scale=0.8]{
//}
Nefry BTのリビジョンは背面で確認することができます。表記のないものは無印となります。
