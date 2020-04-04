
client: client.c hexdump.c libfunc.dll
	gcc -o client client.c hexdump.c -L. -lfunc

libfunc.dll:
	g++ -shared -o libfunc.dll func.cpp hexdump.c

test1:
	./client 

test2:
	python3 client.py

clean:
	@rm client.exe libfunc.dll

.PHONY: clean
