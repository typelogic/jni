#ifdef __cplusplus
extern "C" {
#endif

void* init(unsigned char* a, int, unsigned char* b, int, unsigned char* c, int);
unsigned char* f(void* self, unsigned char* data, int datalen);
void free_mem(void* self);

#ifdef __cplusplus
}
#endif
