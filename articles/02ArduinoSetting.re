= Nefry BT向けのArduino IDEセットアップ方法
//comment{
環境構築
//}

この章では、Arduino IDEにNefry BTの開発環境をインストールする方法を紹介します。@<strong>{Nefry BTの開発にはArduino IDEという無料のソフトウェアが必要ですので、この手順から始めてください。}


== Arduino IDEのインストール


Arduinoのサイト（https://www.arduino.cc/en/Main/Software）から自身の環境に合わせたダウンロードリンクを選択します。



//image[arduino_ide_download][ArduinoのサイトからIDEをダウンロード][scale=0.8]{
//}




Windows用、macOS用、Linux用が用意されています。Linux用にはARM版もありますので、Raspberry Piなどにもインストール可能になっています。



//image[arduino_ide_donation][Arduinoへの寄付][scale=0.8]{
//}




ダウンロードリンクを選択すると、Arduinoへの寄付が求められます。無料でIDEは利用できますが、IDEへの感謝を示したい場合は寄付をしてみてはいかがでしょうか。もちろん寄付を行わなくてもソフトウェアのダウンロードは可能です。@<tt>{JUST DOWNLOAD}をクリックしてダウンロードを開始しましょう。


=== macOS向けのIDE


//image[arduino_ide_mac][macOSでのインストール][scale=0.8]{
//}




macOS向けのダウンロードリンクを選択した場合は、Arduino IDEそのもののダウンロードが開始されるので、ダウンロードしたZIPファイルを解凍してアプリケーションフォルダに移動するだけでインストールが完了します。


=== Windows向けのIDE


Windowsの場合、インストーラーをダウンロードするやりかたの他にも、必要なファイルがZIPで固められているものをダウンロードするやり方や、Windows Storeからダウンロードする方法もあります。
今回は、インストーラーをダウンロードする方法を紹介します。


//image[arduino_ide_win_installer][Windows向けのインストーラー（EULA画面）][scale=0.6]{
//}




インストーラーをダウンロードした場合は、ダウンロード完了後にインストーラーを起動します。上記のようなライセンス許諾の画面が表示されますので、問題がなければ@<tt>{I Agree}をクリックして次に進みます。



//image[arduino_ide_win_installer2][Windows向けのインストーラー（オプション画面）][scale=0.6]{
//}




次の画面でインストールオプションを選択できる画面に遷移しますが、特に問題がなければ@<tt>{Next}をクリックしてインストールを開始させます。次の画面でインストールの進捗が表示され、@<tt>{Completed}と表示されたらインストール完了です。



//image[arduino_ide_win_zip][Windows向けのIDEのZIPファイルを解凍][scale=0.6]{
//}




また、インストーラーではなくZIPファイルをダウンロードした場合、ダウンロード後にZIPを解凍すると上記のようなファイルが展開されます。この中の@<tt>{arduino.exe}をダブルクリックするとArduino IDEを起動することができます。



//image[arduino_ide_win_app_store][WindowsストアからArduino IDEをインストールする][scale=0.6]{
//}




Windows 8.1や10をお使いであれば、WindowsストアからもArduino IDEをインストールすることができます。


=== 起動してみる


//image[arduino_ide_main][Arduino IDE メイン画面][scale=0.6]{
//}




インストールが終わったら、Arduino IDEを起動してみましょう。スプラッシュ画面が表示された後に、このような画面が表示されるはずです。


== ボードマネージャの追加


メニューの@<tt>{Arduino} > @<tt>{Preferences}を選択します。環境設定のダイアログが開きます。



@<tt>{追加のボードマネージャのURL}のフォームに次のURLを追加しましょう。


//emlist{
http://nefry.studio/package_nefrybt_index.json
//}

//image[mac01][環境設定][scale=0.8]{
//}




追加できたらOKを選択します。


== ボードマネージャを開く


メニューの@<tt>{ツール} > @<tt>{ボード} > @<tt>{ボードマネージャ}を選択します。



//image[mac02][ボードマネージャーの開き方][scale=0.8]{
//}




するとこのようなボードマネージャダイアログが表示されます。


//image[mac03][ボードマネージャー][scale=0.8]{
//}



== Nefry BT用の開発環境を追加する


フォームに@<tt>{Nefry}と入力して検索すると項目が表示されます。




//image[mac04][ボードマネージャーにNefryと入力する][scale=0.8]{
//}




@<tt>{インストール}を押すとインストールが開始されます。



横のプルダウンメニューでバージョンを指定できます。（2018/4/1現在 最新のバージョンは 1.2.1になります。）



Nefry BTのライブラリバージョンは、 メジャーバージョン、マイナーバージョン、パッチバージョンに分かれています。


//image[nefry_version][Nefry BTのバージョン][scale=0.8]{
//}


たとえばv1.2.3の場合、最初の1がメジャーバージョン、次の2がマイナーバージョン、最後の3がパッチバージョンとしています。


LTS（安定）版と開発版を分けていて、マイナーバージョンが偶数か奇数かで分けています。LTSがv1.2系、開発版がv1.1系などとなります。その次はLTSが1.4系、開発版がv1.3系となり、以降も偶数と奇数でのアップデートとなります。」（追記）「基本的にはLTS版を使うようにしてください。


更新についてはNefryのGitHubページ（https://github.com/Nefry-Community/arduino-esp32/）にあるリリースノートに記載がありますので、参考にしてみて下さい。


//image[mac05][インストール][scale=0.8]{
//}



あとはインストールが完了するまで待つだけです。


== 確認


メニューの@<tt>{ツール} > @<tt>{ボード}を選択したときに@<tt>{Nefry BT}の項目が追加されていればOKです。

//image[mac06][ボード選択][scale=0.8]{
//}




お手持ちのボードのリビジョンに合わせて選択しましょう。


== Nefryボードのバージョンを確認



Nefry BTがお手元に届いたら、まずはバージョンを確認しましょう！


//image[mac07][ボード選択詳細][scale=0.4]{
//}






Nefry BTには無印のもの（R1）とR2が存在します（2018年1月現在）。



Nefryボードには、初期NefryやNefry v2.0（https://dotstud.io/shop/nefry-connect-internet/）というバージョンも存在するので、BT内ではRevisionで分類しています。


//image[device][ボード背面][scale=0.8]{
//}




お手持ちのボードの背面でRevision番号を確認してください。表記のないものは無印となります。



次は、Nefry BTへのプログラムの書き込みを試してみましょう。
