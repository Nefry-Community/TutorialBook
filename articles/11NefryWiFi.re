= Nefry BTを無線LANに接続しよう
プログラムを試す前に、Nefry BTをインターネットに繋げましょう！

Nefry BTは2.4GHz帯の無線LANと接続することができます（5GHz帯の無線LANには接続できないので注意してください）。

設定を始めるために、Nefry BTをPCやモバイルバッテリーなどに接続してNefry BTに給電しましょう。
電源スイッチはなく、給電したらすぐに起動するようになっています。

//image[power_supply][電源接続][scale=0.8]{
//}
電源に接続すると、Nefry BT中央に付いているLEDが点滅して起動します（@<img>{power_supply}の青く光っている部分です）。

//image[nefry_wifi][無線LANのSSIDを確認しよう][scale=0.7]{
//}
起動すると、「NefryBT-OOOO」という無線LANの信号が周りに向けて発信されるので、それを設定するPC等の端末で選択し、接続します。

この無線LANの名前はNefry BTごとに個別のものになっているので注意してください。
（このときディスプレイがあると、名前を簡単に確認することができます。）

Nefryの無線LANに接続中は、設定している端末がインターネットに繋がらなくなるので注意してください。

//image[setup_page][設定ページ][scale=0.8]{
//}
接続すると自動でWebコンソールが立ち上がります（立ち上がらない場合はブラウザでhttp://192.168.4.1 にアクセスします）。

このコンソールからNefry BTに関するさまざまな設定ができます。


今回必要な設定は無線LANの情報なので「Setup WiFi」をクリックします。

//image[setup_wifi][無線LANの設定][scale=0.8]{
//}
無線LANの設定画面に移動したらNefry BTが利用する無線LANのSSIDとパスワードをそれぞれの欄に入力します。
入力が完了したら「Save」をクリックし、保存します。

===[column] Nefry BTで設定できるネットワークについて
Nefry BTには2つのネットワークを設定することができます。

==== Nefryが発信する無線LAN
"NefryBT-OOOO"という無線LANをNefryは自ら発信しています。
この無線LANに接続することで、インターネットがない環境でもNefryの設定をすることができます。

この章では初めにこちらの無線LANに接続し、設定を行います。
この無線LANは外のネットワークには接続されません。

==== Nefryが接続する無線LAN
家やオフィスなどインターネットに接続できる無線LANをさします。

Nefry BTは5つまで無線LANの設定を記憶することができます。
5つの中からもっとも電波の強い無線LANに接続し、外のネットワークに接続します。

これを設定することでNefry BTがこの先連携するさまざまなクラウドサービスと連携できるようになります。

===[/column]

しばらくすると、Nefry BTは設定を有効にするために自動で再起動します。
再起動が完了したら、無線LANのセットアップは完了です。

//image[nefry_ip][IPアドレス確認][scale=0.8]{
//}
確認のために再度Nefry BTの無線LANに繋いでWebコンソールを開くと、利用する無線LANのSSIDとNefry BTのIPアドレスが表示されているはずです。

このときに無線LANのSSIDの表記がない場合、リセットボタンを押して再起動するか無線LANの設定があっているか確認してください。

以後同じ無線LANを利用するときはインターネットに繋いだままこのIPアドレスで設定ができます。
