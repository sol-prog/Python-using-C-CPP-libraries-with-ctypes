#pragma once

#ifdef __cplusplus
    #include <cstdint>
#else
    #include <stdint.h>
    #include <stdbool.h>
#endif

#ifdef _WIN32
    #ifdef BUILD_CBMP
        #define EXPORT_SYMBOL __declspec(dllexport)
    #else
        #define EXPORT_SYMBOL __declspec(dllimport)
    #endif
#else
    #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void *handle;
    int32_t width;
    int32_t height;
    int32_t channels;
} CBMP;

EXPORT_SYMBOL CBMP *BMP_read(const char *fname);
EXPORT_SYMBOL CBMP *BMP_create(int32_t width, int32_t height, bool has_alpha);
EXPORT_SYMBOL void BMP_destroy(CBMP *cbmp);

EXPORT_SYMBOL void BMP_write(CBMP *cbmp, const char *fname);
EXPORT_SYMBOL uint8_t *BMP_pixels(CBMP *cbmp);
EXPORT_SYMBOL void BMP_fill_region(CBMP *cbmp, uint32_t x0, uint32_t y0, uint32_t w, uint32_t h, uint8_t B, uint8_t G, uint8_t R, uint8_t A);

#ifdef __cplusplus
}
#endif
