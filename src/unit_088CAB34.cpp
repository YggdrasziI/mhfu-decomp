/* unit_088CAB34: 0x088CAB34-0x088CAB64 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;
typedef struct V28_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual char *vfunc_28(); } V28_0;

extern "C" {

s32 func_088CAB34(char **arg0) {
    char *temp_v0;

    temp_v0 = ((V28_0 *) (arg0))->vfunc_28();
    if (temp_v0 != 0) {
        return *(s32 *)(temp_v0 + 0x30);
    }
    return 0;
}

}
