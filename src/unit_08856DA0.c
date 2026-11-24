/* unit_08856DA0: 0x08856DA0-0x08856E34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_08A631A0;
extern int func_08856D60(char *o, u8 v);

int func_08856DA0(char *o, u8 v) {
    u8 *p;
    s32 i;
    s32 j;

    if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
        return func_08856D60(o, v);
    }
    i = 0;
    do {
        if (*(u8 *)(o + 0x30) != 0) {
            p = (u8 *)(o + 0xA9);
            j = 0;
            do {
                if (*p == v) {
                    return 1;
                }
                j++;
                p++;
            } while (j < 5);
        }
        i++;
        o += 0x8C;
    } while (i < 6);
    return 0;
}
