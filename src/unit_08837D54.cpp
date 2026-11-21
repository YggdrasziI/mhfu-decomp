/* unit_08837D54: 0x08837D54-0x08838004 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_088351F0 and text_08838004).
 *
 * C++. The rectangle is an initialised local; its constant is the unit's
 * .data (0x0893B270-0x0893B278). Optimized for speed: the divisions by 100
 * and 10 are multiplications.
 *
 * The address of the record table D_08939850 is kept in $s3 for both calls:
 * the pointer is set through an integer cast; a plain `&D_08939850[0]` is
 * folded into each read (notes/MATCHING.md).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rect {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect;

extern "C" {


extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B04E1E;
extern char D_0893B278;
extern char D_0893B280;
extern char D_0893B28C;
extern char D_0893B220;
typedef struct Rec12 { s16 x; s16 y; s16 w; s16 h; s16 unk8; s16 unkA; } Rec12;
extern Rec12 D_08939850[];

extern s32 func_08838004(char *);
extern char *func_09A7B790(s32, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern void func_08890DFC(char *, s16, s16);
extern int func_0889134C(char *, char *, ...);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);

static inline void draw_rect(char *a0, u16 x, u16 y, Rec12 *rec, u8 *c, s32 flag) {
    func_0882C7B4(a0, x, y, rec->w, rec->h, c[2], c[1], c[0], c[3], 0x8E, flag);
}

void func_08837D54(char *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    char text[0x80];
    s32 color;
    s32 n;
    s32 y;
    Rec12 *p;

    color = func_08838004(arg0);
    if (arg4 / 100 != 0) {
        n = 2;
    } else if (arg4 / 10 != 0) {
        n = 1;
    } else {
        n = 0;
    }
    switch (n) {
    case 0:
        func_0880E8F0(text, &D_0893B278, arg3 + 1, func_09A7B790(D_09B22D70, D_09B04E1E), arg4);
        break;
    case 1:
        func_0880E8F0(text, &D_0893B280, arg3 + 1, func_09A7B790(D_09B22D70, D_09B04E1E), arg4);
        break;
    case 2:
        func_0880E8F0(text, &D_0893B28C, arg3 + 1, func_09A7B790(D_09B22D70, D_09B04E1E), arg4);
        break;
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_08890DFC(D_08A631A8, arg1, arg2);
    func_0889134C(D_08A631A8, &D_0893B220, text);
    if (arg4 <= 1) {
        return;
    }
    u16 r[4] = {0x10, 0, 0x18, 0xE};

    p = (Rec12 *) (s32) &D_08939850[0];
    y = arg2 - r[1];
    draw_rect(arg0, arg1 - r[0], y, p, (u8 *)&color, 1);
    draw_rect(arg0, arg1 + r[2] + r[3] * n, y, p, (u8 *)&color, 0);
}

}
