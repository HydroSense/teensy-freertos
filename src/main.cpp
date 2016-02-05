#include <kinetis.h>
#include <stdlib.h>

#include <FreeRTOS.h>
#include <task.h>

#include <Arduino.h>
#include <usb_dev.h>

void LEDTask(void* args);
void SerialTask(void* args);

int main() {
  // initialize the USB stack
  usb_init();
  Serial.begin(9600);
  Serial.println("Starting main task");

  for(int i=0; i < 25000000; i++);
  //Serial.begin(9600);

  //Serial.println("Starting main task");

  // configure the tasks
  //Serial.println("Creating serial task");

  xTaskCreate(LEDTask, "LT", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  xTaskCreate(SerialTask, "ST", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

  vTaskStartScheduler();    // start scheduler

  for(;;) {
    //Serial.println("scheduler failed");
  }

  return 0;
}

void* pvPortMalloc(size_t size) {
  return malloc(size);
}

void vPortFree(void* ptr) {
  free(ptr);
}

/*
void vPortEnterCritical() {
  noInterrupts();
}

void vPortExitCritical() {
  interrupts();
}

void* pvPortMalloc(size_t size) {
  return malloc(size);
}

void vPortFree(void* ptr) {
  free(ptr);
}

// TODO(colin): not sure if this actually is needed for anything
void vPortValidateInterruptPriority() {
}

// TODO(colin): this is def not right
portSTACK_TYPE* pxPortInitialiseStack(portSTACK_TYPE* pxTopOfStack, pdTASK_CODE pxCode, void* pvParameters) {
}


BaseType_t xPortStartScheduler() {
}
*/
