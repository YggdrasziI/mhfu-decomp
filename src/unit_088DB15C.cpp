/* unit_088DB15C: 0x088DB15C-0x088DB1C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;
typedef struct V44_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); } V44_0;

extern "C" {

extern char **func_088DCEBC(s32, s32);

void func_088DB15C(s32 arg0) {
    s32 var_s0;
    char **temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_088DCEBC(arg0, var_s0);
        if (temp_v0 != 0) {
            ((V44_0 *) (temp_v0))->vfunc_44();
        }
        var_s0 += 1;
    } while (var_s0 < 6);
}

}
