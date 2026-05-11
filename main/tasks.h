#ifndef TASKS_H
#define TASKS_H


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sensor_driver.h"

//Extern queue variable
extern QueueHandle_t sensorQueue;
extern QueueHandle_t alertQueue;

// Start Task
void start_task();

#endif
