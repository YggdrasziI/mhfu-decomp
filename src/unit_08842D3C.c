/* unit_08842D3C: 0x08842D3C-0x08842EE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Slot;

extern char D_0893AA5C[];
extern char D_0893B5F8;
extern u8 D_0899D19E[];
extern s32 D_089CC438;
extern char *D_08A631A8;

extern int func_0880E8F0(char *, char *, ...);
extern s32 func_0882A9DC(s32, s32, s32, s32);
extern void func_0882BE60(char *, u16, s32, s32, s32, s32, s32, s32, s32);
extern Slot *func_08856884(s32, s32);
extern void func_0889198C(char *, s32, s32, s32, s32, char *, s32, s32);

void func_08842D3C(char *arg0) {
    char text[0x10];
    char *p = *(char **)(arg0 + 0x530);

    if (*(u8 *)(p + 0x5F6) != 0xFF) {
        Slot *slot = func_08856884(D_089CC438, 0) + *(u8 *)(p + 0x5F6);
        u8 *color = (u8 *) &D_0893AA5C[D_0899D19E[slot->unk0 * 0x18] * 4];
        u8 tens = slot->unk2 / 10;
        u8 ones = slot->unk2 % 10;
        u16 x;
        s32 r;
        s32 g;
        s32 b;

        if (tens != 0) {
            r = color[0];
            g = color[1];
            b = color[2];
        } else {
            r = g = b = 0x80;
        }
        func_0882BE60(arg0, 0x3C, 0x1E, 0x12, 0x10, r, g, b, 0x176);
        func_0880E8F0(text, &D_0893B5F8, tens);
        func_0889198C(D_08A631A8, 0x50, 0x1E, 1, 0, text, 1, 2);
        for (x = 0x78; ones > 0; ones--) {
            func_0882BE60(arg0, x, 0x1E, 0xC, 0x10, color[0], color[1], color[2], 0x175);
            x += 0xE;
        }
    } else {
        func_0882A9DC((s32) arg0, 0x3C, 0x20, 0x17E);
    }
}