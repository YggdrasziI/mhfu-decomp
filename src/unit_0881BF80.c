/* unit_0881BF80: 0x0881BF80-0x0881C098 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern s32 D_08A62D8C;
extern s32 func_0881C2E4(char *, u8 *, u16, u8);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0881BF80(char *arg0, u8 *arg1, u16 arg2, u8 arg3) {
    u8 half = arg3 >> 1;

    if (*arg1 < half) {
        func_0881C2E4(arg0, arg1, arg2, half);
    } else {
        *arg1 -= half;
        func_0881C2E4(arg0, arg1, arg2, half);
        *arg1 += half;
    }
    if (arg2 & 0xA0) {
        if (arg2 & 0x80) {
            if (*arg1 < half) {
                *arg1 += arg3;
            }
            *arg1 -= half;
        } else {
            *arg1 += half;
            if (*arg1 >= arg3) {
                *arg1 -= arg3;
            }
        }
        func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
    }
}
