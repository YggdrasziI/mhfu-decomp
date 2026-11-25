/* unit_08847B74: 0x08847B74-0x08847CB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08847B74 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 a;
    s16 b;
} Ent;

typedef struct {
    char pad0[0x390];
    Ent ent[32];
    u32 bits[8];
} G;

extern "C" {
extern G *D_089CC438;
extern char *D_08A631A0;
extern s32 D_09A1DAEC;

void func_0884860C(char *arg0, char *arg1);
void func_088AB6D0(s32, s32, void *);
s32 func_088D72A4(char *, u16, s16, s32);
void func_0884853C(char *, s32, s32);

void func_08847B74(char *arg0, char *arg1) {
    G *g = D_089CC438;
    u8 buf[12];
    s32 idx;

    arg1[0x55E] = 0x1E;
    func_0884860C(arg0, arg1);
    if ((bool)(*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
        *(s16 *)(arg1 + 0x5EC) = 0x708;
        *(u32 *)(arg1 + 0x614) |= 0x10000;
        buf[1] = *(u8 *)(arg1 + 0x55D);
        func_088AB6D0(D_09A1DAEC, 1, buf);
        *(u8 *)(arg1 + 0x5EE) = *((u8 *)D_089CC438 + 0x420);
    } else {
        *(s16 *)(arg1 + 0x5EC) = 0;
        *(u32 *)(arg1 + 0x614) &= ~0x10000;
        func_088D72A4(arg1, g->ent[*(u8 *)(arg1 + 0x55D)].a,
                      g->ent[*(u8 *)(arg1 + 0x55D)].b, 0);
        idx = *(u8 *)(arg1 + 0x55D);
        g->bits[(u32)(u8)idx >> 5] |= 1 << (idx % 32);
        func_0884853C(arg0, g->ent[*(u8 *)(arg1 + 0x55D)].a, *(u8 *)(arg1 + 0x55D));
    }
}
}
