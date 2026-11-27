/* unit_0882E604: 0x0882E604-0x0882E6F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Draws record D_08939850 (tile 0x8E) twice: with func_0882C7B4 (flag 1)
 * at (x, y), then with func_0882C11C at (x + dx, y), same colour.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 w;
    /* 0x6 */ s16 h;
} Rec;

extern Rec D_08939850;

extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);

void func_0882E604(char *arg0, u16 x, u16 y, u16 dx, u8 r, u8 g, u8 b, u8 a) {
    Rec *p = (Rec *)(s32)&D_08939850;

    func_0882C7B4(arg0, x, y, p->w, p->h, r, g, b, a, 0x8E, 1);
    func_0882C11C(arg0, x + dx, y, p->w, p->h, r, g, b, a, 0x8E);
}
