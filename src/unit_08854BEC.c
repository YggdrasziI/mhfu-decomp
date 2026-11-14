/* unit_08854BEC: 0x08854BEC-0x08854CCC (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_089B1E90;
extern char D_089B1EBC;
extern s32 func_0884FE80(s32, s32);

s32 func_08854BEC(s32 arg0, s32 arg1) {
    char *var_s0;
    u16 var_a1;

    var_s0 = (char *) (((s32 *)&D_089B1EBC)[arg1]);
    var_a1 = *(u16 *)var_s0;
    if (var_a1 != 0) {
loop_1:
        if (!(func_0884FE80(arg0, (s32) var_a1) & 0xFF)) {
            return 0;
        }
        var_s0 += 2;
        var_a1 = *(u16 *)var_s0;
        if (var_a1 == 0) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    return 1;
}

s32 func_08854C5C(s32 arg0, s32 arg1) {
    char *var_s0;
    u16 var_a1;

    var_s0 = (char *) (((s32 *)&D_089B1E90)[arg1]);
    var_a1 = *(u16 *)var_s0;
    if (var_a1 != 0) {
loop_1:
        if (!(func_0884FE80(arg0, (s32) var_a1) & 0xFF)) {
            return 0;
        }
        var_s0 += 2;
        var_a1 = *(u16 *)var_s0;
        if (var_a1 == 0) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    return 1;
}
