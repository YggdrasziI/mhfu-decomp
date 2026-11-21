/* unit_088EF55C: 0x088EF55C-0x088EF9C8 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between a unit and code still in assembly.
 * They decode a JPEG image into a texture in a thread of its own, with the IJG
 * library (src/jpeg-6b).
 *
 * #pragma optimize_for_size off: func_088EF5EC has its three loops tested at
 * the bottom behind a guard; without the speed setting they jump to the test
 * (notes/COMPILER.md, "Speed and space").
 *
 * Offsets into the library's jpeg_decompress_struct (0x1B0 bytes): mem 0x4,
 * output_width 0x5C, output_height 0x60, output_components 0x68,
 * output_scanline 0x78.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

/* The source manager of the decoder (0x1C bytes, filled by func_088EF3E0)
 * followed by the request of the decoding thread. */
typedef struct {
    /* 0x00 */ char src[0x1C];
    /* 0x1C */ void *data;
    /* 0x20 */ s32 size;
    /* 0x24 */ u16 texWidth;
    /* 0x26 */ u16 texHeight;
    /* 0x28 */ u16 width;
    /* 0x2A */ u16 height;
    /* 0x2C */ void *texture;
} JpegRequest;

extern JpegRequest D_09A52184;
/* Follows the decoder's jpeg_error_mgr (D_09A520FC, 0x84 bytes). */
extern volatile s32 D_09A52180;
extern char D_089B7E88[];

extern void func_088EF3E0(char *);
extern void func_088EF4A8(char ***);
extern void jpeg_CreateDecompress(void *, s32, s32);
extern s32 jpeg_read_header(void *, s32);
extern s32 jpeg_start_decompress(void *);
extern u32 jpeg_read_scanlines(void *, u8 **, u32);
extern s32 jpeg_finish_decompress(void *);
extern void jpeg_destroy_decompress(void *);
extern void func_0890931C(void *);
extern u8 func_0890A310(void *, s32, s32, s32, s32, s32, s32);
extern u8 *func_089095FC(void *, s32, s32);
extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);
extern s32 sceKernelGetThreadExitStatus(s32);
extern s32 sceKernelDelayThread(u32);
extern s32 sceKernelDeleteThread(s32);
extern s32 sceKernelExitThread(s32);
extern void sceKernelDcacheWritebackAll(void);

s32 func_088EF55C(s32 arg0) {
    s32 size;
    if (arg0 != 0x20 && arg0 != 0x40 && arg0 != 0x80 && arg0 != 0x100 && arg0 != 0x200) {
        if (arg0 < 0x20) {
            size = 0x20;
        } else if (arg0 < 0x40) {
            size = 0x40;
        } else if (arg0 < 0x80) {
            size = 0x80;
        } else if (arg0 < 0x100) {
            size = 0x100;
        } else {
            size = 0x200;
        }
        return size;
    }
    return arg0;
}

void func_088EF5EC(char *cinfo, JpegRequest *req, u8 *dst) {
    u8 **rows;
    s32 y;
    s32 x;
    s32 offset;

    rows = (*(u8 **(**)(char *, s32, s32, s32))(*(char **)(cinfo + 4) + 8))(cinfo, 1, req->width * 3, 1);
    for (y = 0; y < req->texHeight; y++) {
        if (*(u32 *)(cinfo + 0x78) < *(u32 *)(cinfo + 0x60)) {
            jpeg_read_scanlines(cinfo, rows, 1);
            offset = 0;
            for (x = 0; x < req->texWidth; x++) {
                if (x < req->width) {
                    dst[0] = rows[0][offset];
                    dst[1] = rows[0][offset + 1];
                    dst[2] = rows[0][offset + 2];
                    offset += 3;
                    dst[3] = 0xFF;
                    dst += 4;
                } else {
                    dst[0] = 0;
                    dst[1] = 0;
                    dst[2] = 0;
                    dst[3] = 0xFF;
                    dst += 4;
                }
            }
        } else {
            for (x = 0; x < req->texWidth; x++) {
                dst[0] = 0;
                dst[1] = 0;
                dst[2] = 0;
                dst[3] = 0xFF;
                dst += 4;
            }
        }
    }
}

s32 func_088EF75C(s32 args, JpegRequest **argp) {
    char cinfo[0x1B0];
    JpegRequest *req;
    u8 *pixels;

    req = *argp;
    func_088EF4A8((char ***) cinfo);
    jpeg_CreateDecompress(cinfo, 62, 0x1B0);
    func_088EF3E0(cinfo);
    jpeg_read_header(cinfo, 1);
    jpeg_start_decompress(cinfo);
    req->width = *(s32 *)(cinfo + 0x5C);
    req->height = *(s32 *)(cinfo + 0x60);
    req->texWidth = func_088EF55C(*(s32 *)(cinfo + 0x5C));
    req->texHeight = func_088EF55C(*(s32 *)(cinfo + 0x60));
    if (*(s32 *)(cinfo + 0x68) != 3) {
        D_09A52180 = 3;
    } else {
        func_0890931C(req->texture);
        if (func_0890A310(req->texture, 3, req->texWidth, req->texHeight, 1, 1, 0) == 0) {
            D_09A52180 = 1;
        } else {
            pixels = func_089095FC(req->texture, 0, 0);
            if (pixels == 0) {
                D_09A52180 = 1;
            } else {
                func_088EF5EC(cinfo, req, pixels);
            }
        }
    }
    jpeg_finish_decompress(cinfo);
    jpeg_destroy_decompress(cinfo);
    sceKernelDcacheWritebackAll();
    sceKernelExitThread(D_09A52180);
    return D_09A52180;
}

s32 func_088EF894(void *texture, void *data, s32 size, u16 *width, u16 *height) {
    JpegRequest *req;
    s32 thread;
    s32 status;

    if (texture == 0) {
        return 0;
    }
    req = &D_09A52184;
    req->data = data;
    req->size = size;
    req->texture = texture;
    thread = sceKernelCreateThread(D_089B7E88, func_088EF75C, 0x20, 0x1000, 0, 0);
    if (thread <= 0) {
        return 0;
    }
    if (sceKernelStartThread(thread, 4, &req) != 0) {
        return 0;
    }
    while (1) {
        status = sceKernelGetThreadExitStatus(thread);
        if (status != (s32) 0x800201A2 && status != (s32) 0x800201A4) {
            break;
        }
        sceKernelDelayThread(1000);
    }
    sceKernelDeleteThread(thread);
    if (status != 0) {
        return -D_09A52180;
    }
    *width = req->width;
    *height = req->height;
    return 0;
}
