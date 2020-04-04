from ctypes import *
from numpy.ctypeslib import ndpointer

lib = CDLL('./libfunc.dll')

lib.getarray.argtypes = [POINTER(c_ubyte), c_int32]
lib.getarray.restype = POINTER(c_ubyte)
#lib.getarray.restype = ndpointer(dtype=c_ubyte, shape=(10,))

lib.free_mem.argtypes = [POINTER(c_ubyte)]
lib.free_mem.restype = None

a = (c_ubyte*3)(*[0xFA,0xCE,0x42])
