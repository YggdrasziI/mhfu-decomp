/* unit_08827BF4: 0x08827BF4-0x0882822C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_08828524. Its jump table (0x08930A94-0x08930ABC) is linked from this
 * unit.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *D_08A62C54;
extern u8 D_08938694[];
extern u8 D_0893869C[];
extern u8 D_089386A4[];
extern u8 D_089386AC[];
extern u8 func_0885CD18(char *, u8, u16);
extern u8 func_0885CE1C(char *, u8);
extern char *func_0885CA50(char *, char *);
extern s32 func_0885F7D4(char *, char *);
extern u16 *func_0885F82C(char *, s32);
extern u32 func_088D7DE8(char *);
extern u8 func_088D6A1C(char *, s32);
extern u8 func_08828524(char *, char *, char *, u8);

s32 func_08827BF4(char *arg0, char *arg1, u8 arg2) {
    u8 kind;
    u8 a;
    u8 b;
    char *e;
    u8 flags;
    s32 f2;
    u8 *p;
    char *s;
    s32 v;
    u16 *q;
    u32 m;

    kind = arg1[arg2 + 0x634];
    a = func_0885CD18(D_08A62C54, arg1[0x4E9], *(u16 *)(arg1 + 0x4EA));
    b = func_0885CE1C(D_08A62C54, a);
    e = func_0885CA50(D_08A62C54, arg1 + 0x4E8);
    flags = b;
    f2 = flags & 2;
    if (f2 != 0) {
        for (p = D_08938694; *p != 0; p++) {
            if (*p == kind) {
                return 0;
            }
        }
        m = *(u32 *)(e + 0x18);
        if (a != 10) {
            for (p = D_089386A4; *p != 0; p++) {
                if (*p == kind) {
                    return 0;
                }
            }
            m |= func_088D7DE8(arg1);
            switch (kind) {
            case 0x16:
                if ((m & 7) == 0) {
                    return 0;
                }
                break;
            case 0x17:
                if ((m & 0x38) == 0) {
                    return 0;
                }
                break;
            case 0x18:
                if ((m & 0x1C0) == 0) {
                    return 0;
                }
                break;
            case 0x1F:
                if ((m & 0xF8000) == 0) {
                    return 0;
                }
                break;
            }
            if (kind == 0x15 && func_088D6A1C(arg1, 0xD9) == 1) {
                return 0;
            }
        } else {
            for (p = D_0893869C; *p != 0; p++) {
                if (*p == kind) {
                    return 0;
                }
            }
            switch (kind) {
            case 0x16:
            case 0x17:
            case 0x18:
                if (func_08828524(arg0, arg1, e, kind) == 0) {
                    return 0;
                }
                break;
            case 0x1F:
                if (*(u8 *)(e + 0x11) == 0) {
                    return 0;
                }
                break;
            }
        }
    } else {
        for (p = D_089386AC; *p != 0; p++) {
            if (*p == kind) {
                return 0;
            }
        }
        s = func_0885CA50(D_08A62C54, arg1 + 0x4E8);
        v = func_0885F7D4(D_08A62C54, arg1 + 0x4E8);
        if (v != -1) {
            q = func_0885F82C(D_08A62C54, v);
            if (q[1] & 7) {
                s[0x10] = q[2];
            } else {
                s[0xE] = q[2];
            }
            if (q[3] & 7) {
                s[0x10] = q[4];
            } else {
                s[0xE] = q[4];
            }
        }
        switch (kind) {
        case 0x1F:
            if (*(u8 *)(s + 0xE) == 0) {
                return 0;
            }
            break;
        }
    }
    if ((flags & 4) == 0) {
        switch (kind) {
        case 0x10:
            return 0;
        case 0x11:
        case 0x12:
            if (a != 1 || (*(u16 *)(arg1 + 0x4EC) & 0x80) == 0) {
                return 0;
            }
            break;
        }
    }
    if (kind == 0x42) {
        switch (a) {
        case 1:
        case 5:
        case 9:
            break;
        case 10:
            if (*(u8 *)(e + 0xB) == 4) {
                return 0;
            }
            break;
        default:
            return 0;
        }
    }
    if (kind == 0x62) {
        switch (a) {
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
            return 0;
        }
    }
    if ((u32)(kind - 2) < 4) {
        if (func_088D6A1C(arg1, 0xD0) == 1) {
            return 0;
        }
    }
    if (flags & 1) {
        if (kind == 0xC || kind == 0x23) {
            if (func_088D6A1C(arg1, 0xD1) == 1) {
                return 0;
            }
        }
    }
    if (f2 != 0) {
        if ((u32)(kind - 0x16) < 3) {
            if (func_088D6A1C(arg1, 0xD2) == 1) {
                return 0;
            }
        }
    }
    if (kind == 0x3F || kind == 0x57) {
        if (func_088D6A1C(arg1, 0xD3) == 1) {
            return 0;
        }
    }
    if (kind == 0x46 || kind == 0x2B) {
        if (func_088D6A1C(arg1, 0xD4) == 1) {
            return 0;
        }
    }
    if (kind == 0x32 || kind == 0x07) {
        if (func_088D6A1C(arg1, 0xD5) == 1) {
            return 0;
        }
    }
    if (kind == 0x27 || kind == 0x4B || kind == 0x05) {
        if (func_088D6A1C(arg1, 0xD6) == 1) {
            return 0;
        }
    }
    return 1;
}
