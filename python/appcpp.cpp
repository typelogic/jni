#include "api.h"
#include "hexdump.h"

#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    unsigned char a[] = {0x11, 0x22};
    unsigned char b[] = {0x55, 0x66, 0x77};
    unsigned char c[] = {0xAA, 0xBB, 0xCC, 0xDD};

    void* context = init(a, b, c);
    printf("C caller got mem = %p\n", context);

    unsigned char* result = f(context, c, 4);
    int len = result[0] >> 24 | result[1] >> 16 | result[2] >> 8 | result[0];
    std::cout << "\n----- C -------\n";
    hexdump(result, len);
    free_mem(context);

    return 0;
}
