The Java 8 enhancement https://openjdk.java.net/jeps/178 is meant for the JVM. 

Given two files:
- Main.java
- Main.c

Create libnative.so:
```
javac Main.java 
javah Main
gcc -c Main.c -I /home/dx/.sdkman/candidates/java/current/include/linux -I /home/dx/.sdkman/candidates/java/current/include
gcc -shared -o libnative.so Main.o 
 ```
Create libnative.a:
```
ar -cvq libnative.a Main.o
```

For each libnative.a, libnative.so test run via:
```
java -Djava.library.path=.  Main
```

This proves that *178* is for the JVM. 

Result:
- Success execution when `libnative.so` 
- Fail execution when `libnative.a`

Replay link: https://asciinema.org/a/HTPWvr0WLyEL6iz3ahGUG1A63

### Java in Cygwin

Have to copy the jars and refer to it in  a relative way:

```
mkdir lib
cp ~/cooljars/bytes-1.3.0.jar lib
javac -cp lib/bytes-1.3.0.jar\;lib/others.jar dx/test/App.java
java -cp lib/bytes-1.3.0.jar\;lib/others.jar\;. dx.test.App
```

References:
- https://github.com/java-native-access/jna/issues/387
- https://github.com/typelogic/jni
