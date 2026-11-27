/* unit_088C9380: 0x088C9380-0x088C95B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef union Bits {
    float f;
    u32 u;
} Bits;

extern u32 *D_089CC000;
extern s32 func_0886171C(s32, s32, char *, s32);

void func_088C9380(char *arg0, s32 arg1, u16 *arg2, s32 arg3) {
    u16 v;
    Bits a;
    Bits b;

    if (*arg2 & 0x100) {
        v = *(u16 *)(arg0 + 0x1C0);
        a.f = 0.25f * (float)(v & 3);
        b.f = 0.25f * (float)((v >> 2) & 3);
        *D_089CC000 = 0x4A000000 | (a.u >> 8);
        D_089CC000++;
        *D_089CC000 = 0x4B000000 | (b.u >> 8);
        D_089CC000++;
    } else if (*arg2 & 0x200) {
        Bits c;
        Bits d;
        v = *(u16 *)(arg0 + 0x1C0);
        c.f = 0.125f * (float)(v & 7);
        d.f = 0.125f * (float)((v >> 3) & 3);
        *D_089CC000 = 0x4A000000 | (c.u >> 8);
        D_089CC000++;
        *D_089CC000 = 0x4B000000 | (d.u >> 8);
        D_089CC000++;
    } else if (*arg2 & 0x400) {
        Bits e;
        Bits g;
        v = *(u16 *)(arg0 + 0x1C0);
        e.f = 0.125f * (float)(v & 7);
        g.f = 0.125f * (float)((v >> 3) & 7);
        *D_089CC000 = 0x4A000000 | (e.u >> 8);
        D_089CC000++;
        *D_089CC000 = 0x4B000000 | (g.u >> 8);
        D_089CC000++;
    }
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    *D_089CC000 = 0x4A000000;
    D_089CC000++;
    *D_089CC000 = 0x4B000000;
    D_089CC000++;
}
