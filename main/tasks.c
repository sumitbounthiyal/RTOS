#include "tasks.h"


// Task 1 → Sender
void sensor_task(void *pvParameters) {
    int sensor_value = 0;

    while (1) {
        sensor_value = sensor_read();

        printf("Sensor Task: Sending value = %d\n", sensor_value);

        xQueueSend(sensorQueue, &sensor_value, portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
// Task 2 → Receiver
void processing_task(void *pvParameters) {
    int received_value = 0;

    while (1) {
        if (xQueueReceive(sensorQueue, &received_value, portMAX_DELAY)) {

            printf("Processing Task: Received value = %d\n", received_value);
	    int status;
            if (received_value < 50) {
		    status = 0;
                printf("Status: GOOD\n");
            } else if (received_value < 100) {
                printf("Status: MODERATE\n");
		status = 1;
            } else {
                printf("Status: BAD\n");
		status = 2;
            }
	    xQueueSend(alertQueue, &status, portMAX_DELAY);
        }
    }
}
void alert_task(void* pvParameters)
{
 int status = 0;
   while (1)
    {
        if (xQueueReceive(alertQueue, &status, portMAX_DELAY))
        {
            if (status == 0)
            {
                printf("ALERT: GREEN (GOOD)\n");
            }
            else if (status == 1)
            {
                printf("ALERT: YELLOW (MODERATE)\n");
            }
            else
            {
                printf("ALERT: RED (BAD) -> BUZZER ON\n");
            }
        }
    }
}

void logger_task(void *pvParameters)
{
    int status;

    while (1)
    {
        if (xQueueReceive(alertQueue, &status, portMAX_DELAY))
        {
            printf("LOGGER: Status logged = %d\n", status);
        }
    }
}


void start_task()
{

    xTaskCreate(sensor_task, "Sensor", 2048, NULL, 1, NULL);
    xTaskCreate(processing_task, "Processing", 2048, NULL, 1, NULL);
    xTaskCreate(alert_task, "Alart",2048,NULL,1,NULL);
    xTaskCreate(logger_task, "Logger", 2048, NULL, 1, NULL);
}
