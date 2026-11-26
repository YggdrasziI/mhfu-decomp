/* unit_0883BA38: 0x0883BA38-0x0883BB10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 func_0881C45C(char *, u8 *, s32, s32);
extern s32 func_0881C2E4(char *, u8 *, s32, s32);

s32 func_0883BA38(char *p, s32 a) {
    u8 lo;
    u8 hi;

    hi = (u32)*(u8 *)(p + 0x57F) >> 2;
    lo = (s32)*(u8 *)(p + 0x57F) % 4;
    if (func_0881C45C(p, &lo, a, 4) != 0) {
        *(u8 *)(p + 0x57F) = lo + hi * 4;
    } else if (func_0881C2E4(p, &hi, a, 3) != 0) {
        *(u8 *)(p + 0x57F) = lo + hi * 4;
    }
    if ((u16)a & 0x4000) {
        *(u8 *)(*(char **)(p + 0x530) + 0x565) = *(u8 *)(p + 0x57F) + 1;
    }
    return a;
}
