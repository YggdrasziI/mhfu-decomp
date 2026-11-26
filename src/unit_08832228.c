/* unit_08832228: 0x08832228-0x08832548 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08832228: nine-piece frame drawn with the D_0893997C corner sizes;
 * opaque (a == 0xFF) or tinted with alpha a. */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
} Rect;

extern Rect D_0893997C;

extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882AC18(char *, u16, u16, u16, u16, s32);
extern void func_0882B94C(char *, u16, u16, u8, u8, u8, u8, s32);
extern void func_0882AD70(char *, u16, u16, u16, u16, u8, u8, u8, u8, s32);

void func_08832228(char *p, u16 x, u16 y, u16 w, u16 h, u8 a) {
    Rect *m = (Rect *)(s32)&D_0893997C;
    s32 x1 = x + m->x4;
    s32 x2 = x + w - m->x4;
    u16 cw = w - m->x4 - m->x4;
    s32 y1 = y + m->x6;
    s32 y2 = y + h - m->x6;
    u16 ch = h - m->x6 - m->x6;

    if (a == 0xFF) {
        func_0882A9DC(p, x, y, 0xA7);
        func_0882AC18(p, x1, y, cw, m->x6, 0x1B5);
        func_0882A9DC(p, x2, y, 0xA8);
        func_0882AC18(p, x, y1, m->x4, ch, 0xA9);
        func_0882AC18(p, x1, y1, cw, ch, 0xAD);
        func_0882AC18(p, x2, y1, m->x4, ch, 0xAA);
        func_0882A9DC(p, x, y2, 0xAB);
        func_0882AC18(p, x1, y2, cw, m->x6, 0x1B6);
        func_0882A9DC(p, x2, y2, 0xAC);
    } else {
        func_0882B94C(p, x, y, 0xFF, 0xFF, 0xFF, a, 0xA7);
        func_0882AD70(p, x1, y, cw, m->x6, 0xFF, 0xFF, 0xFF, a, 0x1B5);
        func_0882B94C(p, x2, y, 0xFF, 0xFF, 0xFF, a, 0xA8);
        func_0882AD70(p, x, y1, m->x4, ch, 0xFF, 0xFF, 0xFF, a, 0xA9);
        func_0882AD70(p, x1, y1, cw, ch, 0xFF, 0xFF, 0xFF, a, 0xAD);
        func_0882AD70(p, x2, y1, m->x4, ch, 0xFF, 0xFF, 0xFF, a, 0xAA);
        func_0882B94C(p, x, y2, 0xFF, 0xFF, 0xFF, a, 0xAB);
        func_0882AD70(p, x1, y2, cw, m->x6, 0xFF, 0xFF, 0xFF, a, 0x1B6);
        func_0882B94C(p, x2, y2, 0xFF, 0xFF, 0xFF, a, 0xAC);
    }
}
