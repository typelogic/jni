This instructions are for cygwin.

### Simple App

Compile:
```
kotlinc Hello.kt
```

Run:
```
kotlin HelloKt
```

### Complex App

For more complex app, need to create a jar then run the jar.

```
kotlinc NativeSimple.kt
javah NativeSimple
```

Create `addnum.dll` take note of `-D`:
```
gcc -D__int64=int64_t -shared -o addnum.dll \
    -I /cygdrive/c/Program\ Files/Java/jdk1.8.0_231/include \
    -I /cygdrive/c/Program\ Files/Java/jdk1.8.0_231/include/win32 \
    addnum.c
```

Must create a **JAR** coz the app is complex. 
```
kotlinc -include-runtime -d NativeSimple.jar Main.kt NativeSimple.kt
```

Run app:
```
java -jar NativeSimple.jar
```
