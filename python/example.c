#include <stdio.h>

struct SomeStructure {
    int i;
    char c;
    char* s;
};

double someFunction(struct SomeStructure* s)
{
    printf("int = %d, char = %c, string = %s\n", s->i, s->c, s->s);
    s->s = "goodbye";
    return 42;
}
