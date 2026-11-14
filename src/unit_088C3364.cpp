/* unit_088C3364: 0x088C3364-0x088C33E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef struct V10_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); } V10_0;

extern "C" {

void func_088C3364(char *arg0) {
    char *temp_a1;
    char *var_s0;

    var_s0 = *(char **)(arg0 + 0xA2E0);
    if (var_s0 != 0) {
        do {
            ((V10_0 *) (var_s0))->vfunc_10();
            var_s0 = *(char **)(var_s0 + 0x14);
        } while (var_s0 != 0);
    }
    temp_a1 = *(char **)arg0;
    if ((temp_a1 != 0) && (*(u8 *)(arg0 + 0xA3E9) == 1)) {
        *(s8 *)(temp_a1 + 0x3D4) = 1;
    }
}

}
