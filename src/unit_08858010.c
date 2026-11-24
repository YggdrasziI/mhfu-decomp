/* unit_08858010: 0x08858010-0x08858184 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

extern char *func_08857C38(char *arg0);
extern char *func_088DCEBC(s32, u8);
extern u8 func_088D6A1C(char *, s32);
extern char *D_08A631A0;
extern s32 D_09A4F0C4;
extern char *D_089CC438;

u32 func_08858010(char *arg0, char *arg1, s32 arg2) {
    u32 r;
    u64 v;

    if (func_08857C38(arg0) != 0 && (u8)arg2 == 0
        && (s32)((*(s32 *)(D_08A631A0 + 0xF80000 - 0x5A84) & 1) != 0) == 0
        && func_088DCEBC(D_09A4F0C4, 1) != 0) {
        r = *(u16 *)(func_088DCEBC(D_09A4F0C4, 1) + 0x422);
        goto end;
    }
    r = (u32)*(float *)(arg1 + 0x1C) + *(u8 *)(arg1 + 0x4D);
    if (*(short *)(arg1 + 0x2A) == 7000) {
        r += 0x14;
    }
    v = *(u32 *)(arg1 + 0x34) + ((u64)*(u32 *)(arg1 + 0x38) << 32);
    if (v & 0x800000) {
        r += 0x1E;
    }
    if (v & 0x100000000ULL) {
        r += 0x32;
    }
    {
        char *p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        if (p != 0) {
            if (func_088D6A1C(p, 0xC1) == 1) {
                r += 0x3C;
            }
        }
    }
end:
    return r;
}
