#include <FreeRTOS.h>
#include <task.h>

void SerialTask(void* args) {
  // assume that serial has already been created
  for (;;) {
    vTaskDelay(500);
  }
}
