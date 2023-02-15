#include <Arduino.h>
#include <bits/stdc++.h>
#include <hardware/gpio.h>
#include "hardware/pio.h"
#include <strings.h>

//#include <TFT_eSPI.h>
//#include <XPT2046_Touchscreen.h>

#include "globals.h"
#include "lv_helper.h"

//TFT_eSPI tft = TFT_eSPI();
//XPT2046_Touchscreen ts(TOUCH_CS, TFT_IRQ);

bool toggle = false;
bool toggle2 = false;
uint32_t atime = 0;
uint16_t debounce = 600;

void handleTouchInterrupt()
{  
    Serial.println("Interrupt2 ");
}

void callInterrupt2()
{
  digitalWrite(25, toggle2 ? LOW : HIGH);
  toggle2 = !toggle2;
  if ( (millis() - debounce) > atime){
//    handleTouchInterrupt();
    isTouched = true;
    atime = millis();
  }
  delay(50);
}

void setup()
{
  Serial.begin(115200);

  gpio_init(15);
  gpio_set_drive_strength(15, GPIO_DRIVE_STRENGTH_8MA);
  gpio_set_dir(15, GPIO_OUT);
  delay(2000);

  lh_init(DISPLAY_PORTRAIT_FLIP);

  lv_obj_t* slider = lv_slider_create(lv_scr_act());
  lv_obj_align(slider, LV_ALIGN_CENTER, 0, 0);
  
  //SPI.usingInterrupt(digitalPinToInterrupt(TFT_IRQ));
  //attachInterrupt(digitalPinToInterrupt(TFT_IRQ), callInterrupt2, LOW);
}

void loop()
{
  lv_timer_handler();
  //gpio_put(15, toggle);
  //toggle = !toggle;
  delay(5);
}
