import cbmp
import ctypes

# Read a BMP image with transparency, draw two rectangles on it, save it and release the object
img = cbmp.BMP_read(b"../cpp-bmp-images/Shapes.bmp")
cbmp.BMP_fill_region(img, 0, 0, 100, 200, 0, 0, 255, 255)
cbmp.BMP_fill_region(img, 150, 0, 209, 203, 0, 255, 0, 255)
cbmp.BMP_write(img, b"Shapes_copy.bmp")
cbmp.BMP_destroy(img)

# Read an RGB BMP image, draw two rectangles on it, save it and release the object
img = cbmp.BMP_read(b"../cpp-bmp-images/Shapes_24.bmp")
cbmp.BMP_fill_region(img, 0, 0, 100, 200, 0, 0, 255, 255)
cbmp.BMP_fill_region(img, 150, 0, 209, 203, 0, 255, 0, 255)
cbmp.BMP_write(img, b"Shapes_24_copy.bmp")
cbmp.BMP_destroy(img)

# Create a 4 channels image in memory, save it empty, draw one rectangle,
# save it agaian, release the object memory
img = cbmp.BMP_create(600, 600, True)
cbmp.BMP_write(img, b"create_empty_32.bmp")
cbmp.BMP_fill_region(img, 100, 100, 200, 300, 99, 75, 180, 200)
cbmp.BMP_write(img, b"create_rect_32.bmp")
cbmp.BMP_destroy(img)

# Create a 3 channels image in memory, get a handle to the raw pixel data
# modify the pixels in Python by creating a colored rectangle,
# write the image to disk.
img = cbmp.BMP_create(500, 500, False)
img_pixels = cbmp.BMP_pixels(img)
print(img.contents.width, img.contents.height, img.contents.channels)
channels = img.contents.channels
for y in range(img.contents.height//2):
    for x in range(img.contents.width//2):
        indx = channels * (y * img.contents.width + x)
        img_pixels[indx + 0] = 150  # Blue
        img_pixels[indx + 1] = 50   # Green
        img_pixels[indx + 2] = 200  # Red
        if channels == 4:
            img_pixels[indx + 3] = 255  # Alpha

cbmp.BMP_write(img, b"create_rect_24.bmp")
cbmp.BMP_destroy(img)
