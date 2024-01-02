#include "wt32_lv.h"
#include "wt32_wifi.h"
#include <Arduino.h>
#include <demos/lv_demos.h>

long check1s = 0;
long check5ms = 0;

void setup() {
  disable_speaker();
  Serial.begin(115200);
  init_wt32_lvgl();
  show_center_msg("Please Config WiFi With ESP-Touch!");
  autoConfigWifi();
  configTime(TZ_SEC, DST_SEC, "ntp.ntsc.ac.cn", "ntp1.aliyun.com");
  setupOTAConfig();
  lv_demo_widgets();
}

void loop() {
  auto ms = millis();
  if (ms - check1s > 1000) {
    check1s = ms;
    ArduinoOTA.handle();
  }
  if (ms - check5ms > 5) {
    check5ms = ms;
    lv_timer_handler();
  }
}