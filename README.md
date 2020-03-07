The Java 8 enhancement https://openjdk.java.net/jeps/178 is meant for the JVM. 

Given two files:
- Main.java
- Main.c

Create libnative.so:
```
javac Main.java 
javah Main
gcc -c Main.c
gcc -c Main.c -I /home/dx/.sdkman/candidates/java/current/include/linux -I /home/dx/.sdkman/candidates/java/current/include
gcc -shared -o libnative.so Main.o 
 ```
Create libnative.a:
```
ar -cvq native.a Main.o
```

For each libnative.a, libnative.so test run via:
```
java -Djava.library.path=.  Main
```

This proves that *178* is for the JVM. 

Result:
- Success execution when `libnative.so` 
- Fail execution when `libnative.a`

References:
- https://github.com/java-native-access/jna/issues/387
