
#include <kinetis.h>

#include <FreeRTOS.h>
#include <task.h>

int LED_CONFIG = 0x00000102;
int LED_MASK   = 0x00000020;
int counter = 0;

void LEDTask(void* args) {

  for(;;){
    if (counter++ % 2) {
      GPIOC_PDOR &= ~LED_MASK;
    } else {
      GPIOC_PDOR |= LED_MASK;
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
