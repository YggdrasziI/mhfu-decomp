/* unit_0882DCB0: 0x0882DCB0-0x0882E0D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Nine-piece frame drawn from the sprites idx..idx+8 of
 * D_089391A8; opaque (a == 0xFF) or tinted with alpha a.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
    /* 0x4 */ s16 w;
    /* 0x6 */ s16 h;
    /* 0x8 */ u16 u;
    /* 0xA */ u16 v;
} Sprite;

extern Sprite D_089391A8[];

extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882AC18(char *, u16, u16, u16, u16, s32);
extern void func_0882B94C(char *, u16, u16, u8, u8, u8, u8, s32);
extern void func_0882AD70(char *, u16, u16, u16, u16, u8, u8, u8, u8, s32);

void func_0882DCB0(char *p, u16 x, u16 y, u16 w, u16 h, u8 a, s32 idx) {
    Sprite *s = &D_089391A8[idx];
    s32 x1;
    s32 xw;
    s32 y2;

    if (a == 0xFF) {
        x1 = x + s->w;
        func_0882A9DC(p, x, y, idx);
        func_0882AC18(p, x1, y, w - s->w * 2, s->h, idx + 1);
        xw = x + w;
        func_0882A9DC(p, xw - s->w, y, idx + 2);
        func_0882AC18(p, x, y + s->h, s->w, h - s->h * 2, idx + 3);
        func_0882AC18(p, xw - s->w, y + s->h, s->w, h - s->h * 2, idx + 4);
        func_0882AC18(p, x1, y + s->h, w - s->w * 2, h - s->h * 2, idx + 8);
        y2 = y + h - s->h;
        func_0882A9DC(p, x, y2, idx + 5);
        func_0882AC18(p, x1, y2, w - s->w * 2, s->h, idx + 6);
        func_0882A9DC(p, xw - s->w, y2, idx + 7);
    } else {
        x1 = x + s->w;
        func_0882B94C(p, x, y, 0xFF, 0xFF, 0xFF, a, idx);
        func_0882AD70(p, x1, y, w - s->w * 2, s->h, 0xFF, 0xFF, 0xFF, a, idx + 1);
        xw = x + w;
        func_0882B94C(p, xw - s->w, y, 0xFF, 0xFF, 0xFF, a, idx + 2);
        func_0882AD70(p, x, y + s->h, s->w, h - s->h * 2, 0xFF, 0xFF, 0xFF, a, idx + 3);
        func_0882AD70(p, xw - s->w, y + s->h, s->w, h - s->h * 2, 0xFF, 0xFF, 0xFF, a, idx + 4);
        func_0882AD70(p, x1, y + s->h, w - s->w * 2, h - s->h * 2, 0xFF, 0xFF, 0xFF, a, idx + 8);
        y2 = y + h - s->h;
        func_0882B94C(p, x, y2, 0xFF, 0xFF, 0xFF, a, idx + 5);
        func_0882AD70(p, x1, y2, w - s->w * 2, s->h, 0xFF, 0xFF, 0xFF, a, idx + 6);
        func_0882B94C(p, xw - s->w, y2, 0xFF, 0xFF, 0xFF, a, idx + 7);
    }
}
