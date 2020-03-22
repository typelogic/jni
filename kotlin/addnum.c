#include "NativeSimple.h"

JNIEXPORT jint JNICALL Java_NativeSimple_addnum
  (JNIEnv *env, jobject thiz, jint a, jint b) {
    jint sum = a + b;
    return sum;
}

