/* unit_0883DF88: 0x0883DF88-0x0883E400 (ULES01213)
 *
 * Draws a framed list page of 8 rows from 6-byte records (id, count,
 * value): the selected row (arg1 % 8 on the page of arg1) in colour 0/2,
 * the others in 10/13; each filled row shows the caption of the item, its
 * count (colour from byte 3 of its D_0899D198 record) and a value capped at
 * 999 between fullwidth brackets.
 *
 * .data 0x0893B430-0x0893B44C: the constants of the three initialised
 * locals (frame style 0x14 bytes, then the two 4-byte bracket strings).
 *
 * Optimized for speed. The page selection is a new local (sel) rather than
 * arg1 modified in place: this orders the box.unk18 store after the
 * subtraction and sets the saved registers. The row y is copied into an
 * s16 local at the top of each row. Declaration order sets the registers.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Box {
    u8 unk0[0xC];
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u8 unk12[6];
    s32 unk18;
    u8 unk1C[0xC];
} Box;

typedef struct Style {
    u16 a;
    u16 b;
    u8 c[4];
    u16 d;
    u16 e;
    s32 f;
    s32 g;
} Style;

typedef struct Rec {
    u16 id;
    u16 qty;
    u16 n;
} Rec;

extern char *D_089CC438;
extern char *D_08A631A8;
extern s32 D_08A62C50;
extern s32 D_09B23930;
extern u16 D_089AC870;
extern u16 D_089AC876;
extern char D_0893B218;
extern char D_0893B220;
extern char D_0893B44C;
extern char D_0893B458;
extern u8 D_0899D198[][24];

extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, Style *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, u16);
extern void func_08890E38(char *, s8);
extern void func_08890DFC(char *, s16, s16);
extern int func_0889134C(char *, char *, ...);
extern void func_08892004(char *, char *, ...);
extern s32 func_0885C498(s32, u16);
extern s32 func_09A92F88(s32, u16);

void func_0883DF88(char *arg0, s32 arg1, s32 arg2, s32 arg3, Rec *arg4, s32 arg5) {
    Style style = { 0x11E, 0x28, { 0xE, 0xE, 5, 3 }, 0x18, 8, 0, 0x8000C040 };
    char c0[4] = "\xEF\xBC\x88";
    char c1[4] = "\xEF\xBC\x89";
    char text[0x20];
    Box box;
    s32 first;
    s32 base;
    s32 sel;
    s32 n;
    s32 a;
    s32 q;
    s32 b;
    u16 y;
    s32 i;
    s16 yy;
    Rec *rec;

    first = arg1 / 8;
    base = first * 8;
    func_0880E8F0(text, &D_0893B218, func_0885151C(D_089CC438, D_089AC870));
    func_0882FA24(&box, &style, text, 0, 0);
    if (arg2 != 0) {
        sel = arg1 - base;
        box.unk18 = arg2;
    } else {
        sel = -1;
    }
    func_0882F580(arg0, &box, text, sel, 0xFF, 0);
    if (arg5 > 8) {
        q = arg5 / 8;
        if (arg5 % 8 != 0) {
            q++;
        }
        func_0882FB38(arg0, &box, first, q, 0, 0);
    }
    y = box.unkE;
    i = 0;
    rec = arg4 + base;
    for (; i < 8; i++, y += box.unk10, rec++) {
        if (arg2 == (s32)0x8000C040 || sel < 0) {
            a = 0;
            b = 2;
            if (arg3 == 1 && base + i < arg5 && (u8)func_09A92F88(D_09B23930, rec->id) == 0) {
                a = 10;
                b = 13;
            }
            if (arg3 == 2 && (arg2 == (s32)0x8000C040 || sel < 0)) {
                a = 10;
                b = 13;
            }
        } else if (i == sel) {
            a = 0;
            b = 2;
        } else {
            a = 10;
            b = 13;
        }
        func_08890E38(D_08A631A8, a);
        yy = y;
        func_08890DFC(D_08A631A8, box.unkC, yy);
        if (base + i >= arg5) {
            func_0889134C(D_08A631A8, &D_0893B220, func_0885151C(D_089CC438, D_089AC876));
        } else {
            func_0889134C(D_08A631A8, &D_0893B220, func_08851528(D_089CC438, rec->id));
            func_08890DFC(D_08A631A8, box.unkC + 0x72, yy);
            func_08892004(D_08A631A8, &D_0893B44C, rec->qty < D_0899D198[rec->id][3] ? a : b, rec->qty);
            func_08890DFC(D_08A631A8, box.unkC + 0x80, yy);
            n = rec->n < 999 ? rec->n : 999;
            if (func_0885C498(D_08A62C50, rec->id) > 0) {
                b = a;
            }
            func_08892004(D_08A631A8, &D_0893B458, a, c0, b, n, a, c1);
        }
    }
}
