
appcpp: appcpp.cpp api.cpp hexdump.c libapi.dll
	g++ -o appcpp appcpp.cpp hexdump.c -L. -lapi -lpthread

app: app.c api.cpp hexdump.c libapi.dll
	gcc -o app app.c hexdump.c -L. -lapi

client: client.c hexdump.c libfunc.dll
	gcc -o client client.c hexdump.c -L. -lfunc

libfunc.dll: libfunc.cpp
	g++ -shared -o libfunc.dll libfunc.cpp hexdump.c

libapi.dll: libapi.cpp
	g++ -shared -o libapi.dll libapi.cpp hexdump.c

libexample.dll: libexample.c
	gcc -shared -o libexample.dll libexample.c

test1:
	./client 

test2:
	python3 client.py

clean:
	@rm -f *.exe *.dll *.o

.PHONY: clean
