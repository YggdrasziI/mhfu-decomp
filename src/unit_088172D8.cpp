/* unit_088172D8: 0x088172D8-0x08818028 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08816F24 and func_08818028, which it calls).
 *
 * C++: the flag test keeps its `sltu` (bool). Default (size) setting.
 *
 * The four initialised local arrays (D_089384F4, D_08938504, D_08938520,
 * D_08938530) and the jump table (jtbl_08930968) are owned by this unit.
 * The `== 2` tests are one-case `switch`es (`beql` + `b` to the default).
 * The table search is a `do { } while` (entered without a guard). The
 * coordinates read from u16 globals: lh when passed, lhu when summed.
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Pair {
    u16 a;
    u16 b;
} Pair;

typedef struct Pos {
    s16 x;
    s16 y;
} Pos;

typedef struct Box {
    u8 unk0[0xC];
    s16 x;
    s16 y;
    u8 unk10[0x18];
} Box;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_08A62C50;
extern u16 D_08938488[2];
extern s32 D_0893848C;
extern u16 D_0893849C;
extern u16 D_0893849E;
extern s32 D_089384A0;
extern s16 D_089384A4;
extern s16 D_089384A8;
extern u8 D_089384AC;
extern u16 D_089384B0;
extern u16 D_089384B2;
extern s32 D_089384B4;
extern s16 D_089384B8;
extern s16 D_089384C0;
extern u16 D_089384D8;
extern u16 D_089384DA;
extern u16 D_089384EC;
extern s32 D_089384F0;
extern char D_08938478;
extern char D_0893847C;
extern char D_08938490;
extern char D_089384CC;
extern char D_089384E0;
extern char D_08938540;
extern char D_08938548;
extern u16 D_089AC834[];
extern u16 D_089AC836;
extern u16 D_089AC838;
extern u16 D_089AC83A;
extern u16 D_089AC83C;
extern u16 D_089AC83E;
extern u16 D_089AC840;
extern u16 D_089AC846;
extern u16 D_089AC588[];
extern u16 D_0893B164;
extern u16 D_0893B166;
extern s32 D_0893B168;
extern s8 D_0893AF2C[];
extern u8 D_0899D19B[][24];

extern Pair *func_08856884(char *, s32);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, s32);
extern void func_0882FC50(char *, void *, char *, s32);
extern int func_088915B0(char *, s32, s32, s8, char *, ...);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern s32 func_088286E4(char *, u8, u16);
extern void func_08818028(char *, s16, s16, u8, u16, s32);
extern s32 func_0885B5B8(char *, s16, s16, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern void func_0882FA24(Box *, void *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern s32 func_0885BE08(char *, s32, s32);
extern u8 func_0885C718(s8);
extern char *func_08825104(char *, s32);
extern s16 func_08828F3C(char *, Pair *);
extern s32 func_088568AC(char *, s32);
extern void func_088197A0(char *, u8, s32, s32, s32);

void func_088172D8(char *arg0) {
    s16 xoffs[7] = { 8, 0x20, 0x1F, 0x30, 0x20, 0x25, 8 };
    s32 sel;
    Pair *tbl;
    s32 color;
    s32 flags;
    s16 y;
    s32 n;
    s32 val;
    s32 cnt;
    char *str;
    s32 i;
    Pair *p;
    s16 key;
    s16 r;
    u8 st;

    sel = *(s32 *)(D_08A631A0 + 0xF7A574);
    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 0x200) == 1) {
        tbl = func_08856884(D_089CC438, 0);
    } else {
        tbl = (Pair *) (D_089CC438 + 0x43C8);
    }
    color = 0;
    flags = 5;
    if (*(u8 *)(arg0 + 0x5B8) < 3 && !(*(s32 *)(arg0 + 0x528) & 0x10)) {
        switch (*(u8 *)(arg0 + 0x5B8)) {
        case 2:
            func_0882FC50(arg0, &D_089384CC, func_0885151C(D_089CC438, D_089AC834[0]), 0xFF);
            break;
        default:
            func_0882FC50(arg0, &D_0893847C, func_0885151C(D_089CC438, D_089AC834[0]), 0xFF);
            break;
        }
        if (*(u8 *)(arg0 + 0x5B8) == 0) {
            func_088915B0(D_08A631A8, (s16) (D_08938488[0] + D_0893848C * 3 + xoffs[sel]), (s16) D_08938488[1], 3, &D_08938478, func_0885151C(D_089CC438, D_089AC846));
            if ((u8) func_088286E4(arg0, *(u8 *)(arg0 + 0x586), tbl[*(u8 *)(arg0 + 0x586)].a) == 1) {
                func_08818028(arg0, D_08938488[0], D_08938488[1] + D_0893848C, *(u8 *)(arg0 + 0x586), tbl[*(u8 *)(arg0 + 0x586)].a, 0);
            } else {
                func_08818028(arg0, D_08938488[0], D_08938488[1] + D_0893848C, 0xFF, tbl[*(u8 *)(arg0 + 0x586)].a, 0);
            }
        } else {
            switch (*(u8 *)(arg0 + 0x5B8)) {
            case 2:
                func_08818028(arg0, D_089384D8, D_089384DA + D_0893848C, *(u8 *)(arg0 + 0x5B0), *(u16 *)(arg0 + 0x5AC), 1);
                break;
            default:
                func_08818028(arg0, D_08938488[0], D_08938488[1] + D_0893848C, *(u8 *)(arg0 + 0x5B0), *(u16 *)(arg0 + 0x5AC), 1);
                break;
            }
        }
        if (*(u8 *)(arg0 + 0x5B8) > 0) {
            switch (*(u8 *)(arg0 + 0x5B8)) {
            case 2:
                func_0882FC50(arg0, &D_089384E0, func_0885151C(D_089CC438, D_089AC836), 0xFF);
                break;
            default:
                func_0882FC50(arg0, &D_08938490, func_0885151C(D_089CC438, D_089AC836), 0xFF);
                break;
            }
            if (*(u8 *)(arg0 + 0x5B8) == 1) {
                func_088915B0(D_08A631A8, (s16) (D_0893849C + D_089384A0 * 3 + xoffs[sel]), (s16) D_0893849E, 3, &D_08938478, func_0885151C(D_089CC438, D_089AC846));
                if (func_0885B5B8(D_08A62C50, *(s16 *)(arg0 + 0x5AC), tbl[*(u8 *)(arg0 + 0x586)].a, 0, 0, 0) != 0) {
                    func_08818028(arg0, D_0893849C, D_0893849E + D_089384A0, *(u8 *)(arg0 + 0x586), tbl[*(u8 *)(arg0 + 0x586)].a, 0);
                } else {
                    func_08818028(arg0, D_0893849C, D_0893849E + D_089384A0, 0xFF, tbl[*(u8 *)(arg0 + 0x586)].a, 0);
                }
            } else {
                switch (*(u8 *)(arg0 + 0x5B8)) {
                case 2:
                    func_08818028(arg0, D_089384EC, D_0893849E + D_089384F0, *(u8 *)(arg0 + 0x5B1), *(u16 *)(arg0 + 0x5AE), 1);
                    break;
                default:
                    func_08818028(arg0, D_0893849C, D_0893849E + D_089384A0, *(u8 *)(arg0 + 0x5B1), *(u16 *)(arg0 + 0x5AE), 1);
                    break;
                }
            }
        }
        st = *(u8 *)(arg0 + 0x5B8);
        if (st < 2) {
            color = 0x8000C040;
        }
        flags = (st > 0 ? 8 : 4) | 0x11;
    }
    {
    Pos pos[7] = { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { -6, 6 }, { -6, 6 }, { 0, 0 } };
    D_089384A4 = pos[sel].x + 0xC;
    D_089384B0 = pos[sel].x + 0x14;
    D_089384A8 = pos[sel].y + 0x9C;
    y = D_089384B0 + D_089384AC * 5;
    }
    switch (*(u8 *)(arg0 + 0x5B8)) {
    case 0:
    case 1:
        if (*(s32 *)(arg0 + 0x528) & 0x10) {
            flags |= 0x21;
            color = 0;
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            func_088920A8(D_08A631A8, D_0893B164 + 0x62, D_0893B166 + D_0893B168 * 2, &D_08938478, func_0885151C(D_089CC438, D_089AC588[*(u8 *)(arg0 + 0x537)]));
        } else {
            if (*(s32 *)(arg0 + 0x528) & 0x20) {
                flags |= 0x10;
            } else {
                flags |= 0x50;
            }
            color = 0x8000C040;
        }
        break;
    case 2:
        {
            Box box;
            s16 w[7] = { 0, 0, 0x10, 0, 0, 0, 0 };
            s16 h[7] = { 0, 0, 2, 0, 0, 0, 0 };
            s32 k;

            k = *(s32 *)(D_08A631A0 + 0xF7A574);
            D_089384B8 = 0xF8 - w[k];
            D_089384C0 = h[k] + 9;
            func_0882FA24(&box, &D_089384B8, 0, 0, 0);
            func_0882F580(arg0, &box, 0, *(u8 *)(arg0 + 0x5B9), 0xFF, 0);
            val = *(s8 *)(arg0 + 0x5BA) == 0 ? 0 : 10;
            func_088915B0(D_08A631A8, box.x, box.y, val, &D_08938478, func_0885151C(D_089CC438, D_089AC840));
        }
    case 3:
    case 4:
        func_0882FC50(arg0, &D_089384A4, func_0885151C(D_089CC438, D_089AC838), 0xFF);
        if (*(s16 *)(arg0 + 0x5B4) > 0) {
            func_08890E38(D_08A631A8, 0);
            func_08891474(D_08A631A8, D_089384B0, D_089384B2 + D_089384B4, &D_08938478, func_08851528(D_089CC438, *(u16 *)(*(char **)(arg0 + 0x5A8) + 2)));
            val = (s8) func_0885BE08(D_08A62C50, *(s32 *)(arg0 + 0x5A8), 0);
            func_08890E38(D_08A631A8, D_0893AF2C[func_0885C718(val)]);
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 2, func_0885151C(D_089CC438, D_089AC83C), (s8) val);
            func_08890E38(D_08A631A8, 0);
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 3, &D_08938478, func_08825104(arg0, *(s32 *)(arg0 + 0x5A8)));
            key = *(s16 *)(arg0 + 0x5B4);
            i = 0;
            p = tbl;
            do {
                if (key == p->a) {
                    r = func_08828F3C(arg0, &tbl[i]);
                    if (r >= 0) {
                        switch (r) {
                        case 0:
                            func_08890E38(D_08A631A8, 2);
                            break;
                        case 1:
                            func_08890E38(D_08A631A8, 6);
                            break;
                        }
                    }
                    break;
                }
                i++;
                p++;
            } while (i < 24);
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 4, &D_08938540, (u16) func_088568AC(D_089CC438, *(u16 *)(arg0 + 0x5B4)), D_0899D19B[*(s16 *)(arg0 + 0x5B4)][0]);
            func_08890E38(D_08A631A8, 0);
        } else {
            func_08890E38(D_08A631A8, 10);
            str = func_0885151C(D_089CC438, D_089AC83A);
            func_08891474(D_08A631A8, D_089384B0, D_089384B2 + D_089384B4, &D_08938478, str);
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 2, &D_08938478, func_0885151C(D_089CC438, D_089AC83E));
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 3, &D_08938478, str);
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 4, &D_08938478, str);
        }
        break;
    case 5:
    case 6:
        {
            u16 k;

            if (*(s16 *)(arg0 + 0x5B6) != 0x9B) {
                val = *(u8 *)(arg0 + 0x5E5);
                k = 7;
            } else {
                k = 8;
                val = 1;
            }
            func_0882FC50(arg0, &D_089384A4, func_0885151C(D_089CC438, D_089AC834[k]), 0xFF);
            n = (u16) func_088568AC(D_089CC438, *(u16 *)(arg0 + 0x5B6));
            cnt = D_0899D19B[*(s16 *)(arg0 + 0x5B6)][0];
            func_08890E38(D_08A631A8, 0);
            func_08891474(D_08A631A8, D_089384B0, D_089384B2 + D_089384B4, &D_08938478, func_08851528(D_089CC438, *(u16 *)(arg0 + 0x5B6)));
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 3, &D_08938548, (u16) val);
            key = *(s16 *)(arg0 + 0x5B4);
            i = 0;
            p = tbl;
            do {
                if (key == p->a) {
                    r = func_08828F3C(arg0, &tbl[i]);
                    if (r >= 0) {
                        switch (r) {
                        case 0:
                            func_08890E38(D_08A631A8, 2);
                            break;
                        case 1:
                            func_08890E38(D_08A631A8, 6);
                            break;
                        }
                    }
                    break;
                }
                i++;
                p++;
            } while (i < 24);
            func_08891474(D_08A631A8, y, D_089384B2 + D_089384B4 * 4, &D_08938540, (u16) n, (u16) cnt);
            func_08890E38(D_08A631A8, 0);
        }
        break;
    }
    func_088197A0(arg0, *(u8 *)(arg0 + 0x586), color, flags, 0);
}

}
