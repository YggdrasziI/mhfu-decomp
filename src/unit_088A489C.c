/* unit_088A489C: 0x088A489C-0x088A49D0 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

extern char D_089B25DC;
extern char D_089B25E4;
extern char D_089B2604;
extern s32 D_09A0EA80;
extern s32 D_09A0EA84[];
extern char *D_09A0EB04;
extern int func_0880D9EC(char *, ...);

s32 func_088A489C(u32 arg0) {
    s32 *src;
    s32 off;
    s32 i;
    char *base;

    base = D_09A0EB04;
    if (*(u32 *)(base + 8) <= arg0) {
        func_0880D9EC(&D_089B25DC);
        func_0880D9EC(&D_089B25E4);
        func_0880D9EC(&D_089B2604);
        return 0x80000003;
    }
    D_09A0EA80 = arg0;
    src = (s32 *)(base + arg0 * 0x40 + 0x10);
    off = 0;
    for (i = 0; i < 16; i++) {
        D_09A0EA84[i] = off;
        D_09A0EA84[i + 16] = src[i];
        off += src[i];
    }
    return 0;
}
