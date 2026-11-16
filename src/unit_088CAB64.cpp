/* unit_088CAB64: 0x088CAB64-0x088CAB98 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef struct V28_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual char *vfunc_28(); } V28_0;

extern "C" {

s8 func_088CAB64(char **arg0) {
    u8 var_v0;
    char *temp_v0;

    temp_v0 = ((V28_0 *) (arg0))->vfunc_28();
    if (temp_v0 != 0) {
        var_v0 = *(u8 *)(temp_v0 + 0x3D);
    } else {
        var_v0 = 0;
    }
    return (s8) var_v0;
}

}
