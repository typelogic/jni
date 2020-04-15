from ctypes import *

lib = CDLL('./libexample.dll')

class SomeStructure (Structure):
    _fields_ = [
            ('count', c_int),
            ('c', c_char),
            ('msg', c_char_p)]

lib.someFunction.argtypes = [ POINTER(SomeStructure) ]
lib.someFunction.restype = c_double

#my_string = "hello world"
#s_obj = SomeStructure(3, c_char('q'.encode('utf-8')), c_char_p(my_string.encode('utf-8')))

my_string = b"hello world"
s_obj = SomeStructure(3, c_char(b'q'), c_char_p(my_string))
result = lib.someFunction(byref(s_obj))
print("result: %s, new value is %s" % (result,str(s_obj.msg))) 
