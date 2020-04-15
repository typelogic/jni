from ctypes import *

lib = CDLL('./libapi.dll')

###############################################################################
lib.init.argtypes = [
        POINTER(c_ubyte), 
        c_int,
        POINTER(c_ubyte), 
        c_int,
        POINTER(c_ubyte),
        c_int
        ]
lib.init.restype = c_void_p

lib.f.argtypes = [c_void_p, POINTER(c_ubyte), c_int32]
lib.f.restype = POINTER(c_ubyte)

lib.free_mem.argtypes = [c_void_p]
lib.free_mem.restype = None
###############################################################################

param1 = bytes([0x01, 0x02, 0x03])
param2 = bytes([0x04, 0x05, 0x06, 0x07])
param3 = [0xFA, 0xCE, 0x42]

context = lib.init(
        cast(param1,POINTER(c_ubyte)), len(param1), 
        cast(param2,POINTER(c_ubyte)), len(param2), 
        None, 0)

a = (c_ubyte * 3)(*[3,3,3])
res = lib.f(context, a, 3)
res_len = int.from_bytes(res[:4], byteorder='little')
arrvalue = res[4:res_len]

print("--------------------------------------------------")
print(' '.join('{:02X}'.format(x) for x in arrvalue))
print("--------------------------------------------------")

lib.free_mem(context)
