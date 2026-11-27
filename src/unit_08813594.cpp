/* unit_08813594: 0x08813594-0x08813B34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * The 0x43/0x57 case joins its call test and its table lookup in one `||`
 * guard before a `return;`: that shape keeps, for the whole function, the
 * dead copies of branch-likely slot instructions after each `b` and the
 * unmerged `b` of the inlined id helpers (same helpers as unit_088CC828).
 * In the 0x3A case the second func_08865CB8 call reuses a2 = 1 left by the
 * compare. C++ for the bool helpers.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern "C" {

extern char *D_08A62C7C;
extern char *D_089CC438;
extern char *D_089CBBEC;
extern u8 D_089383E0[];
extern u16 D_09CE4808[];
extern u16 D_09CE5008[];
extern u16 D_09CE5220[];

extern u8 func_08865CB8(char *, s32, s32);
extern u8 func_0884FC74(char *, u8);
extern s32 func_08813C8C(char *);
extern void func_08813DAC(char *);
extern s32 func_08813DD8(char *);
extern u8 func_08813E10(char *);
extern void func_08813560(char *, s32, char *, s32);

}

static inline bool is_plain(u16 id) {
    if (id == 0xFFFF) {
        return true;
    }
    return D_09CE5008[id] == 0;
}

static inline u16 map_id(u16 id) {
    u16 v;

    if (id == 0xFFFF) {
        return id;
    }
    v = D_09CE5220[id];
    return (v != 0xFFFF) ? v : id;
}

static inline u16 base_id(u16 id) {
    if (is_plain(id) == 1) {
        return id;
    }
    return map_id(id);
}

static inline u16 cur_id(char *g) {
    u16 id = *(u16 *)(g + 0x6AF0E);

    if (id == 0xFFFF) {
        return id;
    }
    return base_id(id);
}

extern "C" void func_08813594(char *arg0, s32 arg1) {
    char *g = D_08A62C7C;
    char *p;
    s32 r;
    u8 k;
    u8 id;
    s32 v;

    p = *(char **)(g + 0x24);
    if (p == 0) {
        p = *(char **)(g + 0x720);
        if (p == 0) {
            return;
        }
        k = *(u8 *)(p + 0x1E8);
        if (k != 7 && k != 0x32 && k != 0x37) {
            return;
        }
    }
    k = *(u8 *)(p + 0x1E8);
    if (k != 2 && k != 0x24 && k != 0x47 && (*(s32 *)(g + 0x28) & 5) == 0) {
        return;
    }
    if (*(u16 *)(p + 0x29A) != *(u16 *)(D_089CC438 + 0x6AF0E)) {
        return;
    }
    switch (k) {
    case 7:
    case 0x32:
        if (cur_id(D_089CC438) != 0xC) {
            return;
        }
        if (*(s16 *)(p + 0x2E4) > 0) {
            return;
        }
        r = 0x13;
        break;
    case 2:
    case 0x24:
    case 0x47:
        if (*(s16 *)(p + 0x2E4) > 0) {
            return;
        }
        r = 0x14;
        break;
    case 0x37:
        id = *(u8 *)(D_089CC438 + 0x6AF10);
        v = D_09CE4808[id];
        v = (v != 0xFFFF) ? v : id;
        if ((u16)v == 1) {
            if (cur_id(D_089CC438) != 0xC) {
                return;
            }
        }
        if (*(s16 *)(p + 0x2E4) > 0) {
            return;
        }
        r = 0x15;
        break;
    case 0x36:
    case 0x3C:
    case 0x3B:
        if (*(s16 *)(p + 0x2E4) > 0) {
            return;
        }
        r = 6;
        break;
    case 0x40:
    case 0x41:
        if (*(s16 *)(p + 0x2E4) > 0) {
            return;
        }
        r = 6;
        break;
    case 0x4C:
        if (*(s16 *)(p + 0x2E4) > 0) {
            return;
        }
        r = 0x16;
        break;
    case 0x58:
        if (*(s16 *)(p + 0x2E4) > 0) {
            return;
        }
        if (*(u8 *)(p + 0x298) == 5 && *(u8 *)(p + 0x299) == 3) {
            return;
        }
        r = 0x17;
        break;
    case 0x3A:
        if (func_08865CB8(p, 5, 0) == 1) {
            r = 0x19;
        } else if (func_08865CB8(p, 5, 1) == 1) {
            r = 0x18;
        }
        break;
    case 0x43:
    case 0x57:
        if (func_08865CB8(p, 5, 2) == 1 ||
            (r = D_089383E0[func_0884FC74(D_089CC438, *(u8 *)(p + 0x1E8))]) == 0xFF) {
            return;
        }
        break;
    case 0x15:
    case 0x2E:
    case 0x53:
        if (*(u8 *)(p + 0x298) == 5 && *(u8 *)(p + 0x299) == 2) {
            return;
        }
    default:
        r = D_089383E0[func_0884FC74(D_089CC438, k)];
        if (r == 0xFF) {
            return;
        }
        break;
    }
    if ((u8)func_08813C8C(arg0) == 1) {
        func_08813DAC(arg0);
    }
    if (arg1 != 0) {
        if (func_08813DD8(arg0) == 0) {
            return;
        }
        if (r == func_08813E10(arg0)) {
            return;
        }
        func_08813DAC(arg0);
    }
    func_08813560(arg0, r, p, 0);
    *(u8 *)(arg0 + 0xA0A) = 1;
    *(s32 *)(D_089CBBEC + 0x528) |= 0x20;
}
