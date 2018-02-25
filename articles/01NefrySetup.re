
= Nefryのセットアップをしよう

Nefry BTにはオプションでディスプレイが取り付けられます。



//image[display][display]{
//}




ディスプレイの4本の足をNefryの4本のピンソケットにさします。
//image[display2][接続してみる]{
//}




このような形でささります。ディスプレイからはNefry BTのIPや無線LAN情報などを確認できます。
//image[display3][完成形]{
//}




Nefry BTのピンでD0とD1がありますが、そのふたつのピンはディスプレイの制御（I2C通信）に使用されているため正常に動作しないことがあります。


== ArduinoIDEでプログラムを書くために知っておくこと


先ほどの手順でインストールしたArduinoIDEを使ってNefry BTの上で動くプログラムを作成します。


=== Arduinoのプログラムって？


Nefry BTのプログラムはArduinoのプログラムと同じようにかけます。



ArduinoIDEが起動するとプログラムを入力するところに初めからこのようなプログラムが書いてあります。


//emlist[][c++]{
void setup(){

}

void loop(){

}
//}




簡単に説明していきます。


//emlist[][c++]{
void setup()
//}


ここの部分では起動時に一度だけ行われる処理を書きます。 たとえば、入出力ピンの設定や温度センサなどセンサ類の初期設定などを入力します。


//emlist[][c++]{
void loop()
//}


ここの部分では起動中ずっと繰り返し行われる処理を書きます。 たとえば、LEDの点滅やセンサーデータの取得などを入力します。



Nefry BTではこのsetupとloopをうまく活用してプログラムを書いていきます。





参考 : @<href>{http://nefry.studio/Nefry%E3%81%AE%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%A0%E3%82%92%E6%9B%B8%E3%81%93%E3%81%86/,Nefryのプログラムを書こう}


== LEDを点滅させてみよう！


Arduinoの基礎を学んだところでLEDを点滅させるLチカと呼ばれるハードウエア入門してみましょう！



まずは一度だけLEDを点滅させてみましょう！
一度だけなので@<tt>{void setup()}にLEDを点滅させるプログラムを書きます。
LEDの制御をするためには、@<tt>{digitalWrite}という関数を呼び出し、制御します。


//quote{
関数の詳細については@<href>{http://www.musashinodenpa.com/arduino/ref/index.php?f=0&pos=2025,こちら}

//}


関数の引数を確認すると、@<tt>{digitalWrite(LED,LOW);}としたときに消灯、@<tt>{digitalWrite(LED,HIGH);}としたときに点灯となります。
それをプログラムで表現してみます。


//emlist[][c++]{
#define LED D6
//LEDをD6につないでください
void setup() {
  pinMode(LED, OUTPUT);//あらかじめLEDを制御できるように出力モードにしておきます
  digitalWrite(LED,HIGH);
  delay(5000);//5秒待つ
  digitalWrite(LED,LOW);
  delay(5000);
}

void loop() {
}
//}


一度だけLチカできたでしょうか？
見損ねた場合、リセットボタンを押すとプログラムを再度初めから行うことができます。



それでは次のステップとして、LEDを何度も点滅させてみましょう！
何度もなので、今度は@<tt>{void loop()}の中で同じ処理を書いてみます。


//emlist[][c++]{
#define LED D6
//LEDをD6につないでください
void setup() {
  pinMode(LED, OUTPUT);//あらかじめLEDを制御できるように出力モードにしておきます
}

void loop() {
  digitalWrite(LED,HIGH);
  delay(5000);//5000ms//5秒待つ
  digitalWrite(LED,LOW);
  delay(5000);
}
//}


Arduinoがどのようなものなのか少しでも理解できたでしょうか？
@<tt>{void setup()}や@<tt>{void loop()}をNefry BTのプログラムを作っていくので知っておいてください。
せっかくなのでdelayの秒数を変更してみたりして、あそんでみましょう。



余談なのですが、もっとLEDのON,OFFの間隔を狭くするとLEDの明るさをコントロールすることもできます。


//emlist[][c++]{
#define LED D6
//LEDをD6につないでください
void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED,HIGH);//あらかじめLEDを制御できるように出力モードにしておきます
  delayMicroseconds(100);//100us//10にも変更してみましょう
  digitalWrite(LED,LOW);
  delayMicroseconds(100);
}
//}
