/* unit_0884FCB0: 0x0884FCB0-0x0884FDC4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FCB0: returns a rank 1-8 from the first flag set among eight ids
 * (highest id first), tested with func_0884FE80.
 */

typedef int s32;
typedef unsigned char u8;

extern s32 func_0884FE80(char *, s32);

s32 func_0884FCB0(char *arg0) {
    if ((u8)func_0884FE80(arg0, 0xC9C) == 1) {
        return 8;
    }
    if ((u8)func_0884FE80(arg0, 0xC1F) == 1) {
        return 7;
    }
    if ((u8)func_0884FE80(arg0, 0xBC1) == 1) {
        return 6;
    }
    if ((u8)func_0884FE80(arg0, 0x899) == 1) {
        return 5;
    }
    if ((u8)func_0884FE80(arg0, 0x848) == 1) {
        return 4;
    }
    if ((u8)func_0884FE80(arg0, 0x4C2) == 1) {
        return 3;
    }
    if ((u8)func_0884FE80(arg0, 0x4B1) == 1) {
        return 2;
    }
    return (u8)func_0884FE80(arg0, 0x450) == 1;
}
