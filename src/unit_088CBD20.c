/* unit_088CBD20: 0x088CBD20-0x088CC0E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 *D_089CC000;

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_088CBD20(char *arg0) {
    u8 alpha;
    u32 col;
    u32 addr;

    if (*(s16 *)(arg0 + 0x3A0) == 0) {
        return;
    }
    *D_089CC000 = 0x1280011C;
    D_089CC000++;
    if (*(s16 *)(arg0 + 0x3A0) == 1) {
        alpha = 0xFF;
        *D_089CC000 = 0xE0FFFFFF;
        D_089CC000++;
        *D_089CC000 = 0xE1FFFFFF;
        D_089CC000++;
        *D_089CC000 = 0xDF0001AA;
        D_089CC000++;
    } else if (*(s16 *)(arg0 + 0x3A0) == 2) {
        alpha = 0xFF - (u8)(u32)(127.5f * *(s16 *)(arg0 + 0x3A2));
        col = alpha << 24;
        *(u32 *)(arg0 + 0x438) = col;
        *(u32 *)(arg0 + 0x42C) = col;
        addr = (u32)(arg0 + 0x42C);
        *D_089CC000 = ((addr & 0xFF000000) >> 8) | 0x10000000;
        D_089CC000++;
        *D_089CC000 = (addr & 0xFFFFFF) | 0x01000000;
        D_089CC000++;
        *D_089CC000 = 0x04060002;
        D_089CC000++;
        *D_089CC000 = 0xE0FFFFFF;
        D_089CC000++;
        *D_089CC000 = 0xE1FFFFFF;
        D_089CC000++;
        *D_089CC000 = 0xDF0001AA;
        D_089CC000++;
    } else {
        alpha = (u32)(255.0f * (1.0f + sin_vfpu(6.2831855f * (360.0f * (f32)(*(s16 *)(arg0 + 0x3A2) * 0xB6 + 0xC000) / 65536.0f / 360.0f))));
        *D_089CC000 = 0xDF000032;
        D_089CC000++;
    }
    if (*(s16 *)(arg0 + 0x3A0) == 1 || *(s16 *)(arg0 + 0x3A0) == 2) {
        col = 0xFFFFFFFF;
        *(u32 *)(arg0 + 0x420) = col;
        *(u32 *)(arg0 + 0x414) = col;
    } else {
        col = (alpha << 24) | 0xFFFFFF;
        *(u32 *)(arg0 + 0x420) = col;
        *(u32 *)(arg0 + 0x414) = col;
    }
    addr = (u32)(arg0 + 0x414);
    *D_089CC000 = ((addr & 0xFF000000) >> 8) | 0x10000000;
    D_089CC000++;
    *D_089CC000 = (addr & 0xFFFFFF) | 0x01000000;
    D_089CC000++;
    *D_089CC000 = 0x04060002;
    D_089CC000++;
    *D_089CC000 = 0xDF000032;
    D_089CC000++;
}
