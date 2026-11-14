/* unit_088666B4: 0x088666B4-0x08866708 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;
typedef struct V14_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); } V14_0;

extern "C" {

void func_088666B4(s32 arg0, s32 arg1) {
    char *var_s0;

    var_s0 = ((char **)((char *)arg0 + 0x80028))[arg1];
    if (var_s0 != 0) {
        do {
            ((V14_0 *) (var_s0))->vfunc_14();
            var_s0 = *(char **)(var_s0 + 0x1C4);
        } while (var_s0 != 0);
    }
}

}
