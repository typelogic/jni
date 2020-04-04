/* Cygwin must be in .dll extension
g++ -shared -o libarray.dll array.cpp */

#include <cstdlib>
#include <iostream>

void hexdump(const void* data, int size);

extern "C" unsigned char* getarray(unsigned char* data, int data_len)
{
    srand(time(0));
    int n = rand() % 100 + 1;
    int total = 4 + n + data_len;
    unsigned char* buf = new unsigned char[total];
    std::cout << "C++ address = " << static_cast<void*>(buf) << std::endl;

    for (int i = 0; i < n; i++) {
        buf[4 + i] = i;
    }

    for (int i = 0; i < data_len; i++) {
        buf[4 + n + i] = data[i];
    }

    buf[0] = total;
    buf[1] = total >> 8;
    buf[2] = total >> 16;
    buf[3] = total >> 24;

    hexdump(buf, total);

    return buf;
}

extern "C" void free_mem(unsigned char* buf)
{
    std::cout << "DELETE C++ address = " << static_cast<void*>(buf) << std::endl
              << std::flush;
    delete[] buf;
}
