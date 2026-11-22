/* unit_088A47C4: 0x088A47C4-0x088A489C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

extern char D_089B25D0;
extern char D_089B25DC;
extern char D_089B25E4;
extern char D_089B25EC;
extern s32 D_09A0EA80;
extern s32 D_09A0EA84[2][16];
extern s32 D_09A0EB04;

extern s32 func_0880EFF8(s32, s32, s32);
extern int func_0880D9EC(char *, ...);
extern s32 func_088A489C(s32);

s32 func_088A47C4(s32 arg0) {
    u32 i;

    if (func_0880EFF8(arg0, (s32)&D_089B25D0, 8) != 0) {
        func_0880D9EC(&D_089B25DC);
        func_0880D9EC(&D_089B25E4);
        func_0880D9EC(&D_089B25EC);
        return 0x80000002;
    }
    for (i = 0; i < 16; i++) {
        D_09A0EA84[0][i] = 0;
        D_09A0EA84[1][i] = 0;
    }
    D_09A0EB04 = arg0;
    D_09A0EA80 = 0;
    return func_088A489C(0);
}
