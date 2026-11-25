/* unit_088423E0: 0x088423E0-0x08842504 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s16 pad0[2];
    s16 x;
    s16 y;
} Rect;

extern Rect D_08939244;
extern Rect D_0893925C;

extern void func_0882B94C(char *, u16, u16, u8, u8, u8, s32, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);

void func_088423E0(char *p, u16 x, u16 y, u16 w, u8 r, u8 g, u8 b, u8 a) {
    Rect *l = (Rect *)(s32)&D_08939244;
    Rect *m = (Rect *)(s32)&D_0893925C;

    func_0882B94C(p, x, y, r, g, b, 0xFF, 0xD);
    func_0882C11C(p, x + l->x, y, (s16)(w - m->x - l->x), l->y, r, g, b, a, 0xE);
    func_0882B94C(p, x + w - m->x, y, r, g, b, 0xFF, 0xF);
}
