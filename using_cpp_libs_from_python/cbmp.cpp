#include <iostream>
#include "../cpp-bmp-images/BMP.h"
#include "cbmp.h"

# if !defined ON_ERROR_EXIT
    // Error utility macro
    #define ON_ERROR_EXIT(p, message) \
    do { \
        if((p)) { \
            std::cerr << "Error in function: " << __func__ << " at line: " << __LINE__ << '\n'; \
            std::cerr << message << '\n'; \
            std::exit(1); \
        } \
    } while(0)
#endif

CBMP *BMP_read(const char *fname)
try {
    CBMP *cbmp = new CBMP();
    ON_ERROR_EXIT(!cbmp, "Unable to allocate memory.");

    BMP *bmp = new BMP(fname);
    ON_ERROR_EXIT(!bmp, "Unable to allocate memory.");

    cbmp->handle = bmp;

    cbmp->width = bmp->bmp_info_header.width;
    cbmp->height = bmp->bmp_info_header.height;
    cbmp->channels = bmp->bmp_info_header.bit_count / 8;

    return cbmp;
} catch(const std::exception &e) {
    std::cerr << "Error in function: " << __func__ << " at line: " << __LINE__ << '\n';
    std::cerr << e.what() <<'\n';
    std::exit(1);
}

CBMP *BMP_create(int32_t width, int32_t height, bool has_alpha)
try {
    CBMP *cbmp = new CBMP();
    ON_ERROR_EXIT(!cbmp, "Unable to allocate memory.");

    BMP *bmp = new BMP(width, height, has_alpha);
    ON_ERROR_EXIT(!bmp, "Unable to allocate memory.");

    cbmp->handle = bmp;

    cbmp->width = bmp->bmp_info_header.width;
    cbmp->height = bmp->bmp_info_header.height;
    cbmp->channels = bmp->bmp_info_header.bit_count / 8;

    return cbmp;
} catch(const std::exception &e) {
    std::cerr << "Error in function: " << __func__ << " at line: " << __LINE__ << '\n';
    std::cerr << e.what() <<'\n';
    std::exit(1);
}

void BMP_destroy(CBMP *cbmp)
try {
    if(cbmp && cbmp->handle) {
        BMP *bmp = (BMP *)cbmp->handle;
        delete bmp;
        delete cbmp;
    } else {
        ON_ERROR_EXIT(-1, "");
    }
} catch(const std::exception &e) {
    std::cerr << "Error in function: " << __func__ << " at line: " << __LINE__ << '\n';
    std::cerr << e.what() <<'\n';
    std::exit(1);
}

void BMP_write(CBMP *cbmp, const char *fname)
try {
    if(cbmp && cbmp->handle) {
        BMP *bmp = (BMP *)cbmp->handle;
        bmp->write(fname);
    } else {
        ON_ERROR_EXIT(-1, "");
    }
} catch(const std::exception &e) {
    std::cerr << "Error in function: " << __func__ << " at line: " << __LINE__ << '\n';
    std::cerr << e.what() <<'\n';
    std::exit(1);
}

uint8_t *BMP_pixels(CBMP *cbmp)
try {
    BMP *bmp;
    if(cbmp && cbmp->handle) {
        bmp = (BMP *)cbmp->handle;
    } else {
        ON_ERROR_EXIT(-1, "");
    }

    return bmp->data.data();
} catch(const std::exception &e) {
    std::cerr << "Error in function: " << __func__ << " at line: " << __LINE__ << '\n';
    std::cerr << e.what() <<'\n';
    std::exit(1);
}

void BMP_fill_region(CBMP *cbmp, uint32_t x0, uint32_t y0, uint32_t w, uint32_t h, uint8_t B, uint8_t G, uint8_t R, uint8_t A)
try {
    if(cbmp && cbmp->handle) {
        BMP *bmp = (BMP *)cbmp->handle;
        bmp->fill_region(x0, y0, w, h, B, G, R, A);
    } else {
        ON_ERROR_EXIT(-1, "");
    }
} catch(const std::exception &e) {
    std::cerr << "Error in function: " << __func__ << " at line: " << __LINE__ << '\n';
    std::cerr << e.what() <<'\n';
    std::exit(1);
}
