/* unit_088DBEE0: 0x088DBEE0-0x088DC1C8 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088DBE80 and unit_088DC1C8.
 *
 * func_088DBEE0 and func_088DC16C run one step function (func_088DBBBC,
 * func_088DBF3C) for the slot at +0x3C and move to the next slot when it
 * returns non-zero; they return 1 once the four slots are done.
 * func_088DBF3C is the two-step sequence of a slot: step 0 sends two pairs
 * of 16-bit values (from the tables at 0x089A989C and 0x089AA140, or fixed
 * ones for six ids) to func_08880A70, step 1 waits for func_08881970.
 *
 * C++: bool conversion.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

struct Pair {
    u16 a;
    u16 b;
};

struct Group {
    char pad0[0x24];
    s32 state[6];
    s32 slot;
};

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern u16 D_089A989C[];
extern u16 D_089A989E[];
extern Pair D_089AA140[][17];
extern Pair D_089AA142[][17];

extern s32 func_08851F20(char *, s32);
extern void func_08880A70(s32, s32, u16 *, u16 *, s32, s32);
extern s32 func_08881970(s32);
extern s32 func_088DBBBC(Group *, s32);

s32 func_088DBF3C(Group *arg0, s32 arg1);

s32 func_088DBEE0(Group *arg0) {
    s32 r;

    if (arg0->slot < 4) {
        if (func_088DBBBC(arg0, arg0->slot) != 0) {
            arg0->slot++;
        }
        r = 0;
    } else {
        arg0->slot = 0;
        r = 1;
    }
    return r;
}

s32 func_088DBF3C(Group *arg0, s32 arg1) {
    char *g = D_089CC438;
    u8 *rec = (u8 *)(g + arg1 * 0x8C + 0x30);
    u16 a[2];
    u16 b[2];
    s32 id;

    switch (arg0->state[arg1]) {
    case 0:
        if (rec[0] == 0) {
            return 1;
        }
        if ((bool) (*(s32 *)(g + 0x6AF14) & 1) != 0) {
            arg0->state[arg1] = 0;
            return 1;
        }
        id = func_08851F20(g, arg1);
        a[0] = D_089A989C[id * 2];
        b[0] = D_089A989E[id * 2];
        if (id == 0x6F || id == 0xAA) {
            if (rec[0x10] == 0) {
                a[1] = 0x129E;
                b[1] = 0x129F;
            } else {
                a[1] = 0x129C;
                b[1] = 0x129D;
            }
        } else if (id == 0x185) {
            a[1] = 0x12A1;
            b[1] = 0x12A0;
        } else if (id == 0x186) {
            a[1] = 0x12A3;
            b[1] = 0x12A2;
        } else if (id == 0x217) {
            a[1] = 0x12A5;
            b[1] = 0x12A4;
        } else if (id == 0x218) {
            a[1] = 0x12A7;
            b[1] = 0x12A6;
        } else {
            a[1] = D_089AA140[rec[0x10]][rec[0x11]].a;
            b[1] = D_089AA142[rec[0x10]][rec[0x11]].a;
        }
        func_08880A70(D_08A62D8C, arg1 + 2, a, b, 0x1257, 2);
        arg0->state[arg1]++;
        break;
    case 1:
        if (func_08881970(D_08A62D8C) != 0) {
            break;
        }
        arg0->state[arg1] = 0;
    default:
        return 1;
    }
    return 0;
}

s32 func_088DC16C(Group *arg0) {
    s32 r;

    if (arg0->slot < 4) {
        if (func_088DBF3C(arg0, arg0->slot) != 0) {
            arg0->slot++;
        }
        r = 0;
    } else {
        arg0->slot = 0;
        r = 1;
    }
    return r;
}

}
