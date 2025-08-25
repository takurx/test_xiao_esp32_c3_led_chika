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