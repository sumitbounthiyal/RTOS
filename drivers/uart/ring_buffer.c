#include "ring_buffer.h"

static char buffer[BUFFER_SIZE];

static int head=0;
static int tail=0;

//initilised the buffer head and tail values to zero.
void buffer_init(void)
{
    head = 0;
    tail = 0;
}

bool buffer_write(char data)
{
	//If head equalto tail then %BUFFER_SIZE will make next to 0. 
	int next = (head+1)%BUFFER_SIZE;

	//Check if buffer is full
	if (next == tail)
	{
		return false;
	}
	//Copy data into buffer and increased the head value
	buffer[head] = data;
	
	head = next;

	return true;
}

bool buffer_read(char *data)
{
	// Check if buffer is empty)
	if (head == tail)
	{
		return false;
	}
	
	//Copy data from buffer and increased the tail value
	*data = buffer[tail];

	tail = (tail+1) % BUFFER_SIZE;

	return true;
}
