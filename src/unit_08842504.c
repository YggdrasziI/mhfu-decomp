/* unit_08842504: 0x08842504-0x08842628 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08842504: the table pointers go through an integer cast so that they
 * stay in saved registers; the alpha argument of func_0882C11C is u8, which
 * loads the spilled parameter before the table halfword. */

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

extern Rect D_08939244;
extern Rect D_0893925C;

extern void func_0882B94C(char *, u16, u16, u8, u8, u8, s32, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);

void func_08842504(char *p, u16 x, u16 y, u16 w, u8 r, u8 g, u8 b, u8 a) {
    Rect *s = (Rect *)(s32)&D_08939244;
    Rect *t = (Rect *)(s32)&D_0893925C;

    func_0882B94C(p, x, y, r, g, b, 0xFF, 0x20C);
    func_0882C11C(p, x + s->x4, y, (s16)(w - t->x4 - s->x4), s->x6, r, g, b, a, 0x20D);
    func_0882B94C(p, x + w - t->x4, y, r, g, b, 0xFF, 0x20E);
}
