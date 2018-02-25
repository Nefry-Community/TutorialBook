+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 15
slug = "nefrybt-error-handling-2"
title = "コンパイルは成功するのに書き込みが失敗する"
title_eng = "about Nefry BT"
description = "Nefry BTでコンパイルは通っても書き込みが失敗する人のための記事です。"
draft = false
doctype = ["nefrybt"]
date = "2018-01-17T01:02:41+09:00"
+++

(2018年1月現在)Nefry BTのコンパイルは成功するのに、書き込み時にエラーが出てしまう場合があります。

## 解決策

* 何度か書き込みを再チャレンジすると書き込めます。
* Arduino IDEのUpload Speedを遅くするとうまくいきます。
    * 921600になっていたものを460800にするなど

![](https://i.gyazo.com/c5dd59164e9c899cabc7432d29d39395.png)

## エラー例

ESP32側のバグが関係しているそうです。

![](https://i.gyazo.com/7e4db071b4106e2397cb1da020313e12.png)

```
A fatal error occurred: Timed out waiting for packet header
```

```
A fatal error occurred: Timed out waiting for packet content
```

```
A fatal error occurred: Invalid head of packet ('F')
```

```
A fatal error occurred: Failed to set SPI params (result was 8080)
```

```
A fatal error occurred: Invalid head of packet ('\x80')
```

```
A fatal error occurred: Failed to write compressed data to flash after seq 1 (result was C100)
```

```
A fatal error occurred: MD5 of file does not match data in flash!
```
