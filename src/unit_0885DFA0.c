/* unit_0885DFA0: 0x0885DFA0-0x0885E244 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885DFA0: picks a 0x1A-byte record from one of three tables
 * (D_0893B818 / D_0894932C / D_0894E628, by type 0/1/2), checks its four
 * {id, need} requirements against func_0885AED0 / func_0885C33C counts
 * (mode 0: both, 1: first only, 2: second only) and returns 2 when all four
 * are met or empty, 1 when every flagged slot passes func_0885C5CC, else 0/1
 * from byte 1 of the record (0 when byte 1 is 2 and func_08857A80(.., 0xE)
 * fails).
 * Speed setting needed; the slot pointer steps by 4 bytes through the record
 * (`Rec *` stepped by `(char *) + 4`, fields read as e->e[0]); the declaration
 * order of the locals sets the saved registers.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u16 id;
    s16 need;
} Req;

typedef struct {
    u8 f0;
    u8 f1;
    u16 f2;
    Req e[4];
    u8 flags[4];
    u8 pad18[2];
} Rec;

extern Rec D_0893B818[];
extern Rec D_0894932C[];
extern Rec D_0894E628[];
extern char *D_08A62C50;
extern char *D_089CC438;

extern u8 func_0885C5CC(char *, u16);
extern s32 func_0885AED0(char *, u16);
extern s32 func_0885C33C(char *, u16);
extern s32 func_08857A80(char *, s32);

s32 func_0885DFA0(s32 arg0, u16 type, s16 idx, s32 mode) {
    s32 i;
    s32 a;
    u8 ok;
    u8 cntA;
    s32 b;
    s32 sum;
    u8 mask;
    Rec *r;
    Rec *e;
    u8 cntB;

    switch (type) {
    case 0:
        r = &D_0893B818[idx];
        break;
    case 1:
        r = &D_0894932C[idx];
        break;
    case 2:
        r = &D_0894E628[idx];
        break;
    }
    cntA = 0;
    cntB = 0;
    mask = 0;
    i = 0;
    e = r;
    for (; i < 4; i++, e = (Rec *)((char *)e + 4)) {
        if (e->e[0].id == 0 || e->e[0].need == 0) {
            mask |= (u8)(1 << i);
            continue;
        }
        ok = func_0885C5CC(D_08A62C50, e->e[0].id) == 1;
        switch (mode) {
        case 0:
            a = (s16)func_0885AED0(D_08A62C50, e->e[0].id);
            b = func_0885C33C(D_08A62C50, e->e[0].id);
            break;
        case 1:
            a = (s16)func_0885AED0(D_08A62C50, e->e[0].id);
            b = 0;
            break;
        case 2:
            a = 0;
            b = func_0885C33C(D_08A62C50, e->e[0].id);
            break;
        }
        sum = a + b;
        if (r->flags[i] != 0) {
            cntB++;
            if (ok > 0) {
                cntA++;
            }
        }
        if (sum >= e->e[0].need) {
            mask |= (u8)(1 << i);
        }
    }
    if (r->f1 == 2 && (u8)func_08857A80(D_089CC438, 0xE) == 0) {
        return 0;
    }
    if (mask == 0xF) {
        return 2;
    }
    if (cntB != 0 && cntB == cntA) {
        return 1;
    }
    if (r->f1 != 0) {
        return 1;
    }
    return 0;
}
