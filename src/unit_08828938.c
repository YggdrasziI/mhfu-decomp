/* unit_08828938: 0x08828938-0x08828EEC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Its jump table (0x08930B10-0x08930B2C) is linked from this unit.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern u8 func_08830728(char *, s8, s16, s16);
extern u8 func_08823AE4(char *, u8);
extern void func_0881C098(char *, char *, u16, s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s16 func_08826734(char *, u8);
extern void func_0881C520(char *, u16, s32);
extern void func_088D839C(char *, s32);
extern s32 func_088D72A4(char *, u16, s16, s32);
extern void func_088D8900(char *);
extern void func_0881C1C8(char *, char *, s32);

s32 func_08828938(char *arg0, u16 arg1) {
    s8 t;

    switch (*(u8 *)(arg0 + 0x52F)) {
    case 0:
        if (*(s16 *)(arg0 + 0x119E) != 0) {
            *(s16 *)(arg0 + 0x119E) -= 1;
        }
        return 0;
    case 1:
        if (*(u8 *)(arg0 + 0x58D) == 0xFF) {
            *(u8 *)(arg0 + 0x58D) = func_08830728(arg0, 1, 0, *(s16 *)(arg0 + 0x590));
            *(s8 *)(arg0 + 0x592) = -1;
        } else {
            if (*(u8 *)(arg0 + 0x58D) == *(u8 *)(D_089CC438 + 0x381)) {
                *(u8 *)(arg0 + 0x52F) += 1;
                *(s8 *)(arg0 + 0x592) = 4;
                *(s32 *)(arg0 + 0x528) |= 0x100;
                return 1;
            }
            if (func_08823AE4(arg0, *(u8 *)(arg0 + 0x58D)) == 0) {
                *(u8 *)(arg0 + 0x52F) += 1;
                *(s8 *)(arg0 + 0x592) = 0;
                *(s32 *)(arg0 + 0x528) |= 0x100;
                return 1;
            }
            return 1;
        }
        return 0;
    case 2:
        *(s8 *)(arg0 + 0x594) = 0;
        *(u8 *)(arg0 + 0x58C) = 0;
        *(s32 *)(arg0 + 0x528) &= ~0x800;
        *(u8 *)(arg0 + 0x52F) += 1;
    case 3:
        *(s8 *)(arg0 + 0x594) = (*(s8 *)(arg0 + 0x594) + 1) & 0x7F;
        if (*(s8 *)(arg0 + 0x594) < 0x40) {
            *(s16 *)(arg0 + 0x58E) = 0x14;
        } else {
            *(s16 *)(arg0 + 0x58E) = *(u16 *)(arg0 + 0x590) + 0x18;
        }
        func_0881C098(arg0, arg0 + 0x586, arg1 & 0xA0, 0x18);
        if (arg1 & 0x4000) {
            switch (*(u8 *)(arg0 + 0x58C)) {
            case 0:
                *(s16 *)(arg0 + 0x58E) = 0x15;
                *(u8 *)(arg0 + 0x5DA) = 0;
                *(u8 *)(arg0 + 0x52F) += 1;
                break;
            case 1:
                *(u8 *)(arg0 + 0x52F) = 6;
                break;
            }
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if (arg1 & 0x50) {
            *(u8 *)(arg0 + 0x58C) = (*(u8 *)(arg0 + 0x58C) + 1) & 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 4:
        if (*(u8 *)(arg0 + 0x5DA) != 0) {
            if (arg1 & 0xA000) {
                *(u8 *)(arg0 + 0x5DA) = 0;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
            arg1 &= 0xDFFF;
        } else if (arg1 & 0x8000) {
            *(u8 *)(arg0 + 0x5DA) = 1;
            func_08883988(D_08A62D8C, 0, 9, 0, 0, 0, 0, 0, 0);
        }
        func_0881C098(arg0, arg0 + 0x586, arg1, 0x18);
        if (arg1 & 0x4000) {
            *(s16 *)(arg0 + 0x58E) = 0x16;
            *(u8 *)(arg0 + 0x5DA) = 0;
            *(u8 *)(arg0 + 0x537) = 1;
            *(u8 *)(arg0 + 0x52F) += 1;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if (arg1 & 0x2000) {
            *(s16 *)(arg0 + 0x58E) = 0x14;
            *(s8 *)(arg0 + 0x594) = 0;
            *(u8 *)(arg0 + 0x52F) = 3;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (*(u8 *)(arg0 + 0x5DA) == 0) {
            *(s16 *)(arg0 + 0x58E) = 0x15;
        } else {
            *(s16 *)(arg0 + 0x58E) = func_08826734(arg0, *(u8 *)(arg0 + 0x586)) + 0x18;
        }
        break;
    case 5:
        *(s16 *)(arg0 + 0x58E) = 0x16;
        func_0881C520(arg0, arg1, 0x50);
        if (arg1 & 0x4000) {
            if (*(u8 *)(arg0 + 0x537) == 0) {
                func_088D839C(*(char **)(arg0 + 0x530), *(u8 *)(arg0 + 0x586));
                func_088D72A4(*(char **)(arg0 + 0x530), *(u16 *)(arg0 + 0x590), *(s8 *)(arg0 + 0x593), 0);
                if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
                    func_088D8900(*(char **)(arg0 + 0x530));
                }
                *(u8 *)(arg0 + 0x52F) = 6;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                *(u8 *)(arg0 + 0x52F) = 4;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            }
        } else if (arg1 & 0x2000) {
            *(u8 *)(arg0 + 0x52F) = 4;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 6:
        func_0881C1C8(arg0, arg0 + 0x586, 0);
        *(u8 *)(arg0 + 0x52F) = 0;
        *(s16 *)(arg0 + 0x590) = 0;
        if (*(u8 *)(arg0 + 0x52D) != 0 && *(u8 *)(arg0 + 0x57D) == 0) {
            *(s32 *)(arg0 + 0x5E8) |= 4;
        } else {
            *(s32 *)(arg0 + 0x528) &= ~0x100;
            *(s32 *)(arg0 + 0x5E8) &= ~4;
        }
        return 0;
    }
    t = *(s8 *)(arg0 + 0x592);
    if (t >= 0) {
        if (t > 0) {
            *(s8 *)(arg0 + 0x592) = t - 1;
        }
        if (*(u8 *)(arg0 + 0x58D) != *(u8 *)(D_089CC438 + 0x381)) {
            *(s8 *)(arg0 + 0x592) = -1;
        }
    }
    return 1;
}
