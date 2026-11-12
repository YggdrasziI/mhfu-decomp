/* unit_08866708: 0x08866708-0x0886678C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;

extern "C" {

extern s32 D_089CBFFC;
extern s32 func_0884C9B8(s32, s32, s32, s32);

void func_08866708(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a1;
    char *var_s0;

    var_s0 = ((char **)((char *)arg0 + 0x80028))[arg1];
    if (var_s0 != 0) {
        do {
            temp_a1 = *(s32 *)(var_s0 + 4);
            if (((bool) (temp_a1 & 1) == 1) && ((bool) (temp_a1 & 4) == 0)) {
                func_0884C9B8(D_089CBFFC, 5, (s32) var_s0, 0);
            }
            var_s0 = *(char **)(var_s0 + 0x1C4);
        } while (var_s0 != 0);
    }
}

}
