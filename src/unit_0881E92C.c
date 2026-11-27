/* unit_0881E92C: 0x0881E92C-0x0881EAF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881E92C (ULES01213)
 *
 * Callee prototypes: func_0881C2E4 and func_088260D4 take a u16 third/second
 * parameter here (raw register passed, no mask before the call).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62D8C;
extern void func_0881C2E4(char *, u8 *, u16, u8);
extern s32 func_088262B0(char *);
extern s32 func_088291B4(char *, s8, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0882619C(char *, u16);
extern void func_088260D4(char *, u16);

u16 func_0881E92C(char *arg0, u16 arg1) {
    if (arg1 & 8) {
        return 8;
    }
    switch (*(u8 *)(arg0 + 0x57E)) {
    case 0:
        *(s32 *)(arg0 + 0x5E8) |= 4;
        if (arg1 & 0x2000) {
            break;
        }
        if (!(arg1 & 0x4000)) {
            func_0881C2E4(arg0, (u8 *)(arg0 + 0x57F), arg1, 3);
            *(s16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57F);
            break;
        }
        switch (*(u8 *)(arg0 + 0x57F)) {
        case 0:
            *(s16 *)(arg0 + 0x5C0) = 0;
            *(u8 *)(arg0 + 0x5C2) = 8;
            func_088262B0(arg0);
            break;
        case 1:
            *(s8 *)(arg0 + 0x5D9) = func_088291B4(arg0, *(s8 *)(arg0 + 0x5D9), 0);
            break;
        }
        *(s16 *)(arg0 + 0x1208) = 0;
        (*(u8 *)(arg0 + 0x57E))++;
        arg1 = 0;
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
    case 1:
        if (arg1 & 0x2000) {
            arg1 = 0;
            *(s32 *)(arg0 + 0x5E8) |= 4;
            *(u8 *)(arg0 + 0x5FE) = 2;
            *(s16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57F);
            *(u8 *)(arg0 + 0x57E) = 0;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            *(s32 *)(arg0 + 0x528) &= ~0x800;
        } else {
            *(s32 *)(arg0 + 0x5E8) &= ~4;
            switch (*(u8 *)(arg0 + 0x57F)) {
            case 0:
                func_0882619C(arg0, arg1);
                break;
            case 1:
                func_088260D4(arg0, arg1);
                break;
            }
        }
        break;
    }
    return arg1;
}
