#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "tasks.h"
	
//Queue handle
QueueHandle_t sensorQueue;
QueueHandle_t alertQueue;
QueueHandle_t logQueue;


void app_main ()
{

	sensorQueue = xQueueCreate(5, sizeof(int));
	alertQueue = xQueueCreate(5, sizeof(int));	
	logQueue = xQueueCreate(5, sizeof(int));	
	start_task();

}

