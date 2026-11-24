/* unit_088552E0: 0x088552E0-0x088553DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 func_0884FE80(char *, u16);
extern u16 *D_089B1E64[];

s32 func_088552E0(char *arg0) {
    u8 i;
    u16 *p;
    s32 count;

    count = 0;
    for (i = 0; i < 11; i++) {
        p = D_089B1E64[i];
        if (*p != 0) {
            do {
                if (*p != 0xFA1 && *p != 0xFA2 && *p != 0xFA3 && *p != 0xFA4 &&
                    *p != 0xFA5 && *p != 0xFA6 && *p != 0xFA7) {
                    if ((u8)func_0884FE80(arg0, *p) == 1) {
                        count++;
                    }
                }
                p++;
            } while (*p != 0);
        }
    }
    return count;
}
