#include <stdio.h>

struct SomeStructure {
    int count;
    char c;
    char* msg;
};

double someFunction(struct SomeStructure* s)
{
    printf("\n---- C receive these values -----------\n");
    printf("int = %d, char = %c, string = %s\n", s->count, s->c, s->msg);
    s->msg = "goodbye";
    printf("---------- end C ----------\n");
    return 42;
}
