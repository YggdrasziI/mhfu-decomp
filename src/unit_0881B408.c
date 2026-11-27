/* unit_0881B408: 0x0881B408-0x0881B5C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881B408 (ULES01213)
 *
 * Speed setting. Draws a header line and five rows (indices from D_0893AEB8,
 * read as bytes with a 4-byte stride) through func_08831338 / func_088920A8.
 *
 * D_08938598 is const: its x load in the loop is then scheduled above the
 * stack argument store (sw zero, 0(sp)). The row y is passed as (u16)y to an
 * s32 parameter (andi), the text y as s16; the loop steps are split between
 * the body and the for header to match the original order.
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    s16 v[3];
} Rec;

typedef struct Big {
    u8 unk0[0x4E8];
    Rec main;
    Rec sub[5];
} Big;

typedef struct Pos {
    u16 x;
    s16 y;
} Pos;

typedef struct Size {
    u16 unk0;
    u16 unk2;
    u16 w;
    u16 h;
} Size;

extern const Pos D_08938598[];
extern s16 D_0893859A[];
extern Size D_08939700;
extern u8 D_0893AEB8[];
extern u16 D_089AC8E0;
extern u16 D_089AC8E2;
extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C54;

extern void func_08831338(char *, s32, s16, u16, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern char *func_0885C968(char *, u8, u16);
extern void func_088920A8(char *, s32, s16, char *, ...);

void func_0881B408(char *arg0, Big *arg1, s32 arg2) {
    s16 y;
    s16 ty;
    const Pos *pos;
    Size *sz;
    s32 i;
    u8 *idx;
    char *e;
    u16 *c;
    const s16 *py;

    pos = &D_08938598[arg2];
    sz = (Size *)(s32)&D_08939700;
    func_08831338(arg0, arg1->main.b, arg1->main.c, pos->x, 0x44, sz->w, sz->h, 0xFF, 0);
    func_088920A8(D_08A631A8, D_0893859A[arg2 * 2], 0x4A, func_0885151C(D_089CC438, D_089AC8E0),
                  func_0885C968(D_08A62C54, arg1->main.b, arg1->main.c));
    y = 0x5E;
    ty = 0x64;
    i = 0;
    idx = D_0893AEB8;
    py = &pos->y;
    for (; i < 5; idx += 4) {
        e = (char *)arg1 + *idx * 12;
        c = (u16 *)(e + 0x4F6);
        func_08831338(arg0, *idx, *c, pos->x, (u16)y, sz->w, sz->h, 0xFF, 0);
        func_088920A8(D_08A631A8, *py, ty, func_0885151C(D_089CC438, D_089AC8E2), func_0885C968(D_08A62C54, *(u8 *)(e + 0x4F5), *c));
        y += 0x1A;
        i++;
        ty += 0x1A;
    }
}
