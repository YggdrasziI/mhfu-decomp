/* unit_08857E74: 0x08857E74-0x08858008 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08857E74 (ULES01213)
 *
 * The flags at 0x34 are a 64-bit mask kept as two words (0x34 low, 0x38
 * high), rebuilt with a 64-bit add as in func_08857D88. The flag test at
 * D_08A631A0 + 0xF7A57C keeps its `sltu` only when compared as a 0/1 value.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern char *D_089CC438;
extern char *D_08A631A0;
extern s32 D_09A4F0C4;
extern char *func_08857C38(char *);
extern char *func_088DCEBC(s32, u8);
extern s32 func_088DADD8(char *);
extern u8 func_088D6A1C(char *, s32);

s32 func_08857E74(char *arg0, char *arg1, u8 arg2) {
    u32 r;
    u64 v;
    char *p;

    if (func_08857C38(arg0) != 0 && arg2 == 0 &&
        (s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0 &&
        func_088DCEBC(D_09A4F0C4, 1) != 0) {
        r = (u16)func_088DADD8(func_088DCEBC(D_09A4F0C4, 1));
    } else {
        r = (u32)*(float *)(arg1 + 0x18) + *(u8 *)(arg1 + 0x4C);
        if (*(s16 *)(arg1 + 0x2A) == 0x1B58) {
            r += 0x14;
        }
        v = *(u32 *)(arg1 + 0x34) + ((u64)*(u32 *)(arg1 + 0x38) << 32);
        if (v & 0x400000) r += 0x14;
        if (v & 0x20000000) r += 0x1E;
        if (v & 0x100000000ULL) r += 0x32;
        p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        if (p != 0) {
            if (func_088D6A1C(p, 0xC0) == 1) r += 0x28;
        }
    }
    return r;
}
