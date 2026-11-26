/* unit_0883D40C: 0x0883D40C-0x0883D4F0 (ULES01213) */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *D_09A0B544;
extern int D_08A62D8C;

extern char *func_088DCEBC(s32, u8);
extern s32 func_0883B498(char *, u16);
extern void memcpy(void *, void *, s32);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_0883D40C(char *arg0) {
    char *p;

    p = *(char **)(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)) + 0x2F4);
    if (p == 0 || func_0883B498(arg0, *(u16 *)(p + 0x1E6)) == -1) {
        return 0;
    }
    *(u8 *)(arg0 + 0x57F) = func_0883B498(arg0, *(u16 *)(p + 0x1E6));
    memcpy(arg0 + 0x1172, D_09A0B544 + *(u8 *)(arg0 + 0x57F) * 0xC8 + 0x57C, 8);
    *(u8 *)(arg0 + 0x582) = 0;
    func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
    return 1;
}
