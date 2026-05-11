#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>

#define BUFFER_SIZE 8

void buffer_init(void);

bool buffer_write(char data);

bool buffer_read(char *data);

#endif
