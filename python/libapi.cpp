#include "hexdump.h"

#include <cstdlib>
#include <iostream>
#include <vector>

struct Context {
    unsigned char encryption_key[32];
    unsigned char sign_key[16];
    unsigned char* verification_keys;
    int vklen;
    std::vector<unsigned char*> vMem;
};

extern "C" void* init(unsigned char* a,
                      int a_len,
                      unsigned char* b,
                      int b_len,
                      unsigned char* c,
                      int c_len)
{
    Context* context = new Context;
    std::cout << "C++ mem = " << static_cast<void*>(context) << std::endl;
    return static_cast<void*>(context);
}

extern "C" unsigned char* f(void* self, unsigned char* data, int data_len)
{
    Context* context = (Context*)self;

    srand(time(0));
    int n = rand() % 100 + 1;
    int total = 4 + n + data_len;

    unsigned char* buf = new unsigned char[total];
    context->vMem.push_back(buf);

    std::cout << "C++ new mem = " << static_cast<void*>(buf) << std::endl;

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

extern "C" void free_mem(void* self)
{
    Context* context = (Context*)self;

    for (auto& mem : context->vMem) {
        std::cout << "C++ free mem = " << static_cast<void*>(mem) << std::endl;
        delete mem;
    }

    std::cout << "C++ free mem = " << static_cast<void*>(self) << std::endl;
    delete context;
}
