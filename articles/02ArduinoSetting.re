= Nefry BT向けのArduino IDEセットアップ方法
//comment{
環境構築
//}

このページでは、Arduino IDEにNefry BTの開発環境をインストールする方法を紹介します。@<strong>{Arduino IDEでNefry BTの開発をする際に必須になる項目です。}



Arduino IDEのインストールは@<href>{/docs/arduinoide-setup/,こちらのドキュメント}を参照してください。


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



横のプルダウンメニューでバージョンを指定できますが、@<href>{/docs/nefrybt-library,Nefry BTのライブラリ} を参考にバージョン選択するようにしましょう。

//image[mac05][インストール]{
//}



あとはインストールが完了するまで待つだけです。


== 確認


メニューの@<tt>{ツール} > @<tt>{ボード}を選択したときに@<tt>{Nefry BT}の項目が追加されていればOKです。

//image[mac06][ボード選択]{
//}




Nefry BT R2以降は@<href>{/docs/nefrybt-revision-check,Nefry BTのリビジョンのチェック}を参考にして、@<tt>{Nefry BT R2}を選択しましょう。


//image[mac07][ボード選択詳細]{
//}



Nefry BTがお手元に届いたら、まずはバージョンを確認しましょう！



現在（2018年1月）Nefry BTは無印のもの（R1）とR2が存在します。



ちなみに、@<href>{/docs/nefry/,Nefry v2}が存在するので区別するために、VersionではなくRevisionとしました。



//image[device][Device]{
//}




背面に@<strong>{R2}の文字があればR2で無ければ無印となります。



2018年1月以降に出荷しているものは基本的にR2となっています。



基本的な使い方に代わりはないですが、 @<href>{/docs/nefrybt-arduino-ide-setup/,Arduino IDEでの書き込み}の際の指定の仕方が少し変わります。



書き込み時のボード選択でR2の場合は@<tt>{Nefry BT R2}を選択し、無印の場合は@<tt>{Nefry BT}を選択して書き込みをして下さい。




お疲れ様でした。



次は、はじめてのプログラム書き込みの例として@<href>{/docs/nefrybt-led/,Nefry BT付属のLEDでLチカ}を試してみてください。
