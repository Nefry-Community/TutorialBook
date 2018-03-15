
= LEDでGPIO制御してみる

このページではNefry BTでLEDを制御する方法を紹介します。



事前に、Nefry BTに組み込まれているフルカラーLEDを利用したLチカを@<href>{/docs/nefrybt-led,こちらのドキュメント}を参照して試してみましょう。



ちなみにNefry BTのピンでD0とD1がありますが、そのふたつのピンはディスプレイの制御（I2C通信）のために使用されているため正常に動作しないことがあります。（←Nefry BT R2で修正しました。）


== アナログLED


通常のLEDです。



LEDについては@<href>{/docs/led/,こちらのドキュメント}を参照してください。


== 配線


Nefry BTのA1ピンソケットにカソード（+側、足の長い方）ピンを、隣のGNDピンソケットにアノード（-側、足の短い方）


== コード


次のコードでこのページ上部のようなLEDの点滅になります。


//emlist{
#define LED_PIN A1
#define DELAY_TIME 1000

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_TIME);
}
//}
