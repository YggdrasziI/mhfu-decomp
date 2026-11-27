/* unit_0881B5F8: 0x0881B5F8-0x0881B7F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_0881B5F8: draws up to 6 entries from the bytes at 0x676 of a record. */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089ACD38[];
extern char D_08938478;

extern char *func_0885151C(char *, u16);
extern void func_08890DE8(char *, s8, u8);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);
extern s32 func_08827BF4(char *, u8 *, u8);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);

void func_0881B5F8(char *a, u8 *p, s16 x, s16 y, s8 *kind)
{
    s8 c;
    s32 i;
    s32 bx;

    func_08890DE8(D_08A631A8, 14, 13);
    if ((p[0x676] | p[0x677] | p[0x678] | p[0x679] | p[0x67A]) == 0) {
        func_088915B0(D_08A631A8, x, y, 0, &D_08938478,
                      func_0885151C(D_089CC438, D_089ACD38[0]));
        return;
    }
    i = 0;
    bx = x - 8;
    for (; i < 6; i++) {
        if (p[(u8)i + 0x676] == 0) {
            continue;
        }
        if ((u8)func_08827BF4(a, p, i) == 1) {
            c = kind[i];
        } else {
            c = 9;
        }
        func_088915B0(D_08A631A8, x, y, c, &D_08938478,
                      func_0885151C(D_089CC438, D_089ACD38[p[(u8)i + 0x676]]));
        if (kind[i] == 14 || kind[i] == 2) {
            func_0882C7B4(a, bx, y + 1, 6, 12, 0xD0, 0xD0, 0xD0, 0xC0, 0x8E, 0);
        }
        y += 14;
    }
}
