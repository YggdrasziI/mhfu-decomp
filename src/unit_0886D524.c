/* unit_0886D524: 0x0886D524-0x0886D5E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern u16 func_0886B8DC(char *);
extern u8 D_089A8164[];
extern u8 *D_089A8148[];
extern u8 D_08A62C80[];
extern u8 D_08A62C81[];

u16 func_0886D524(char *arg0) {
    u8 *t;
    u16 v;
    s32 k;

    t = D_089A8148[D_089A8164[func_0886B8DC(arg0) & 0x1F]];
    v = t[func_0886B8DC(arg0) & 0x1F];
    k = *(s8 *)(*(char **)(arg0 + 0x4C) + 0x4A);
    if (v < D_08A62C80[k * 2]) {
        v = D_08A62C80[k * 2];
    }
    if (v > D_08A62C81[k * 2]) {
        v = D_08A62C81[k * 2];
    }
    return v;
}
