#include <kinetis.h>
//#include <FreeRTOS.h>

#include <core_pins.h>
#include <usb_serial.h>

int LED_CONFIG = 0x00000102;
int LED_MASK   = 0x00000020;

int main() {
  // setup
  PORTC_PCR5 = LED_CONFIG;
  GPIOC_PDDR |= LED_MASK;

  Serial.begin(9600);

  // loop forever
  int counter = 0;
  for(;;) {
    if (counter++ % 2) {
      GPIOC_PDOR |= LED_MASK;
    } else {
      GPIOC_PDOR &= ~LED_MASK;
    }

    Serial.println("Hello World");

    // delay for some fixed time
    for(int i=0; i < 2500000; i++);
  }

  return 0;
}
