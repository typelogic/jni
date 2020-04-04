#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char* getarray(unsigned char* data, int data_len);
void free_mem(unsigned char* buf);
void hexdump(const void* data, int size);

int main(int argc, char*argv[])
{
    unsigned char buf[] = { 0xFA, 0xCE, 0x42 };
    unsigned char* result = getarray(buf,3);
    printf("C got address = %p\n",result);
    int len = result[0] >> 24 | result[1] >> 16 | result[2] >> 8 | result[0];

    printf("\n-------- %d ----------\n",len);
    hexdump(result, len);

    free_mem(result);

    return 0;
}
