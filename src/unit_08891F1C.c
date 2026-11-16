/* unit_08891F1C: 0x08891F1C-0x08891F88 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_089CBBE8;
extern int func_08816460(s32, s8 **);

s32 func_08891F1C(s32 arg0, s8 *arg1) {
    s8 *sp1C;
    s32 var_s0;
    s8 var_v1;

    sp1C = arg1;
    var_v1 = *arg1;
    var_s0 = 0;
    if (var_v1 != 0) {
        do {
            if (var_v1 == 0xA) {
                sp1C += 1;
            } else {
                func_08816460(D_089CBBE8, &sp1C);
                var_s0 += 1;
            }
            var_v1 = *sp1C;
        } while (var_v1 != 0);
    }
    return var_s0;
}
