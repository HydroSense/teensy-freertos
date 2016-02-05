#include <FreeRTOS.h>
#include <task.h>

#include <Arduino.h>


void SerialTask(void* args) {
  // initialize the serial
  Serial.begin(9600);

  for (;;) {
    Serial.println("Hello World");
    vTaskDelay(20);
  }
}
