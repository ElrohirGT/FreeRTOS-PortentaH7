#ifndef QTZ_LIB
#define QTZ_LIB

#include <stddef.h>
#include <stdint.h>


// Holds an array of bytes
typedef struct {
	// The pointer to the first element of the array.
  uint8_t *data;
	// The number of bytes this array contains with information.
	size_t length;
	// The number of bytes the data can hold.
  size_t capacity;
} QTZ_ByteArray;


#endif
