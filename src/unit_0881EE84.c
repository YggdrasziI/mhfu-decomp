/* unit_0881EE84: 0x0881EE84-0x08820B74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * NonMatching: func_0881EE84 99.46 %. Left: the saved registers of px and
 * item2 are swapped (s1/s2) through the whole function (and so in kind 4/5
 * mask/flag take s2 instead of s1), and the prologue spill slots of
 * arg7 * 4 and sy0 are swapped (0x74/0x70). The px/item2 order did not move
 * with declaration order (function or block level, random searches), local
 * copies of item2 or px (any type, any position), param types, inline
 * helpers for the kinds, statement orders, or pragmas. The spill slots follow
 * the definition order before scheduling: an explicit `a7off = arg7 * 4`
 * before `sy0 = py` gives the right slots but schedules the sy0 store after
 * the switch value (99.44 %). The stack slots of the byte/halfword locals
 * follow declaration order: default's own dval first, txt at function
 * level, and kind 0's spx is sx0 reused (a split web goes last). arg0 goes
 * through a void * copy to get s0. Kind 4/5's rec is declared first (it
 * takes the last saved register of that block). func_08821B58 takes a
 * `u8 *` second argument: with `(u8 *)arg6 + 0x4E8` a0 is set before a1.
 * Owns jtbl_089309D4, jtbl_089309F0 and the initialised local D_089385B8
 * once it matches.
 */

/* func_0881EE84: draws one item description panel by its kind. */

#pragma optimize_for_size off
#pragma opt_propagation off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s16 v[7];
} Offs7;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    Vec3s v;
} ItemRec;

extern char *D_08A631A0;
extern char *D_08A631A8;
extern char *D_089CC438;
extern char *D_08A62C54;
extern Offs7 D_089385B8;
extern u16 D_089385C8[];
extern u16 D_089385CA[];
extern s32 D_0893ABBC[];
extern char D_08938478[];
extern char D_08938548[];
extern char D_08938594[];
extern u16 D_089385D4[];
extern u16 D_089AC89C;
extern u16 D_089AC8A0;
extern u16 D_089AC8A2;
extern u16 D_089AC8A4;
extern u16 D_089AC8A6;
extern u16 D_089AC8A8;
extern u16 D_089AC8AA;
extern u16 D_089AC8C6;
extern u16 D_089AC8E6;
extern u16 D_089AC8EC[];
extern u16 D_089AC8F4[];
extern u16 D_089AC8FC[];
extern u16 D_089AC904[];
extern u16 D_089AC910[];
extern u16 D_089AC914;
extern u16 D_089AC920[];
extern u16 D_089AC934[];
extern u16 D_089AC944[];
extern u16 D_089AC94A[];
extern u16 D_089AC94C;
extern u16 D_089AC954[];
extern u16 D_089AC95E;
extern u16 D_089AC960;
extern u16 D_089AC962;
extern u16 D_089AC964;
extern u16 D_089AC974[];

extern char *func_08820DBC(char *, u8 *, s32, u8 *);
extern s32 func_0885C83C(char *, u8, u16);
extern u8 func_0885CD18(char *, u8, u16);
extern s32 func_088303A0(char *, u8);
extern void func_08890E38(char *, s8);
extern void func_08820FB4(char *, u8 *, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern char *func_08851578(char *, u16);
extern char *func_0885154C(char *, u16);
extern char *func_08851654(char *, u16);
extern char *func_08851628(char *, u16);
extern char *func_088515FC(char *, u16);
extern char *func_088515D0(char *, u16);
extern char *func_088515A4(char *, u16);
extern char *func_0885C968(char *, u8, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern u8 *func_0885CA50(char *, u8 *);
extern s16 func_0885CE38(char *, u8 *);
extern s32 func_0885EAA4(char *, u8 *);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_08892148(char *, s16, s16, s8, char *, ...);
extern void func_08892004(char *, char *, ...);
extern void func_08821080(char *, s32, u8 *, s16, s16);
extern void func_088232A0(char *, u8 *, u16, u16, u8 *);
extern void func_08822210(char *, u8 *, u16, u16);
extern void func_0882217C(char *, u8 *, u16, u16);
extern u16 func_08820B74(char *, u8 *, u8 *, u8 *);
extern void func_08831274(char *, s16, s16, u16 *, s16, s8 *);
extern void func_08890E40(char *, s32);
extern s32 func_08890E48(char *, char *);
extern void func_088226F0(char *, s32, u8 *, u16, u16, u8 *);
extern void func_088229B8(char *, u8 *, u16, u16, u8);
extern void func_0882148C(char *, u8 *, s16, s16, u8 *, u8);
extern u8 func_08826EF4(char *, s32, u8 *);
extern u8 func_08821B58(char *, u8 *, u8 *);
extern void func_08838894(char *, s32, u8 *, s16, s16);
extern void func_0881B5C4(char *, s32, s16, s16);
extern void func_08821890(char *, s32);
extern void func_08821A10(char *, s32, u8 *);
extern u32 func_088D7DE8(s32);
extern u8 func_088D6A1C(s32, s32);
extern void func_08821924(char *, s32);
extern void func_08890DFC(char *, s16, s16);
extern void func_08821D48(char *, s16, s16, u8 *, u32, u32, s32, u8);
extern void func_0882232C(char *, u8 *, s32, u8 *, u16, u16);
extern s32 func_088D7F34(s32);
extern void func_08822594(char *, u8 *, u16, u16, s32);
extern void func_08822C58(char *, u8 *, u16, u16, u8, s32);

void func_0881EE84(void *a0v, u8 *item, u16 px, u16 py, s32 flags, u8 *item2, s32 arg6, s32 arg7)
{
    char *arg0 = a0v;
    s16 sx0;
    s16 sy0;
    s16 offs[7] = { 0, 0, 0, 0, 0, -8, 0 };
    s32 sel;
    char *str;
    u8 kind;
    u32 dval;
    u32 dval2;
    u8 rarity;
    u8 cat;
    u8 cat2;
    s32 noHl;
    s8 dim;
    s8 hl;
    s8 base;
    u16 *ids;
    s8 *colp;
    char *txt;
    s8 col[8];

    sel = *(s32 *)(D_08A631A0 + 0xF7A574);
    str = func_08820DBC(arg0, item, flags, item2);
    kind = str[flags & 7];
    if (flags & 0x20) {
        item2 = 0;
    }
    if (item != 0) {
        rarity = func_0885C83C(D_08A62C54, item[1], *(u16 *)(item + 2));
        cat = func_0885CD18(D_08A62C54, item[1], *(u16 *)(item + 2));
    } else {
        rarity = (u8)(cat = 0);
    }
    if (item2 != 0) {
        cat2 = func_0885CD18(D_08A62C54, item2[1], *(u16 *)(item2 + 2));
    } else {
        cat2 = 0;
    }
    noHl = flags & 8;
    if (noHl == 0) {
        dim = 5;
        base = 0;
        hl = func_088303A0(arg0, rarity);
    } else {
        hl = 10;
        dim = 10;
        base = 10;
    }
    func_08890E38(D_08A631A8, dim);
    sx0 = px;
    sy0 = py;
    px = sx0 + D_089385C8[arg7 * 2];
    py = sy0 + 8;
    switch (kind) {
    case 0: {
        u16 x16;
        u16 y16;
        u32 val;
        u32 val2;
        u8 *rec;
        u8 *rec2;

        sx0 = px;
        func_08820FB4(arg0, item, sx0, (s16)py, flags & 0xFF);
        y16 = py;
        x16 = px;
        func_088920A8(D_08A631A8, x16 + 0x1C, y16 + 4, func_0885151C(D_089CC438, D_089AC954[0]), hl,
                      func_0885C968(D_08A62C54, item[1], *(u16 *)(item + 2)));
        py = y16 + 0x20;
        colp = 0;
        switch (item[1]) {
        case 5: {
            u16 yy;

            rec = func_0885CA50(D_08A62C54, item);
            val = (u16)((*(u16 *)(rec + 0xA) * D_0893ABBC[cat]) / 100);
            col[4] = 0;
            col[3] = 0;
            col[2] = 0;
            col[1] = 0;
            col[0] = 0;
            if (item2 != 0) {
                if (item[1] == item2[1]) {
                    rec2 = func_0885CA50(D_08A62C54, item2);
                    val2 = (u16)((*(u16 *)(rec2 + 0xA) * D_0893ABBC[cat2]) / 100);
                    if (rec2[9] < rec[9]) {
                        col[1] = 4;
                    } else if (rec[9] < rec2[9]) {
                        col[1] = 2;
                    }
                } else {
                    val2 = (u16)((D_0893ABBC[cat2] * func_0885CE38(D_08A62C54, item2)) / 100);
                }
                if (val2 < val) {
                    col[0] = 4;
                } else if (val < val2) {
                    col[0] = 2;
                }
            }
            func_088915B0(D_08A631A8, x16 + 0x38, py, col[0], D_08938594, val);
            yy = py;
            func_08821080(arg0, arg6, item, x16 + 0x64, yy + 0xF);
            func_088232A0(arg0, item, px, yy + 0x20, item2);
            switch (cat) {
            case 9:
                func_0882217C(arg0, item, px, py);
                break;
            case 8:
                func_08822210(arg0, item, px, py);
                break;
            }
            ids = D_089AC8FC;
            break;
        }
        case 6: {
            u16 bits;
            u8 b3;
            u8 b2;
            u8 b1;
            u8 b0;
            s16 spy;

            val = (u16)((D_0893ABBC[cat] * func_0885CE38(D_08A62C54, item)) / 100);
            bits = func_08820B74(arg0, item, &b3, &b1);
            col[7] = 0;
            col[6] = 0;
            col[5] = 0;
            col[4] = 0;
            col[3] = 0;
            col[2] = 0;
            col[1] = 0;
            col[0] = 0;
            if (bits != 0) {
                if (bits & 1) {
                    col[1] = 3;
                }
                if (bits & 6) {
                    col[5] = 3;
                }
            }
            if (item2 != 0) {
                if (item[1] == item2[1]) {
                    val2 = (u16)((D_0893ABBC[cat2] * func_0885CE38(D_08A62C54, item2)) / 100);
                    func_08820B74(arg0, item2, &b2, &b0);
                    if (cat2 != 10) {
                        if (b2 < b3) {
                            col[1] = 4;
                        } else if (b3 < b2) {
                            col[1] = 2;
                        }
                        if ((s8)(*(u16 *)(item2 + 4) & 0xF) < (s8)(*(u16 *)(item + 4) & 0xF)) {
                            col[2] = 4;
                        } else if ((s8)(*(u16 *)(item + 4) & 0xF) < (s8)(*(u16 *)(item2 + 4) & 0xF)) {
                            col[2] = 2;
                        }
                        if (*(u16 *)(item2 + 4) & 0x40) {
                            if (!(*(u16 *)(item + 4) & 0x40)) {
                                col[3] = 2;
                            }
                        } else if (*(u16 *)(item + 4) & 0x40) {
                            col[3] = 4;
                        }
                        if (*(u16 *)(item2 + 4) & 0xB0) {
                            if (!(*(u16 *)(item + 4) & 0xB0)) {
                                col[4] = 2;
                            }
                        } else if (*(u16 *)(item + 4) & 0xB0) {
                            col[4] = 4;
                        }
                        if (b0 < b1) {
                            col[5] = 4;
                        } else if (b1 < b0) {
                            col[5] = 2;
                        }
                    }
                } else {
                    rec2 = func_0885CA50(D_08A62C54, item2);
                    val2 = (u16)((*(u16 *)(rec2 + 0xA) * D_0893ABBC[cat2]) / 100);
                }
                if (val2 < val) {
                    col[0] = 4;
                } else if (val < val2) {
                    col[0] = 2;
                }
            }
            spy = py;
            func_088915B0(D_08A631A8, x16 + 0x38, spy, col[0], D_08938594, val);
            if (cat != 10) {
                s16 cx;
                s32 k;
                u16 yy;
                s32 y1;
                s32 y2;

                cx = (u16)(x16 + 0x46);
                yy = py;
                y1 = yy + 0x10;
                func_088915B0(D_08A631A8, cx, y1, col[1], D_08938478,
                              func_0885151C(D_089CC438, D_089AC920[b3]));
                y2 = yy + 0x20;
                func_088915B0(D_08A631A8, cx, y2, col[5], D_08938478,
                              func_0885151C(D_089CC438, D_089AC934[b1]));
                func_088915B0(D_08A631A8, x16 + 0x54, yy + 0x30, col[2], D_08938548,
                              (*(u16 *)(item + 4) & 0xF) + 1);
                func_088915B0(D_08A631A8, x16 + 0x70, spy, col[3], D_08938478,
                              func_0885151C(D_089CC438, D_089AC954[(*(u16 *)(item + 4) & 0x40) ? 1 : 2]));
                k = -1;
                if (cat == 1) {
                    if (*(u16 *)(item + 4) & 0x20) {
                        k = 0x12;
                    } else if (*(u16 *)(item + 4) & 0x80) {
                        k = 0x13;
                    }
                } else {
                    if (*(u16 *)(item + 4) & 0x20) {
                        k = 3;
                    } else if (*(u16 *)(item + 4) & 0x10) {
                        k = 4;
                    }
                }
                if (k >= 0) {
                    func_088915B0(D_08A631A8, x16 + 0x8C, y1, col[4], D_08938478,
                                  func_0885151C(D_089CC438, D_089AC954[k]));
                }
                func_088232A0(arg0, item, x16 + 0x8C, y2, item2);
                ids = D_089AC904;
                col[3] = dim; col[2] = dim; col[1] = dim; col[0] = dim;
                colp = col;
                if (bits != 0) {
                    if (bits & 1) {
                        col[1] = 3;
                    }
                    if (bits & 6) {
                        col[2] = 3;
                    }
                }
            } else {
                func_088232A0(arg0, item, px, py + 0x10, item2);
                ids = D_089AC910;
            }
            break;
        }
        default: {
            u16 cx;
            s16 c;
            s32 yy;
            s32 y1;
            s32 y2;
            s32 y3;
            u16 x2;
            s16 xx;

            rec = func_0885CA50(D_08A62C54, item);
            dval = (u16)func_0885EAA4(D_08A62C54, item);
            col[6] = base;
            col[5] = base;
            col[4] = base;
            col[3] = base;
            col[2] = base;
            col[1] = base;
            col[0] = base;
            if (item2 != 0 && item[1] == item2[1]) {
                rec2 = func_0885CA50(D_08A62C54, item2);
                dval2 = (u16)func_0885EAA4(D_08A62C54, item2);
                if (dval2 < dval) {
                    col[0] = 4;
                } else if (dval < dval2) {
                    col[0] = 2;
                }
                if (*(u16 *)(item2 + 4) < *(u16 *)(item + 4)) {
                    col[1] = 4;
                } else if (*(u16 *)(item + 4) < *(u16 *)(item2 + 4)) {
                    col[1] = 2;
                }
                if (((s8 *)rec2)[0xD] < ((s8 *)rec)[0xD]) {
                    col[2] = 4;
                } else if (((s8 *)rec)[0xD] < ((s8 *)rec2)[0xD]) {
                    col[2] = 2;
                }
                if (((s8 *)rec2)[0xE] < ((s8 *)rec)[0xE]) {
                    col[3] = 4;
                } else if (((s8 *)rec)[0xE] < ((s8 *)rec2)[0xE]) {
                    col[3] = 2;
                }
                if (((s8 *)rec2)[0xF] < ((s8 *)rec)[0xF]) {
                    col[4] = 4;
                } else if (((s8 *)rec)[0xF] < ((s8 *)rec2)[0xF]) {
                    col[4] = 2;
                }
                if (((s8 *)rec2)[0x11] < ((s8 *)rec)[0x11]) {
                    col[5] = 4;
                } else if (((s8 *)rec)[0x11] < ((s8 *)rec2)[0x11]) {
                    col[5] = 2;
                }
                if (((s8 *)rec2)[0x10] < ((s8 *)rec)[0x10]) {
                    col[6] = 4;
                } else if (((s8 *)rec)[0x10] < ((s8 *)rec2)[0x10]) {
                    col[6] = 2;
                }
            }
            cx = x16 + 0x4D;
            c = cx;
            yy = py;
            func_088915B0(D_08A631A8, c, yy, col[0], D_08938594, dval);
            y1 = yy + 0x10;
            func_088915B0(D_08A631A8, c, y1, col[2], D_08938594, ((s8 *)rec)[0xD]);
            y2 = yy + 0x20;
            func_088915B0(D_08A631A8, c, y2, col[4], D_08938594, ((s8 *)rec)[0xF]);
            y3 = yy + 0x30;
            func_088915B0(D_08A631A8, c, y3, col[6], D_08938594, ((s8 *)rec)[0x10]);
            c = (u16)(cx + 0x70);
            func_088915B0(D_08A631A8, c, yy, col[1], D_08938594, *(u16 *)(item + 4) + 1);
            func_088915B0(D_08A631A8, c, y1, col[3], D_08938594, ((s8 *)rec)[0xE]);
            func_088915B0(D_08A631A8, c, y2, col[5], D_08938594, ((s8 *)rec)[0x11]);
            ids = D_089385D4;
            func_08890E38(D_08A631A8, dim);
            func_08891474(D_08A631A8, sx0, yy, D_08938478, func_0885151C(D_089CC438, D_089AC89C));
            func_08891474(D_08A631A8, sx0, y1, D_08938478, func_0885151C(D_089CC438, D_089AC8A0));
            func_08891474(D_08A631A8, sx0, y2, D_08938478, func_0885151C(D_089CC438, D_089AC8A4));
            func_08891474(D_08A631A8, sx0, y3, D_08938478, func_0885151C(D_089CC438, D_089AC8A8));
            x2 = px;
            xx = (u16)(x2 + 0x46);
            func_08891474(D_08A631A8, xx, yy, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            func_08891474(D_08A631A8, xx, y1, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            func_08891474(D_08A631A8, xx, y2, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            func_08891474(D_08A631A8, xx, y3, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            xx = (u16)(x2 + 0x70);
            func_08891474(D_08A631A8, xx, yy, D_08938478, func_0885151C(D_089CC438, D_089AC914));
            func_08891474(D_08A631A8, xx, y1, D_08938478, func_0885151C(D_089CC438, D_089AC8A2));
            func_08891474(D_08A631A8, xx, y2, D_08938478, func_0885151C(D_089CC438, D_089AC8A6));
            xx = (u16)(x2 + 0xB6);
            func_08891474(D_08A631A8, xx, yy, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            func_08891474(D_08A631A8, xx, y1, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            func_08891474(D_08A631A8, xx, y2, D_08938478, func_0885151C(D_089CC438, D_089AC8AA));
            break;
        }
        }
        func_08890E38(D_08A631A8, dim);
        func_08831274(arg0, sx0, py, ids, 0x10, colp);
        break;
    }
    case 1: {
        u16 x16;
        u16 y16;
        u16 yb;
        s32 yc;
        u8 sub;
        s16 spx;
        s16 syb;
        u8 *rec;

        spx = px;
        y16 = py;
        func_08820FB4(arg0, item, spx, (s16)(y16 + 0xA), flags & 0xFF);
        yb = y16 + 0x30;
        ids = D_089AC8F4;
        switch (item[1]) {
        case 6:
            ids = D_089AC8EC;
            txt = func_08851578(D_089CC438, *(u16 *)(item + 2));
            break;
        case 5:
            ids = D_089AC8EC;
            txt = func_0885154C(D_089CC438, *(u16 *)(item + 2));
            break;
        case 0:
            txt = func_08851654(D_089CC438, *(u16 *)(item + 2));
            break;
        case 4:
            txt = func_08851628(D_089CC438, *(u16 *)(item + 2));
            break;
        case 3:
            txt = func_088515FC(D_089CC438, *(u16 *)(item + 2));
            break;
        case 2:
            txt = func_088515D0(D_089CC438, *(u16 *)(item + 2));
            break;
        case 1:
            txt = func_088515A4(D_089CC438, *(u16 *)(item + 2));
            break;
        }
        syb = yb;
        func_08831274(arg0, spx, syb, ids, 0x10, 0);
        func_08890E40(D_08A631A8, 0x10);
        x16 = px;
        func_08892148(D_08A631A8, x16 + 0x1C, py, base, D_08938478, txt);
        if (*(u16 *)(item + 2) != 0) {
            switch (item[1]) {
            case 5:
            case 6:
                sub = item[1] - 5;
                break;
            default:
                rec = func_0885CA50(D_08A62C54, item);
                if ((rec[4] & 0xC) == 0xC) {
                    sub = 2;
                } else if (rec[4] & 4) {
                    sub = 0;
                } else {
                    sub = 1;
                }
                if (rec[0x13] >= 2) {
                    s32 yd = yb + 0x10;

                    func_08892148(D_08A631A8, x16 + 0x70 + offs[sel], yd, dim, D_08938478,
                                  func_0885151C(D_089CC438, D_089AC94C));
                    func_08892148(D_08A631A8, x16 + 0x9A, yd, base, D_08938478,
                                  func_0885151C(D_089CC438, D_089AC94A[rec[0x13]]));
                }
                break;
            }
            yc = func_08890E48(D_08A631A8, func_0885151C(D_089CC438, D_089AC8EC[0]));
            func_08891474(D_08A631A8, x16 + yc * 7, syb, D_08938478,
                          func_0885151C(D_089CC438, D_089AC944[sub]));
            yc = yb + 0x10;
            func_088915B0(D_08A631A8, x16 + 0x38, yc, hl, D_08938548, rarity + 1);
        } else {
            func_08891474(D_08A631A8, x16 + 0x70, syb, D_08938478, func_0885151C(D_089CC438, D_089AC95E));
            yc = yb + 0x10;
            func_08891474(D_08A631A8, x16 + 0x38, yc, D_08938478, func_0885151C(D_089CC438, D_089AC95E));
        }
        func_088226F0(arg0, arg6, item, x16 + 0x70, yc, item2);
        func_088229B8(arg0, item, px, yb + 0x20, noHl != 0);
        break;
    }
    case 2:
        func_0882148C(arg0, item, px, py, item2, flags & 0xFF);
        break;
    case 3: {
        s16 sx = px;
        u16 yb;

        func_08891474(D_08A631A8, sx, py, func_0885151C(D_089CC438, D_089AC8C6));
        yb = py + 0x10;
        if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
            if (item != 0) {
                if (item[1] != 6 && item[1] != 5) {
                    if (func_08826EF4(arg0, arg6, item) == 0) {
                        return;
                    }
                    if (noHl != 0) {
                        return;
                    }
                    if (func_08821B58(arg0, (u8 *)arg6 + item[1] * 12 + 0x4F4, item) != 0) {
                        goto fallback;
                    }
                    func_08838894(arg0, arg6, item, sx, yb);
                    return;
                } else {
                    if (func_08821B58(arg0, (u8 *)arg6 + 0x4E8, item) != 0) {
                        goto fallback;
                    }
                    func_08838894(arg0, arg6, item, sx, yb);
                    return;
                }
            }
            if (item2 != 0) {
                ItemRec tmp;

                tmp.a = ((ItemRec *)item2)->a;
                tmp.b = ((ItemRec *)item2)->b;
                tmp.c = ((ItemRec *)item2)->c;
                tmp.d = ((ItemRec *)item2)->d;
                tmp.v = ((ItemRec *)item2)->v;
                tmp.c = 0;
                tmp.v.z = 0;
                tmp.v.y = 0;
                tmp.v.x = 0;
                func_08838894(arg0, arg6, (u8 *)&tmp, sx, yb);
                return;
            }
        }
    fallback:
        func_0881B5C4(arg0, arg6, sx, yb);
        break;
    }
    case 4:
    case 5: {
        u8 *rec;
        u32 all;
        u32 mask;
        u32 add;
        u8 flag;
        s16 sy;
        s16 sx;
        u16 yy;
        s32 y1;
        s32 y2;
        s32 y3;
        s32 y4;

        func_08821890(arg0, arg6);
        func_08821A10(arg0, arg6, item);
        rec = func_0885CA50(D_08A62C54, item);
        mask = *(u32 *)(rec + 0x18);
        add = ~mask & func_088D7DE8(arg6);
        all = mask | add;
        flag = 0;
        if (func_088D6A1C(arg6, 0xAA) == 1) {
            flag = 1;
        }
        func_08821924(arg0, arg6);
        func_08890E38(D_08A631A8, dim);
        sy = py;
        sx = px;
        func_08890DFC(D_08A631A8, sx, sy);
        if (kind == 4) {
            func_08892004(D_08A631A8, D_08938478, func_0885151C(D_089CC438, D_089AC960));
            yy = py;
            y1 = yy + 0x10;
            func_08821D48(arg0, sx, y1, rec, all, add, 0, flag);
            y2 = yy + 0x20;
            func_08821D48(arg0, sx, y2, rec, all, add, 1, flag);
            y3 = yy + 0x30;
            func_08821D48(arg0, sx, y3, rec, all, add, 2, flag);
            y4 = yy + 0x40;
            func_08821D48(arg0, sx, y4, rec, all, add, 3, flag);
            func_08821D48(arg0, sx, yy + 0x50, rec, all, add, 4, flag);
            px = px + D_089385CA[arg7 * 2];
            func_088920A8(D_08A631A8, px + 0x2A, sy, D_08938478, func_0885151C(D_089CC438, D_089AC962));
            sx = px;
            func_08821D48(arg0, sx, y1, rec, all, add, 5, flag);
            func_08821D48(arg0, sx, y2, rec, all, add, 6, flag);
            func_08821D48(arg0, sx, y3, rec, all, add, 7, flag);
            func_08821D48(arg0, sx, y4, rec, all, add, 8, flag);
        } else {
            func_08892004(D_08A631A8, D_08938478, func_0885151C(D_089CC438, D_089AC964));
            yy = py;
            y1 = yy + 0x10;
            func_08821D48(arg0, sx, y1, rec, all, add, 9, flag);
            y2 = yy + 0x20;
            func_08821D48(arg0, sx, y2, rec, all, add, 10, flag);
            y3 = yy + 0x30;
            func_08821D48(arg0, sx, y3, rec, all, add, 11, flag);
            y4 = yy + 0x40;
            func_08821D48(arg0, sx, y4, rec, all, add, 12, flag);
            func_08821D48(arg0, sx, yy + 0x50, rec, all, add, 13, flag);
            sx = (u16)(px + 0x70);
            func_08821D48(arg0, sx, y1, rec, all, add, 14, flag);
            func_08821D48(arg0, sx, y2, rec, all, add, 15, flag);
            func_08821D48(arg0, sx, y3, rec, all, add, 16, flag);
            func_08821D48(arg0, sx, y4, rec, all, add, 17, flag);
        }
        break;
    }
    case 6:
    case 7: {
        u8 *rec;

        rec = func_0885CA50(D_08A62C54, item);
        if (kind == 6) {
            func_0882232C(arg0, rec, arg6, item, px, py);
        } else {
            func_08822594(arg0, rec, px, py, func_088D7F34(arg6));
        }
        break;
    }
    case 8:
    case 9:
        func_088915B0(D_08A631A8, px, py, dim, D_08938478, func_0885151C(D_089CC438, D_089AC974[kind]));
        func_08890E38(D_08A631A8, base);
        func_08822C58(arg0, item, px, py + 0x10, kind - 8, flags);
        break;
    case 10:
        func_088915B0(D_08A631A8, sx0 + 0x2A, sy0 + 0x10, 0, D_08938478, func_0885151C(D_089CC438, D_089AC8E6));
        break;
    }
}
