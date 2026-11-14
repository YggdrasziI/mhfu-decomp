/* unit_088C32E8: 0x088C32E8-0x088C3324 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;
typedef struct V14_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); } V14_0;

extern "C" {

void func_088C32E8(char **arg0) {
    char *temp_a0;

    temp_a0 = *arg0;
    if ((temp_a0 != 0) && (*(s32 *)(temp_a0 + 0x50) != 0)) {
        ((V14_0 *) (temp_a0))->vfunc_14();
    }
}

}
