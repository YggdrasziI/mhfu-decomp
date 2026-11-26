/* unit_08823E18: 0x08823E18-0x08824B14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. Its jump table (0x08930A40-0x08930A5C,
 * in .data) is linked from this unit.
 *
 * C++: in state 3 the swapped record is a local initialised where it is read
 * (copied as a block, lh/lh) and assigned back with `*q = tmp;` (copied by
 * members, lhu/lh), after which tmp.a is read again from the stack. The
 * 0x390 table is indexed as `(char *)(idx * 4) + (s32)base` (index first in
 * the addu), except for the store of the swapped record (`base + idx * 4`).
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 a;
    s16 b;
} Pair;

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62C50;
extern s32 D_08A62CB4;
extern s32 D_08A62D8C;
extern s32 D_09A4F0C4;

extern void func_0881C098(char *, char *, s32, s32);
extern s32 func_0881C2E4(char *, u8 *, s32, s32);
extern s32 func_0881C45C(char *, u8 *, s32, s32);
extern u16 func_0884FB6C(char *);
extern s32 func_0884FBA4(char *, s32);
extern u16 func_08853ABC(char *, u16, u16, u16);
extern Pair *func_08856884(char *, s32);
extern s32 func_088569F8(char *, u16);
extern void func_08858F1C(char *, u16);
extern void func_0885ACA0(s32, u16);
extern s32 func_0885C498(s32, u16);
extern s32 func_088790F4(s32);
extern s32 func_08879158(s32);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u16 func_088D72A4(char *, u16, s16, s32);
extern void func_088D8900(char *);
extern char *func_088DCEBC(s32, u8);

}

#define ENT(o) ((char *)(*(u8 *)(p + 0x120C) * 4) + (s32)D_089CC438 + (o))

extern "C" s32 func_08823E18(char *p, s32 arg1) {
    s32 pad;
    s32 cols;
    s32 rows;
    char *obj;
    s32 id;
    s32 cnt;
    u8 col;
    u8 row;
    Pair *q;
    Pair *e;

    pad = func_0884FB6C(D_089CC438);
    if (*(u8 *)(p + 0x1218) == 0) {
        cols = 8;
        rows = 4;
    } else {
        cols = 8;
        rows = 2;
    }
    if (*(u8 *)(p + 0x120F) == 0) {
        func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        *(u8 *)(p + 0x120F) = 1;
    }
    obj = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    id = *(u16 *)ENT(0x390);
    *(s8 *)(p + 0x1210) = -1;
    if (arg1 != 0) {
        *(s32 *)(p + 0x1214) -= 1;
    }
    switch (*(u8 *)(p + 0x120A)) {
    case 1:
    case 3:
        cnt = (s16)func_088569F8(D_089CC438, id);
        if (cnt == 0xFF || cnt == 0) {
            *(s8 *)(p + 0x1210) = 0;
        }
        break;
    case 2:
        cnt = func_0885C498(D_08A62C50, id);
        if (cnt == 0) {
            *(s8 *)(p + 0x1210) = 0;
        }
        break;
    }
    switch (*(u8 *)(p + 0x120A)) {
    case 0:
        if (func_0881C2E4(p, (u8 *)(p + 0x120B), pad, 3) != 0) {
            *(u16 *)(p + 0x5FC) = *(u8 *)(p + 0x120B) + 4;
        } else if ((u16)pad & 0x4000) {
            if (*(u8 *)(p + 0x120B) == 0) {
                *(u8 *)(p + 0x120C) = 0;
                *(u8 *)(p + 0x120A) = 1;
            } else if (*(u8 *)(p + 0x120B) == 1) {
                *(u8 *)(p + 0x120C) = 0;
                *(u8 *)(p + 0x120A) = 2;
            } else if (func_08879158(D_08A62CB4) == 0) {
                *(u8 *)(p + 0x120A) = 6;
            } else {
                *(u8 *)(p + 0x120D) = 0;
                *(u8 *)(p + 0x120A) = 4;
            }
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if ((u16)pad & 0x2000) {
            if (*(u8 *)(p + 0x120B) != 2) {
                *(u8 *)(p + 0x120B) = 2;
                *(u16 *)(p + 0x5FC) = 6;
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
        }
        break;
    case 1:
        col = *(u8 *)(p + 0x120C) % cols;
        row = *(u8 *)(p + 0x120C) / cols;
        if (func_0881C45C(p, &col, pad, (u8)cols) != 0) {
            *(u8 *)(p + 0x120C) = col + row * cols;
        } else if (func_0881C2E4(p, &row, pad, (u8)rows) != 0) {
            *(u8 *)(p + 0x120C) = col + row * cols;
        } else if ((u16)pad & 0x4000) {
            if (id != 0 && *(s8 *)(p + 0x1210) < 0) {
                switch (func_088D72A4(obj, id, *(s16 *)ENT(0x392), 0)) {
                case 0:
                case 1:
                    func_08858F1C(D_089CC438, *(u16 *)ENT(0x390));
                    *(u16 *)ENT(0x390) = 0;
                    *(u16 *)ENT(0x392) = 0;
                    func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
                    break;
                case 2:
                    func_08858F1C(D_089CC438, *(u16 *)ENT(0x390));
                    *(s16 *)ENT(0x392) -= (s16)cnt;
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                    break;
                case 3:
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                    break;
                case 5:
                    *(u16 *)(p + 0x5FC) = 1;
                    *(u8 *)(p + 0x120E) &= 0xFE;
                    *(u8 *)(p + 0x586) = 0;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                    *(u8 *)(p + 0x120A) = 3;
                    break;
                }
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        } else if ((u16)pad & 0x8000) {
            if (*(u8 *)(p + 0x120E) & 1) {
                *(u8 *)(p + 0x120E) &= 0xFE;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            } else {
                *(u8 *)(p + 0x120E) |= 1;
                func_08883988(D_08A62D8C, 0, 9, 0, 0, 0, 0, 0, 0);
            }
        } else if ((u16)pad & 0x2000) {
            if (*(u8 *)(p + 0x120E) & 1) {
                *(u8 *)(p + 0x120E) &= 0xFE;
            } else {
                *(u8 *)(p + 0x120A) = 0;
                *(u8 *)(p + 0x120E) = 0;
                *(u8 *)(p + 0x5FE) = 6;
                *(u16 *)(p + 0x5FC) = *(u8 *)(p + 0x120B) + 4;
            }
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 2:
        col = *(u8 *)(p + 0x120C) % cols;
        row = *(u8 *)(p + 0x120C) / cols;
        if (func_0881C45C(p, &col, pad, (u8)cols) != 0) {
            *(u8 *)(p + 0x120C) = col + row * cols;
        } else if (func_0881C2E4(p, &row, pad, (u8)rows) != 0) {
            *(u8 *)(p + 0x120C) = col + row * cols;
        } else if ((u16)pad & 0x4000) {
            if (id != 0 && *(s8 *)(p + 0x1210) < 0) {
                id = func_08853ABC(D_089CC438, id, *(u16 *)ENT(0x392), 0xFFFF);
                func_08858F1C(D_089CC438, *(u16 *)ENT(0x390));
                if (id == 0) {
                    *(u16 *)ENT(0x390) = 0;
                    *(u16 *)ENT(0x392) = 0;
                    func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
                } else {
                    *(u16 *)ENT(0x392) = id;
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        } else if ((u16)pad & 0x8000) {
            if (*(u8 *)(p + 0x120E) & 1) {
                *(u8 *)(p + 0x120E) &= 0xFE;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            } else {
                *(u8 *)(p + 0x120E) |= 1;
                func_08883988(D_08A62D8C, 0, 9, 0, 0, 0, 0, 0, 0);
            }
        } else if ((u16)pad & 0x2000) {
            if (*(u8 *)(p + 0x120E) & 1) {
                *(u8 *)(p + 0x120E) &= 0xFE;
            } else {
                *(u8 *)(p + 0x120A) = 0;
                *(u8 *)(p + 0x120E) = 0;
                *(u8 *)(p + 0x5FE) = 6;
                *(u16 *)(p + 0x5FC) = *(u8 *)(p + 0x120B) + 4;
            }
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 3:
        if ((u16)pad & 0x4000) {
            Pair tmp = *(Pair *)ENT(0x390);
            q = func_08856884(D_089CC438, *(u8 *)(p + 0x586));
            e = (Pair *)(D_089CC438 + *(u8 *)(p + 0x120C) * 4 + 0x390);
            e->a = q->a;
            e->b = q->b;
            q = func_08856884(D_089CC438, *(u8 *)(p + 0x586));
            *q = tmp;
            func_0885ACA0(D_08A62C50, tmp.a);
            *(u8 *)(p + 0x120A) = 1;
            *(u16 *)(p + 0x5FC) = 0;
            *(u8 *)(p + 0x120E) &= 0xFE;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if ((u16)pad & 0x2000) {
            if (*(u8 *)(p + 0x120E) & 1) {
                *(u8 *)(p + 0x120E) &= 0xFE;
            } else {
                *(u8 *)(p + 0x120A) = 1;
                *(u16 *)(p + 0x5FC) = 0;
            }
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if ((u16)pad & 0x8000) {
            if (*(u8 *)(p + 0x120E) & 1) {
                *(u8 *)(p + 0x120E) &= 0xFE;
                func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
            } else {
                *(u8 *)(p + 0x120E) |= 1;
                func_08883988(D_08A62D8C, 0, 9, 0, 0, 0, 0, 0, 0);
            }
        } else {
            func_0881C098(p, p + 0x586, pad, 0x18);
        }
        break;
    case 4:
        if ((u16)pad & 0xA0) {
            *(u8 *)(p + 0x120D) ^= 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        } else if (((u16)pad & 0x4000) && *(u8 *)(p + 0x120D) == 1) {
            *(u8 *)(p + 0x120A) = 5;
        } else if ((((u16)pad & 0x4000) && *(u8 *)(p + 0x120D) == 0) || ((u16)pad & 0x2000)) {
            *(u8 *)(p + 0x120A) = 0;
            *(u8 *)(p + 0x120E) = 0;
            *(u8 *)(p + 0x5FE) = 6;
            *(u16 *)(p + 0x5FC) = *(u8 *)(p + 0x120B) + 4;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 5:
        func_0884FBA4(D_089CC438, func_088790F4(D_08A62CB4));
        func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
        *(u8 *)(p + 0x120A) = 6;
        return 1;
    case 6:
        func_088D8900(obj);
        return 0;
    default:
        return 0;
    }
    if (*(s32 *)(p + 0x1214) <= 0) {
        func_0884FBA4(D_089CC438, func_088790F4(D_08A62CB4));
        func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
        *(u8 *)(p + 0x120A) = 6;
    }
    return 1;
}
