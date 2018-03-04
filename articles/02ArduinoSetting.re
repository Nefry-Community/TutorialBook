= Nefry BT向けのArduino IDEセットアップ方法
//comment{
環境構築
//}

このページでは、Arduino IDEにNefry BTの開発環境をインストールする方法を紹介します。@<strong>{Arduino IDEでNefry BTの開発をする際に必須になる項目です。}


== Arduino IDEのインストール


Arduinoのサイト（https://www.arduino.cc/en/Main/Software）から自身の環境に合わせたダウンロードリンクを選択します。



//image[arduino_ide_download][ArduinoのサイトからIDEをダウンロード]{
//}




Windows用、macOS用、Linux用が用意されています。Linux用にはARM版もありますので、Raspberry Piなどにもインストール可能になっています。



//image[arduino_ide_donation][Arduinoへの寄付]{
//}




ダウンロードリンクを選択すると、Arduinoへの寄付が求められます。無料でIDEは利用できますが、IDEへの感謝を示したい場合は寄付をしてみてはいかがでしょうか。もちろん寄付を行わなくてもソフトウェアのダウンロードは可能です。@<tt>{JUST DOWNLOAD}をクリックしてダウンロードを開始しましょう。


=== macOS向けのIDE


//image[arduino_ide_mac][macOSでのインストール]{
//}




macOS向けのダウンロードリンクを選択した場合は、Arduino IDEそのもののダウンロードが開始されるので、ダウンロードしたZIPファイルを解凍してアプリケーションフォルダに移動するだけでインストールが完了します。


=== Windows向けのIDE


Windowsの場合、インストーラーをダウンロードするやりかたの他にも、必要なファイルがZIPで固められているものをダウンロードするやり方や、Windows Storeからダウンロードする方法もあります。



//image[arduino_ide_win_installer][Windows向けのインストーラー（EULA画面）]{
//}




インストーラーをダウンロードした場合は、ダウンロード完了後にインストーラーを起動します。上記のようなライセンス許諾の画面が表示されますので、問題がなければ@<tt>{I Agree}をクリックして次に進みます。



//image[arduino_ide_win_installer2][Windows向けのインストーラー（オプション画面）]{
//}




次の画面でインストールオプションを選択できる画面に遷移しますが、特に問題がなければ@<tt>{Next}をクリックしてインストールを開始させます。次の画面でインストールの進捗が表示され、@<tt>{Completed}と表示されたらインストール完了です。



//image[arduino_ide_win_zip][Windows向けのIDEのZIPファイルを解凍]{
//}




また、インストーラーではなくZIPファイルをダウンロードした場合、ダウンロード後にZIPを解答すると上記のようなファイルが展開されます。この中の@<tt>{arduino.exe}をダブルクリックするとArduino IDEを起動することができます。



//image[arduino_ide_win_app_store][WindowsストアからArduino IDEをインストールする]{
//}




Windows 8.1や10をお使いであれば、WindowsストアからもArduino IDEをインストールすることができます。


=== 起動してみましょう


//image[arduino_ide_main][Arduino IDE メイン画面]{
//}




インストールが終わったら、Arduino IDEを起動してみましょう。スプラッシュ画面が表示された後に、このような画面が表示されるはずです。


== ボードマネージャの追加


メニューの@<tt>{Arduino} > @<tt>{Preferences}を選択します。環境設定のダイアログが開きます。



@<tt>{追加のボードマネージャのURL}のフォームに次のURLを追加しましょう。


//emlist{
http://nefry.studio/package_nefrybt_index.json
//}

//image[mac01][環境設定]{
//}




追加できたらOKを選択します。


== ボードマネージャを開く


メニューの@<tt>{ツール} > @<tt>{ボード} > @<tt>{ボードマネージャ}を選択します。



//image[mac02][ボードマネージャーの開き方]{
//}




するとこのようなボードマネージャダイアログが表示されます。


//image[mac03][ボードマネージャー]{
//}



== Nefry BT用の開発環境を追加する


フォームに@<tt>{Nefry}と入力して検索すると項目が表示されます。




//image[mac04][ボードマネージャーにNefryと入力する]{
//}




@<tt>{インストール}を押すとインストールが開始されます。



横のプルダウンメニューでバージョンを指定できます。



Nefry BTのライブラリバージョンは、 メジャーバージョン、マイナーバージョン、パッチバージョンに分かれています。

 * メジャーバージョン - 大きな変更
 * マイナーバージョン - 機能追加などの更新
 * パッチバージョン - バグ修正など



例えば@<tt>{v1.2.3}の場合、最初の1がメジャーバージョン、次の2がマイナーバージョン、最後の3がパッチバージョンとしています。また、 LTS(安定)版と開発版を分けていて、マイナーバージョンが偶数か奇数かで分けています。LTSがv1.2系、開発版がv1.1系などとなります。その次はLTSが1.4系、開発版がv1.3系となり、以降も偶数と奇数でのアップデートとなります。更新についてはNefryのGitHubページ（https://github.com/Nefry-Community/arduino-esp32/）にあるリリースノートに記載がありますので、参考にしてみて下さい。


//image[mac05][インストール]{
//}



あとはインストールが完了するまで待つだけです。


== 確認


メニューの@<tt>{ツール} > @<tt>{ボード}を選択したときに@<tt>{Nefry BT}の項目が追加されていればOKです。

//image[mac06][ボード選択]{
//}




Nefry BT R2以降は@<tt>{Nefry BT R2}を選択しましょう。


//image[mac07][ボード選択詳細]{
//}



Nefry BTがお手元に届いたら、まずはバージョンを確認しましょう！



現在（2018年1月）Nefry BTは無印のもの（R1）とR2が存在します。



ちなみに、Nefry v2（https://dotstud.io/shop/nefry-connect-internet/）というボードも存在するので区別するために、VersionではなくRevisionとしました。



//image[device][ボード背面]{
//}




背面に@<strong>{R2}の文字があればR2で無ければ無印となります。



2018年1月以降に出荷しているものは基本的にR2となっています。



基本的な使い方に代わりはないですが、 書き込み時のボード選択でR2の場合は@<tt>{Nefry BT R2}を選択し、無印の場合は@<tt>{Nefry BT}を選択して書き込みをして下さい。




お疲れ様でした。



次は、はじめてのプログラム書き込みの例としてNefry BT付属のLEDでLチカを試してみてください。
