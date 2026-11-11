/* unit_0886E008: 0x0886E008-0x0886E060 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef struct { char b[8]; } E8;

s16 func_0886E008(char *arg0, s32 arg1) {
    s32 var_a3;
    char *var_a2;

    var_a3 = 0;
    var_a2 = arg0;
loop_1:
    if (((*(s32 *)(var_a2 + 0x728) & 0x11) == 0x11) && (*(u16 *)(var_a2 + 0x72C) == (arg1 & 0xFFFF))) {
        return *(s16 *)((E8 *)(arg0 + 0x72E))[var_a3].b;
    }
    var_a3 += 1;
    var_a2 += 8;
    if (var_a3 >= 2) {
        return -1;
    }
    goto loop_1;
}
