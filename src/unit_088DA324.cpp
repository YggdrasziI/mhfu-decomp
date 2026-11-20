/* unit_088DA324: 0x088DA324-0x088DA940 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088DA2C4 and unit_088DA940.
 *
 * func_088DA324 tells whether the state pair at +0x298 / +0x299 is one of
 * seven. func_088DA398 returns one value of the first item (type at +0x4E9,
 * id at +0x4EA; 0x18-byte records at 0x08959FD8 for type 5, 0x1C-byte
 * records at 0x08960B9C otherwise) chosen by `arg1`, with the factors of
 * func_088DA740 or, for 8, the state bonuses.
 *
 * C++: bool conversions, an inline test of the object id against the
 * global one. Optimized for speed (float constants as immediates).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" {

extern char *D_089CC438;

/* Fields of the 0x18-byte records at 0x08959FD8 and of the 0x1C-byte
 * records at 0x08960B9C (one symbol per field in the original code). */
extern s8 D_08959FD9[];
extern u8 D_08959FDA[];
extern u8 D_08959FDB[];
extern u8 D_08959FDC[];
extern u8 D_08959FDD[];
extern s8 D_08960BA9[];
extern u8 D_08960BAD[];
extern u8 D_08960BAE[];

extern s32 func_088D6A1C(char *, u8);
extern s32 func_088D6A54(char *, u8);
extern s32 func_088DAE98(char *, s32);

s16 func_088DA740(char *arg0, u16 arg1, s16 arg2);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

s32 func_088DA324(char *arg0, char *arg1) {
    if (*(u8 *)(arg1 + 0x298) == 0 && (*(u8 *)(arg1 + 0x299) == 0x27 || *(u8 *)(arg1 + 0x299) == 0x28 || *(u8 *)(arg1 + 0x299) == 0x29 || *(u8 *)(arg1 + 0x299) == 0x2A || *(u8 *)(arg1 + 0x299) == 0x2B || (u32) (*(u8 *)(arg1 + 0x299) - 0x77) < 2)) {
        return 1;
    }
    return 0;
}

s16 func_088DA398(char *arg0, u8 arg1) {
    u8 kind;
    u8 type;
    u8 elem;
    u8 power;
    u8 elem_val;
    s8 base;
    u16 flag;
    s16 v;
    s16 val;

    kind = *(u8 *)(arg0 + 0x4E9);
    val = 0;
    flag = 0;
    if (kind == 5) {
        type = D_08959FDA[*(u16 *)(arg0 + 0x4EA) * 0x18];
        elem = D_08959FDC[*(u16 *)(arg0 + 0x4EA) * 0x18];
        power = D_08959FDB[*(u16 *)(arg0 + 0x4EA) * 0x18];
        elem_val = D_08959FDD[*(u16 *)(arg0 + 0x4EA) * 0x18];
        base = D_08959FD9[*(u16 *)(arg0 + 0x4EA) * 0x18];
    } else {

        type = D_08960BAD[*(u16 *)(arg0 + 0x4EA) * 0x1C];
        elem = 0;
        power = D_08960BAE[*(u16 *)(arg0 + 0x4EA) * 0x1C];
        elem_val = 0;
        base = D_08960BA9[*(u16 *)(arg0 + 0x4EA) * 0x1C];

    }
    switch (arg1) {
    case 0:
        if (type == 1) {
            val = power;
            flag = 0x10;
        }
        break;
    case 1:
        if (type == 2) {
            val = power;
            flag = 0x20;
        }
        break;
    case 2:
        if (type == 3) {
            val = power;
            flag = 0x40;
        }
        break;
    case 3:
        if (type == 4) {
            val = power;
            flag = 0x100;
        }
        break;
    case 4:
        if (kind == 5 && elem == 1) {
            val = elem_val;
            flag = 2;
        }
        break;
    case 5:
        if (kind == 5 && elem == 2) {
            val = elem_val;
            flag = 4;
        }
        break;
    case 6:
        if (kind == 5 && elem == 3) {
            val = elem_val;
            flag = 1;
        }
        break;
    case 7:
        if (type == 5) {
            val = power;
            flag = 0x80;
        }
        break;
    case 8:
        v = base;
        if ((u8) func_088D6A1C(arg0, 0x20) == 1) {
            v += 10;
        } else if ((u8) func_088D6A1C(arg0, 0x21) == 1) {
            v += 20;
        } else if ((u8) func_088D6A1C(arg0, 0x22) == 1) {
            v += 30;
        } else if ((u8) func_088D6A1C(arg0, 0x23) == 1) {
            v -= 5;
        } else if ((u8) func_088D6A1C(arg0, 0x24) == 1) {
            v -= 10;
        } else if ((u8) func_088D6A1C(arg0, 0x25) == 1) {
            v -= 15;
        }
        if (v > 0) {
            if (*(u8 *)(arg0 + 0x4E9) == 5) {
                switch (*(u8 *)(arg0 + 0x5F2)) {
                case 0:
                case 1:
                case 2:
                case 3:
                    break;
                case 4:
                    v += 5;
                    break;
                case 5:
                case 6:
                    v += 10;
                    break;
                }
            }
        }
        return v;
    }
    if (val > 0) {
        if (flag != 0) {
            val = func_088DA740(arg0, flag, val);
        }
    }
    return val;
}

s16 func_088DA740(char *arg0, u16 arg1, s16 arg2) {
    if (arg2 > 0) {
        if (arg1 & 7) {
            if ((u8) func_088D6A1C(arg0, 0x43) == 1) {
                arg2 = 1.125f * arg2;
            }
            if ((u8) func_088D6A54(arg0, 9) == 1) {
                arg2 = 1.125f * arg2;
            }
        }
        if (arg1 & 0x1F0) {
            if ((u8) func_088D6A1C(arg0, 0x44) == 1) {
                arg2 = 1.2f * arg2;
            }
            if ((u8) func_088DAE98(arg0, 0x2000) == 1) {
                if (is_own(arg0) == 1) {
                    if (*(u8 *)(arg0 + 0x606) == 1) {
                        arg2 = 1.15f * arg2;
                    } else {
                        arg2 = 1.2f * arg2;
                    }
                } else {
                    if ((bool) (*(s32 *)(arg0 + 0x614) & 0x80000) == 0) {
                        arg2 = 1.15f * arg2;
                    } else {
                        arg2 = 1.2f * arg2;
                    }
                }
            }
        }
    }
    return arg2;
}

}
