#include <kinetis.h>
#include <stdlib.h>

#include <FreeRTOS.h>
#include <task.h>

// extern tasks declared elsewhere in program
void LEDTask(void* args);
void SerialTask(void* args);

int main() {
  // create the tasks
  xTaskCreate(LEDTask, "LT", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  xTaskCreate(SerialTask, "ST", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

  // start scheduler, main should stop functioning here
  vTaskStartScheduler();

  for(;;);

  return 0;
}

// FreeRTOS malloc port function
void* pvPortMalloc(size_t size) {
  return malloc(size);
}

// FreeRTOS free port function
void vPortFree(void* ptr) {
  free(ptr);
}
