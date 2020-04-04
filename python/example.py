from ctypes import *

lib = CDLL('./libexample.dll')

class SomeStructure (Structure):
    _fields_ = [
            ('i', c_int),
            ('c', c_char),
            ('s', c_char_p)
            ]

lib.someFunction.restype = c_double
lib.someFunction.argtypes = [ POINTER(SomeStructure) ]

my_string = "hello world"
s_obj = SomeStructure(3, c_char('q'.encode('utf-8')), c_char_p(my_string.encode('utf-8')))
result = lib.someFunction(byref(s_obj))
print("result: %s, new value is %s" % (result,str(s_obj.s))) 
