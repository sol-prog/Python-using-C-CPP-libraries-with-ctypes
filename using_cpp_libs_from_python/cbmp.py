""" Python wrapper for the C shared library cbmp"""
import sys, platform
import ctypes, ctypes.util

# Find the library and load it
cbmp_path = ctypes.util.find_library("./cbmp")
if not cbmp_path:
    print("Unable to find the specified library.")
    sys.exit()

try:
    cbmp = ctypes.CDLL(cbmp_path)
except OSError:
    print("Unable to load the system C library")
    sys.exit()


class CBMP(ctypes.Structure):
    _fields_ = [
        ('handle', ctypes.c_void_p),
        ('width', ctypes.c_int32),
        ('height', ctypes.c_int32),
        ('channels', ctypes.c_int32)
    ]

# Make the function names visible at the module level and add types
BMP_read = cbmp.BMP_read
BMP_read.argtypes = [ctypes.c_char_p]
BMP_read.restype = ctypes.POINTER(CBMP)

BMP_create = cbmp.BMP_create
BMP_create.argtypes = [ctypes.c_int32, ctypes.c_int32, ctypes.c_bool]
BMP_create.restype = ctypes.POINTER(CBMP)

BMP_destroy = cbmp.BMP_destroy
BMP_destroy.argtypes = [ctypes.POINTER(CBMP)]
BMP_destroy.restype = None

BMP_write = cbmp.BMP_write
BMP_write.argtypes = [ctypes.POINTER(CBMP), ctypes.c_char_p]
BMP_write.restype = None

BMP_pixels = cbmp.BMP_pixels
BMP_pixels.argtypes = [ctypes.POINTER(CBMP)]
BMP_pixels.restype = ctypes.POINTER(ctypes.c_uint8)

BMP_fill_region = cbmp.BMP_fill_region
BMP_fill_region.argtypes = [ctypes.POINTER(CBMP), ctypes.c_uint32, ctypes.c_uint32, ctypes.c_uint32, ctypes.c_uint32, ctypes.c_uint8, ctypes.c_uint8, ctypes.c_uint8, ctypes.c_uint8]
BMP_fill_region.restype = None
