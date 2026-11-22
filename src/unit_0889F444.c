/* unit_0889F444: 0x0889F444-0x0889F47C (ULES01213) */

typedef int s32;

extern s32 D_09A0C5EC;
extern char D_09A0C5E8[];
extern char *D_09A0C5D0;

s32 func_0889F444(void) {
    char *p;

    p = D_09A0C5E8;
    if (D_09A0C5EC == 0) {
        return 0;
    }
    D_09A0C5D0 = *(char **)(*(char **)(p + 8) + 0xC);
    return *(s32 *)(D_09A0C5D0 + 4);
}
