from ctypes import *

lib = CDLL('./libfunc.dll')

lib.getarray.argtypes = [POINTER(c_ubyte), c_int32]
lib.getarray.restype = POINTER(c_ubyte)

lib.free_mem.argtypes = [POINTER(c_ubyte)]
lib.free_mem.restype = None

inputArray = [0xFA, 0xCE, 0xBA, 0xBE, 0x42]
#a = (c_ubyte*3)(*[6,6,6])
a = (c_ubyte*len(inputArray))(*inputArray)
res = lib.getarray(a,len(inputArray))
res_len = int.from_bytes(res[:4], byteorder='little')
arrvalue = res[4:res_len]
print("--------------------------------------------------")
print(' '.join('{:02X}'.format(x) for x in arrvalue))
print("--------------------------------------------------")
lib.free_mem(res)
