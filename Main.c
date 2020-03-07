#include "Main.h"
#include <stdio.h>

JNIEXPORT jint JNICALL Java_Main_addnum(JNIEnv *env,
                                        jobject thiz,
                                        jint a,
                                        jint b)
{
    printf("hello\n");
    return a + b;
}
