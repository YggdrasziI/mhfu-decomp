/* unit_0881C098: 0x0881C098-0x0881C1C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881C098: paged cursor update over pages of 8 entries. */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62D8C;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0881C2E4(char *, u8 *, s32, u8);

void func_0881C098(char *arg0, u8 *arg1, s32 arg2, u8 arg3) {
    u8 i;

    for (i = 0; ; i += 8) {
        if (*arg1 < i + 8) {
            *arg1 -= i;
            func_0881C2E4(arg0, arg1, arg2, 8);
            *arg1 += i;
            break;
        }
    }
    if (arg3 > 8 && ((u16)arg2 & 0xA0)) {
        if ((u16)arg2 & 0x80) {
            if (*arg1 < 8) {
                *arg1 += arg3;
            }
            *arg1 -= 8;
        } else {
            *arg1 += 8;
            if (*arg1 >= arg3) {
                *arg1 -= arg3;
            }
        }
        func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
    }
}
