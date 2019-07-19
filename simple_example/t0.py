"""Simple example of loading and using the system C library from Python"""
import sys, platform
import ctypes, ctypes.util

# Get the path to the system C library
if platform.system() == "Windows":
    path_libc = ctypes.util.find_library("msvcrt")
else:
    path_libc = ctypes.util.find_library("c")

# Get a handle to the sytem C library
try:
    libc = ctypes.CDLL(path_libc)
except OSError:
    print("Unable to load the system C library")
    sys.exit()

print(f'Succesfully loaded the system C library from "{path_libc}"')

libc.puts(b"Hello from Python to C")

libc.printf(b"%s\n", b"Using the C printf function from Python ... ")

# Create a mutable string
mut_str = ctypes.create_string_buffer(10)

# Fill the first 5 elements with 'X':
libc.memset(mut_str, ctypes.c_char(b"X"), 5)

# Print the modified string
libc.puts(mut_str)

# Add 4 'O' to the string starting from position 6
p = ctypes.cast(ctypes.addressof(mut_str) + 5, ctypes.POINTER(ctypes.c_char))
libc.memset(p, ctypes.c_char(b"O"), 4)

# Print the modified string
libc.puts(mut_str)
