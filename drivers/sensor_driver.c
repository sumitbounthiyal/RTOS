#include"sensor_driver.h"

static int sensor_value = 0;

int sensor_read(void)
{
	sensor_value+=10;

	return sensor_value;
}
