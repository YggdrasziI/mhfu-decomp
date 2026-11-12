/* unit_0882FD68: 0x0882FD68-0x0882FDA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_08930BDC;

char *func_0882FD68(s32 arg0, s32 arg1) {
    char *var_v0;
    s32 var_a1;

    var_v0 = &D_08930BDC;
    var_a1 = 0;
loop_1:
    if (*(u8 *)(var_v0 + 3) == (arg1 & 0xFF)) {
        return var_v0;
    }
    var_a1 += 1;
    var_v0 += 0xE;
    if (var_a1 >= 0x3E) {
        return 0;
    }
    goto loop_1;
}
