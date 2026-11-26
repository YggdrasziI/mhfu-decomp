/* unit_0883D6D0: 0x0883D6D0-0x0883DF88 (ULES01213)
 *
 * Draws a detail panel for one record (e): two frames, an icon, then
 * label / value rows, the value columns only when the record is set
 * (*(s8 *)e != 0).
 *
 * .data 0x0893B414-0x0893B42C: the constants of the initialised local
 * (u16[6][2]).
 *
 * Optimized for speed (row loop with a stepped table pointer). The x of
 * the loop rows is an invariant sum masked inside the loop: a u32 local
 * masked in place (`xx &= 0xFFFF`), copied into the u16 x before the text
 * call when it must survive that call.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B04DE0;
extern u16 D_09B054E0[];
extern u16 D_09B054E2;
extern u16 D_09B054E4;
extern u16 D_09B054E6;
extern u16 D_09B054E8;
extern u16 D_09B05300[];
extern u16 D_09B05480[];
extern u16 D_089ACEEC[];
extern s8 D_09CCF418[][8];
extern s8 D_09CCF41F[][8];
extern char D_0893B220[];
extern char D_0893B42C[];

extern void func_0881A9D8(char *, s8);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern void func_0882DCA0(char *, u16, s32, u16, u16, s32);
extern char *func_0885151C(char *, u16);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890DFC(char *, s16, s16);
extern void func_08890E38(char *, s8);
extern void func_08891474(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);
extern void func_09A7BF18(s32, s32, char *);

void func_0883D6D0(char *arg0, u16 arg1, s32 arg2, char *e) {
    u16 a[6][2] = { { 0xE0, 0x8E }, { 8, 8 }, { 0x20, 0xD }, { 8, 0x28 }, { 0xE0, 0x50 }, { 8, 0x98 } };
    char buf[32];
    s8 col;
    u16 h;
    s32 y0;
    s32 x0;
    s32 xb;
    s32 yb;
    u16 x;
    u16 y;
    char *text;
    s32 i;
    s32 n;
    s32 v;
    u32 xx;

    if (*(s8 *)e == 0) {
        col = 9;
    } else {
        col = 5;
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    h = a[0][1];
    func_0882DCA0(arg0, arg1, arg2, a[0][0], h, 0xFF);
    x0 = arg1;
    y0 = (u16) arg2;
    x = x0 + (u16) a[1][0];
    y = y0 + (u16) a[1][1];
    if (*(s8 *)e != 0) {
        func_0882BE60(arg0, x, y, 0x18, 0x18, 0xFF, 0xFF, 0xFF, 0xEF);
    } else {
        func_0882BE60(arg0, x, y, 0x18, 0x18, 0x7F, 0x7F, 0x7F, 0xEF);
    }

    x = x0 + (u16) a[2][0];
    y = y0 + (u16) a[2][1];
    text = func_09A7B790(D_09B22D70, D_09B04DE0);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_0893B220, text);
    if (*(s8 *)e != 0) {
        text = func_09A7B790(D_09B22D70, D_09B05300[*(u8 *)(e + 1)]);
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0xE), y, D_0893B220, text);
    }

    xb = x0 + (u16) a[3][0];
    yb = y0 + (u16) a[3][1];
    x = xb;
    y = yb;
    text = func_09A7B790(D_09B22D70, D_09B054E0[0]);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_0893B220, text);
    text = func_09A7B790(D_09B22D70, D_09B04DE0);
    func_08891474(D_08A631A8, (u16) (x + 0x46), y, D_0893B220, text);
    if (*(s8 *)e != 0) {
        func_09A7BF18(D_09B22D70, *(s8 *)(e + 3), buf);
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0x54), y, D_0893B220, buf);
    }

    x = xb;
    y = yb + 0x10;
    text = func_09A7B790(D_09B22D70, D_09B054E2);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_0893B220, text);
    text = func_09A7B790(D_09B22D70, D_09B04DE0);
    func_08891474(D_08A631A8, (u16) (x + 0x46), y, D_0893B220, text);
    if (*(s8 *)e != 0) {
        func_08890E38(D_08A631A8, 0);
        for (i = 0, n = 0; i < 7; i++) {
            v = D_09CCF418[*(s8 *)(e + 6)][i];
            if (v != 0) {
                y += (u16) n;
                xx = xb + 0x54;
                xx &= 0xFFFF;
                x = xx;
                text = func_09A7B790(D_09B22D70, D_09B054E0[i + 5]);
                func_08891474(D_08A631A8, x, y, D_0893B220, text);
                xx = xb + 0x93;
                xx &= 0xFFFF;
                func_08890DFC(D_08A631A8, xx, y);
                func_0881A9D8(D_089CBBEC, v);
                n += 0x10;
            }
        }
    }

    x = xb;
    y = yb + 0x40;
    text = func_09A7B790(D_09B22D70, D_09B054E4);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_0893B220, text);
    text = func_09A7B790(D_09B22D70, D_09B04DE0);
    func_08891474(D_08A631A8, (u16) (x + 0x46), y, D_0893B220, text);
    if (*(s8 *)e != 0) {
        func_08890E38(D_08A631A8, 0);
        v = D_09CCF41F[*(s8 *)(e + 6)][0];
        if (v != 0) {
            func_08890DFC(D_08A631A8, (u16) (x + 0x54), y);
            func_0881A9D8(arg0, v);
        } else {
            func_08891474(D_08A631A8, (u16) (x + 0x54), y, D_0893B220, D_0893B42C);
        }
    }

    text = func_09A7B790(D_09B22D70, D_09B054E6);
    x = xb;
    y = yb + 0x50;
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_0893B220, text);
    text = func_09A7B790(D_09B22D70, D_09B04DE0);
    func_08891474(D_08A631A8, (u16) (x + 0x46), y, D_0893B220, text);
    if (*(s8 *)e != 0) {
        text = func_09A7B790(D_09B22D70, D_09B05480[*(s8 *)(e + 2)]);
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (u16) (x + 0x54), y, D_0893B220, text);
    }

    func_0882DCA0(arg0, arg1, (u16) (y0 + h), a[4][0], a[4][1], 0xFF);
    x = x0 + (u16) a[5][0];
    y = y0 + (u16) a[5][1];
    text = func_09A7B790(D_09B22D70, D_09B054E8);
    func_08890E38(D_08A631A8, col);
    func_08891474(D_08A631A8, x, y, D_0893B220, text);
    if (*(s8 *)e != 0) {
        func_08890E38(D_08A631A8, 0);
        text = func_0885151C(D_089CC438, D_089ACEEC[*(s8 *)(e + 7)]);
        func_08891474(D_08A631A8, x, (u16) (y + 0x10), D_0893B220, text);
        text = func_0885151C(D_089CC438, D_089ACEEC[*(s8 *)(e + 8)]);
        func_08891474(D_08A631A8, x, (u16) (y + 0x20), D_0893B220, text);
        text = func_0885151C(D_089CC438, D_089ACEEC[*(s8 *)(e + 9)]);
        func_08891474(D_08A631A8, x, (u16) (y + 0x30), D_0893B220, text);
    }
}
