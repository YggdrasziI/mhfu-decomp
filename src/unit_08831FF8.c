/* unit_08831FF8: 0x08831FF8-0x08832204 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned char u8;

extern char *D_089CC438;
extern char *D_08A62D90;
extern char *D_08A62C50;
extern u16 func_088D72A4(char *, s32, s32, s32);
extern void func_088860A0(char *, s32);
extern s32 func_0885B21C(char *, s32);
extern u8 func_08830728(char *, s8, s16, s16);

s16 func_08831FF8(char *arg0, char *arg1, s32 arg2, s32 arg3, u8 arg4, s32 arg5) {
    u16 r;

    if (*(u8 *)(arg0 + 0x52F) != 0) {
        return -1;
    }
    if (*(s16 *)(arg0 + 0x119E) > 0 && (s16)arg3 != *(u16 *)(arg0 + 0x119C)) {
        return -1;
    }
    r = func_088D72A4(arg1, arg2, arg5, 0);
    *(s16 *)(arg0 + 0x590) = 0;
    switch (r) {
    case 0:
    case 1:
        if (arg4 & 2) {
            if (*(u16 *)(arg1 + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) {
                func_088860A0(D_08A62D90, arg2);
            }
        }
        if (arg4 & 1) {
            func_08830728(arg0, 1, 0, arg2);
        }
        break;
    case 2:
    case 3:
        if (arg4 & 1) {
            func_08830728(arg0, 1, 3, arg2);
        }
        break;
    case 5:
        if (func_0885B21C(D_08A62C50, arg2) != -1) {
            if (arg4 & 1) {
                func_08830728(arg0, 0, 12, 0);
            }
            return 5;
        }
        *(s16 *)(arg0 + 0x590) = arg2;
        *(u8 *)(arg0 + 0x52F) = 1;
        *(s16 *)(arg0 + 0x58E) = arg2;
        *(u8 *)(arg0 + 0x593) = arg5;
        if (arg4 & 2) {
            if (*(u16 *)(arg1 + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) {
                func_088860A0(D_08A62D90, arg2);
            }
        }
        *(u8 *)(arg0 + 0x58D) = 0xFF;
        break;
    }
    return r;
}
