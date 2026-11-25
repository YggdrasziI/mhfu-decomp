/* unit_08849BCC: 0x08849BCC-0x08849CAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08849BCC */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_089CC438;
extern s32 D_08A62C7C;
extern char *D_08A62D8C;

extern u8 func_0884FA5C(s32, s32);
extern void func_0881C520(char *, s32, s32);
extern void func_0886A054(s32);
extern s32 func_08883988(char *, s32, s32, s32, s32, s32, s32, s32, u8);

s32 func_08849BCC(char *arg0, s32 arg1) {
    if (func_0884FA5C(D_089CC438, 0) == 1) {
        return 8;
    }
    if (*(u8 *)(arg0 + 0x1115) == 1) {
        return arg1;
    }
    if (*(u8 *)(arg0 + 0x57E) == 0) {
        func_0881C520(arg0, arg1, 0xA0);
        if ((u16)arg1 & 0x4000) {
            if (*(u8 *)(arg0 + 0x537) == 0) {
                func_0886A054(D_08A62C7C);
                *(u8 *)(arg0 + 0x57E) += 1;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                return 0;
            }
            return 0x2000;
        }
        return arg1;
    }
    return 0;
}
