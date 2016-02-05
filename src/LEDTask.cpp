
#include <kinetis.h>

#include <FreeRTOS.h>
#include <task.h>

int LED_CONFIG = 0x00000102;
int LED_MASK   = 0x00000020;
int counter = 0;

#include <Arduino.h>

int ledPin = 13;

void LEDTask(void* args) {
  //PORTC_PCR5 = aLED_CONFIG;
  //GPIOC_PDDR |= aLED_MASK;
  //GPIOC_PDOR |= aLED_MASK;
  pinMode(ledPin, OUTPUT);

  for(;;){
    if (counter++ % 2) {
      digitalWrite(ledPin, LOW);
    } else {
      digitalWrite(ledPin, HIGH);
    }

    vTaskDelay(10);
  }

  /*
  // setup
  PORTC_PCR5 = LED_CONFIG;
  GPIOC_PDDR |= LED_MASK;

  for(;;) {
    if (counter++ % 2) {
      GPIOC_PDOR |= LED_MASK;
    } else {
      GPIOC_PDOR &= ~LED_MASK;
    }
  }
  */
}
