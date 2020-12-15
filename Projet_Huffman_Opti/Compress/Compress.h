#ifndef COMPRESS_H_INCLUDED
#define COMPRESS_H_INCLUDED
#include "../Structure/Structure.h"
FILE* compress(FILE** dictio, FILE* text, Node** huff_t, Element** tab);

#endif // COMPRESS_H_INCLUDED
