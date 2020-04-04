# Python / C Interaction

In Cygwin, the library must have `*.dll` extension. 

The function type definitions are a must in `client.py`. 
We declare the input param and output type of two functions:
- getarray
- free_mem

The length-prefix 4-bytes header in the returned array from C is also a must. 
Python cannot parse the returned array without this length.

As verification, I printed the pointer memory address in the needed 
checkpoint places to verify the memory is clean-up correctly.

The use of `numpy` in python has been suggested to ease the operation. 
But it is important to be able handle first purely in python core library.
