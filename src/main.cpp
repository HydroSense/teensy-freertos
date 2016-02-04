#include <kinetis.h>
#include <stdlib.h>

#include <FreeRTOS.h>
#include <task.h>

void LEDTask(void* args);
void SerialTask(void* args);

int aLED_CONFIG = 0x00000102;
int aLED_MASK   = 0x00000020;

#define STACK_SIZE 10000

int main() {
  //Serial.begin(9600);

  //Serial.println("Starting main task");

  // configure the tasks
  //Serial.println("Creating serial task");
  PORTC_PCR5 = aLED_CONFIG;
  GPIOC_PDDR |= aLED_MASK;
  GPIOC_PDOR |= aLED_MASK;

  //xTaskCreate(SerialTask, "ST", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, NULL);
  xTaskCreate(LEDTask, "LT", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

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
