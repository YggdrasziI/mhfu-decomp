/* unit_0882232C: 0x0882232C-0x08822594 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08821BD4 and text_08822594).
 *
 * Optimized for speed: the loop is guarded and rotated, its constants hoisted.
 *
 * NonMatching: func_0882232C 94.7 %. func_08892148 is variadic here (93.4 %
 * with eight fixed parameters). Register allocation differs: the
 * original keeps x in $s0 until the loop and a sign-extended copy in $s7,
 * keeps the loop constant 3 in $a0 (set again in each delay slot) and so has
 * every saved register taken; ours keeps 3 in a saved register and shifts the
 * others. Tried: s16 / s32 types for x and the colour, declaration orders
 * (greedy pairwise search), local copies, x kept as a
 * sign-extended s32.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AC97E;
extern u16 D_089AC954[];
extern u16 D_089AC9DC[];
extern s8 D_08978E38[][4];
extern char D_08938478;
extern char D_089385EC;

extern char *func_0885151C(char *, u16);
extern void func_088915B0(char *, s16, s16, s32, char *, ...);
extern void func_08821890(char *, s32);
extern void func_08821A10(char *, s32, s32);
extern u8 func_088D6A1C(s32, s32);
extern int func_0880E8F0(char *, char *, ...);
extern int func_0880ED70(char *, char *);
extern void func_08892148(char *, s16, s16, s32, char *, ...);
extern void func_08821924(char *, s32);

void func_0882232C(char *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, u16 y) {
    char text[8];
    char name[8];
    s32 n;
    s32 i;
    s8 c;
    s32 w;
    char *label;
    s16 x = arg4;

    func_088915B0(D_08A631A8, x, y, 5, &D_08938478, func_0885151C(D_089CC438, D_089AC97E));
    func_08821890(arg0, arg2);
    n = 3;
    func_08821A10(arg0, arg2, arg3);
    if (arg1[0xB] == 4) {
        n++;
    } else if (arg1[0xB] == 2) {
        if (func_088D6A1C(arg2, 0xAA) == 0) {
            n--;
        }
    } else if (func_088D6A1C(arg2, 0xAA) == 1) {
        n++;
    }
    y += 0x10;
    for (i = 0; i < n; i++) {
        if (i == 3 && arg1[0xB] != 4) {
            c = 3;
            w = c;
        } else if (i == 2 && arg1[0xB] == 2) {
            c = 3;
            w = c;
        } else {
            w = 6;
            c = 0;
        }
        func_0880E8F0(text, &D_089385EC, i + 1);
        func_0880ED70(name, text);
        label = func_0885151C(D_089CC438, D_089AC954[i == 0 ? 0x16 : 0x17]);
        func_08892148(D_08A631A8, x, y, w, label, name, (s8) c, func_0885151C(D_089CC438, D_089AC9DC[D_08978E38[*(u8 *)(arg1 + 0x10)][i]]));
        y += 0x10;
    }
    func_08821924(arg0, arg2);
}