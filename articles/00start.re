
== ハードウエアやってみよう


みなさん、ハードウエアを作ってみたことありますか？



プログラムを書くことでソフトウェアをつくり、PCからディスプレイ上でマウスの動きに合わせてアニメーションさせてユーザーに情報を伝えることができます。



ですが、そのソフトウェアで出来上がった仕組みに、さらにハードウエアも作ることができると、ディスプレイの中の出来事を飛び出して、現実世界で直接知覚しダイナミックに動かすこともできます。



たとえば、電車の遅延情報を例に上げてみましょう。この情報をソフトウェアの力でインターネット上で表示している場合、文字で～～～分の遅延という形で一覧で確認しやすくしています。



ですが、この遅延情報に応じてLEDでピカピカと光ってハードウェアを作って連動させるとどうでしょう。そうすると、LEDが光ることで一目瞭然に「あ、遅れているな」ということが分かり、ディスプレイ上で一覧で目を追うよりも直接知覚しダイナミックに伝わります。



//image[00start_01][京急の遅延情報を伝えるガジェット][scale=0.8]{
//}




このように、ソフトウェアでの情報をディスプレイでみる視覚情報だけでなく、ハードウェアの力を加えることで情報を分かりやすく強調することができます。



もう一つ、ハードウェアの側面としてセンサーによって現実世界の色々な状況を計測・判別もできることにも注目です。たとえば光センサーでは人間の目のように空間の明るさを検知できます。他にも温度センサーのように人間が感じる部屋の暑さ・寒さを人間の代わりに教えてくれます。


//quote{
複雑なセンサーでエンタメに寄せる案（Grove I2Cカラーセンサー）

//}


//image[00start_02][カラーセンサーを使ったサンプル][scale=0.8]{
//}




この例はカラーセンサーを使ったサンプルです。センサーが判定した色と照明が同期するものです。これはスマートフォンやPCで標準で付いているキーボードやタッチセンサーでは検知できないもので、このようなセンサーをきっかけにすることで、ソフトウェアで作った仕組みに、新しい体験を加えることができます。


//quote{
複雑なセンサーでエンタメに寄せる案　ここまで　↑



センサーによる活用例に寄せる案（IoT的）
仕掛けが必要なので短く説明するのが難しい・・・

//}


センサーで人間が知覚できる情報を肩代わりできるといろいろな展開ができます。たとえば、磁石センサーを使うとドアに磁石を設置すればドアの開け閉めが分かるようになりますし、人間が見に行かずドアを経由した人の出入りが分かるようになります。


//quote{
センサーによる活用例に寄せる案（IoT的）　ここまで　↑

//}


このように、ハードウエアを使うことで、いろいろな形で現実世界をハックすることができます。


== ハードウェアは最近とっつきやすくなりました


さて、このハードウェア。



以前ですと、

 * コンデンサや抵抗など電子の基礎知識
 * 部品の接続をするために必要な回路図の理解
 * 部品選択のために必要なデータシートの読み方
 * 半田付け等の基礎技術



などなど、さまざまな事柄が絶妙に組み合わさってこそ初めて踏み入れることができる領域でした。



実際、この章を書いている私も、何度も踏み入れようとしてうまくいかなかった経験があります。



しかし、近年、ハードウェアの周辺も変わってきています。



//image[00start_03][回路や電流の流れの制御をソフトウェアで手軽に行えるArduino][scale=0.8]{
//}

キャプション：回路や電流の流れの制御をソフトウェアで手軽に行えるArduino



まず、Arduinoという技術などの台頭により、ハードウェアで行う電流の流れの制御や回路に任せていた複雑な仕組みについてもソフトウェアの力も借りやすくなりました。



近年のIoTの登場によって、さらに楽しさが増してます。今までハードウェアの中で完結していたデータが、インターネットの力とうまく混ぜ合わせることで、情報の世界に飛び出し生き生きと活用されるようになってきています。



//image[00start_04][Nefry BTに繋がるGroveシリーズ][scale=0.8]{
//}

キャプション：Nefry BTに繋がるGroveシリーズ



そして、Groveやブレッドボードといった技術によって部品をあつかう技術についても、ハンダ付けをしなくても手軽に電子工作を体験できる仕組みも整ってきていることも心強いポイントでしょう。



このように、ソフトウェアにより何度でも試行錯誤できることや、Groveピンやブレッドボードで手軽にセンサーや動きを試せることによって間口が広がり、インターネット上に、たくさんの試行錯誤したレシピが紹介されるようになり、ハードウェアのとっつきやすさは増しています。


== さて、Nefry BT！


Nefry BTは、このようなハードウェアのやりやすさが盛り上がってきた中で「簡単にインターネットにつながる」ことをコンセプトに生まれました。



//image[00start_05][Nefry BTのしくみ][scale=0.8]{
//}




このようにフリスクケースくらいの大きさにさまざまな機能がギュッと詰まっています。できるだけハードウェアを意識せずに使えるように設計され、はんだづけや複雑な接続なしで動作するデバイスです。（もしかすると、見慣れない言葉や機能もあるかもしれませんが、このチュートリアルで追って使い方を説明していくので大丈夫です）



//image[00start_06][はんだづけや複雑な接続なしでLEDやスイッチが試せる]{
//}




初めてハードウェアを触る方にもおすすめです。先ほど紹介したLEDやスイッチが内蔵されていて、Nefry BT 1台でも、最初から使うことができます。



//image[00start_07][手軽にインターネットやPCに繋がる][scale=0.8]{
//}




また、Arduinoで手軽にインターネットにつながるESP-WROOM-32をベースにしているためインターネットに手軽に接続でき、PCと通信できるUSBポートも備えているので開発もしやすいです。



//image[00start_08][Groveポートやブレッドボードとつなぎやすい][scale=0.8]{
//}




そして、より発展してNefry BTにセンサーや動きを追加したいと思ったときも、GroveポートやブレッドボードとつなぎやすいGPIOピンが付いているので、発想を広げやすいです。



この書籍では、Nefry BTのこのようなつなぎやすいポイントを軸にして、ひとつひとつステップアップしていけるようご紹介するチュートリアル形式となっています。



さあ、一緒にはじめてみましょう！

