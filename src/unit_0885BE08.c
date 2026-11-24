/* unit_0885BE08: 0x0885BE08-0x0885C0F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_0885BE08: computes a percentage (capped at 100) for arg1: -1 when
 * func_0885B160 refuses, 100 on two flag/skill checks, else a base value from
 * D_089A5B58 adjusted by func_088D6AC8/func_088D6A54 results and by the count
 * of leading D_089A5B60 entries found (D_089A5B6C bonus).
 * Speed setting needed (the two search loops step a pointer).
 * The flag must be written as a ternary `(arg2 == 1) ? 1 : 0` in the same
 * local as the later value: it then lives in s0 across the first call.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern u8 D_089A5B58[];
extern u16 D_089A5B60[];
extern u8 D_089A5B6C[];

extern char *func_088DCEBC(s32, u8);
extern u8 func_0885B160(s32, char *, u8 *, s32);
extern u8 func_088D6A1C(char *, s32);
extern u8 func_088D6AC8(char *, s32);
extern s32 func_088D6A54(char *, s32);
extern s32 func_088568AC(char *, u16);
extern u16 func_0885BD0C(s32, s32);

s8 func_0885BE08(s32 arg0, u8 *arg1, s32 arg2) {
    s32 v;
    char *p;
    u32 i;
    s32 found;

    v = (arg2 == 1) ? 1 : 0;
    p = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
    if (func_0885B160(arg0, p, arg1, v) != 1) {
        return -1;
    }
    if (arg1[7] & 2) {
        if (func_088D6A1C(p, 0x45) == 1) {
            return 100;
        }
    }
    if (arg1[7] & 0x10) {
        if (func_088D6A1C(p, 0xC2) == 1) {
            return 100;
        }
    }
    v = D_089A5B58[(s8)arg1[4]];
    switch (func_088D6AC8(p, 0x3B)) {
    case 0x99: v = (u8)(v + 15); break;
    case 0x9A: v = (u8)(v + 25); break;
    case 0x9B: v = (u8)(v + 45); break;
    case 0x9C: v = (u8)(v - 5); break;
    case 0x9D: v = (u8)(v - 10); break;
    case 0x9E: v = (u8)(v - 15); break;
    }
    if (func_088D6A54(p, 0xF)) {
        v = (u8)(v + 10);
    }
    if (func_088D6A54(p, 0x10)) {
        v = (u8)(v + 5);
    }
    if (arg2 == 0) {
        for (i = 0; i < 5; i++) {
            if (func_088568AC(D_089CC438, D_089A5B60[i]) == 0) {
                break;
            }
        }
        v = (u8)(v + D_089A5B6C[i]);
    }
    if (arg2 == 1) {
        for (i = 0; i < 5; i++) {
            found = 0;
            if (func_088568AC(D_089CC438, D_089A5B60[i]) != 0) {
                found = 1;
            }
            if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
                if (func_0885BD0C(arg0, D_089A5B60[i]) != 0xFFFF) {
                    found = 1;
                }
            }
            if (!(u8)found) {
                break;
            }
        }
        v = (u8)(v + D_089A5B6C[i]);
    }
    if ((u8)v > 100) {
        v = 100;
    }
    return v;
}
