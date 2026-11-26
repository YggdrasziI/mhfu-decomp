/* unit_08820DBC: 0x08820DBC-0x08820FB4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Returns one of several string pointers by the kind of two records.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62C54;
extern char D_0893AC30[];
extern char D_0893AC38[];
extern char D_0893AC3C[];
extern char D_0893AC44[];
extern char D_0893AC4C[];
extern char D_0893AC50[];
extern char D_0893AC58[];
extern char D_0893AC60[];
extern char D_0893AC64[];
extern char D_0893AC6C[];
extern char D_0893AC74[];
extern char D_0893AC7C[];
extern char D_0893AC84[];

extern s32 func_0885E718(s32 arg0, u8 *arg1);
extern u8 func_0885CD18(s32 arg0, u8 arg1, u16 arg2);

char *func_08820DBC(s32 arg0, u8 *p, s32 flags, u8 *q) {
    s32 f;
    s32 r;
    s32 k;

    f = flags & 0x100;
    if (p == 0) {
        if (q == 0) {
            return D_0893AC84;
        }
        k = q[1];
        switch (k) {
        case 5:
        case 6:
            if (f == 0) {
                if (func_0885E718(D_08A62C54, q) == 0) {
                    return D_0893AC84;
                }
            }
        }
        return D_0893AC7C;
    }
    r = func_0885E718(D_08A62C54, p);
    if (q != 0) {
        r |= func_0885E718(D_08A62C54, q);
        k = q[1];
        f |= r;
    } else {
        f |= flags & 0x10;
        k = -1;
    }
    switch (p[1]) {
    case 5:
        if (f != 0) {
            return D_0893AC30;
        }
        return r == 0 ? D_0893AC38 : D_0893AC3C;
    case 6:
        if (func_0885CD18(D_08A62C54, p[1], *(u16 *)(p + 2)) != 10) {
            if (f != 0) {
                return D_0893AC44;
            }
            return r == 0 ? D_0893AC4C : D_0893AC50;
        }
        if (f != 0) {
            return D_0893AC58;
        }
        return r == 0 ? D_0893AC60 : D_0893AC64;
    }
    if (k != -1 || f != 0) {
        return D_0893AC6C;
    }
    return D_0893AC74;
}
