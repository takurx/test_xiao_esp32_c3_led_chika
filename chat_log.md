# XIAO ESP32-C3 LED制御プログラム開発ログ

## 開発日時
2025年8月24日

## 要求事項
1. XIAO ESP32-C3のGPIOを1秒ごとにON/OFFするプログラム
2. 全てのGPIOピンで同時に実行

## 使用したGPIOピン
```
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 21 (合計13ピン)
```

## 最終的なプログラム
```cpp
#include <Arduino.h>

// XIAO ESP32-C3で使用可能な全GPIOピン
int gpioPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 21};
int numPins = sizeof(gpioPins) / sizeof(gpioPins[0]);

void setup() {
  // 全てのGPIOピンを出力として設定
  for (int i = 0; i < numPins; i++) {
    pinMode(gpioPins[i], OUTPUT);
  }
  
  // シリアル通信を初期化（デバッグ用）
  Serial.begin(115200);
  Serial.println("XIAO ESP32-C3 All GPIO LED Blink Start");
  Serial.print("Using GPIO pins: ");
  for (int i = 0; i < numPins; i++) {
    Serial.print(gpioPins[i]);
    if (i < numPins - 1) Serial.print(", ");
  }
  Serial.println();
}

void loop() {
  // 全てのGPIOをONにする
  for (int i = 0; i < numPins; i++) {
    digitalWrite(gpioPins[i], HIGH);
  }
  Serial.println("All GPIOs ON");
  delay(1000); // 1秒待機
  
  // 全てのGPIOをOFFにする
  for (int i = 0; i < numPins; i++) {
    digitalWrite(gpioPins[i], LOW);
  }
  Serial.println("All GPIOs OFF");
  delay(1000); // 1秒待機
}
```

## 開発履歴
1. 最初に単一GPIO（GPIO2）での点滅プログラムを作成
2. 要求に応じて全GPIOピンでの同時点滅に拡張

## 注意事項
- GPIO0とGPIO1はブート時に特別な機能を持つため注意が必要
- GPIO20とGPIO21は通常I2C（SDA/SCL）として使用される
- LEDを接続する場合は適切な電流制限抵抗を使用すること
