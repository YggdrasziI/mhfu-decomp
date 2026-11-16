/* unit_088A658C: 0x088A658C-0x088A6780 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions building messages (same byte-wise clear as
 * include/unk_msg.h), after func_088A6100 (still in assembly) and before
 * unit_088A6780.
 */

#include "unk_msg.h"

typedef struct {
    s32 type;
    s32 unk4;
    s32 v;
} MC;

typedef struct {
    s32 type;
    s32 unk4;
    u8 b;
} MCb;

typedef struct {
    s32 type;
    s32 unk4;
    u8 a;
    s32 c;
    u8 b;
} M14;

extern s32 func_088A5B50(s32, void *, s32);
extern s32 *func_088A5ECC(s32, void *, s32);
extern s32 func_088A4C54(u32);
extern s32 func_088A5454(s32, u8);
extern s32 func_088A5548(char *, s32, u8, u8, u8);
extern s32 func_088A4BE8(s32);
extern void func_088A5774(R *, char *, s32, s32);
extern s32 func_088A6F30(R *, R *);

s32 func_088A658C(s32 arg0) {
    MC m;

    clear((char *) &m, sizeof(MC));
    m.v = arg0;
    return *func_088A5ECC(0x309, &m, sizeof(MC));
}

void func_088A65D4(s32 arg0) {
    MCb m;

    clear((char *) &m, sizeof(MCb));
    m.type = 0x10000009;
    m.b = arg0 & 1;
    func_088A5B50(1, &m, sizeof(MCb));
}

void func_088A6628(s32 a, s32 b, s32 c) {
    M14 m;

    clear((char *) &m, sizeof(M14));
    m.type = 0x1000000B;
    m.a = (a == 0xFF) ? a : (a & 0xF);
    m.c = c;
    m.b = b & 0x7F;
    func_088A5B50(1, &m, sizeof(M14));
}

s32 func_088A6690(R *arg0, s32 arg1) {
    char buf[0x10];
    R r;
    s32 h;
    s32 n;
    s32 i;
    s32 ret;

    clear(buf, sizeof(buf));
    ret = 0;
    h = func_088A4C54((u8) arg0->h.f.a);
    n = func_088A5454(h, arg1);
    i = 0;
    if (n > 0) {
        do {
            if (func_088A5548(buf, h, arg1, arg0->h.f.unk5, i) >= 0) {
                func_088A5774(&r, buf, arg0->h.f.unk5, func_088A4BE8((u8) arg0->h.f.a));
                ret = func_088A6F30(&r, arg0);
            }
            i++;
        } while (i < n);
    }
    return ret;
}
