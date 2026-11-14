/* unit_088CA508: 0x088CA508-0x088CA558 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned char u8;
typedef int s32;
typedef struct V28_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual char *vfunc_28(); } V28_0;

extern "C" {

u8 func_088CA508(char **arg0) {
    return *(u8 *)((char *)(((V28_0 *) (arg0))->vfunc_28()) + 0x3F);
}

s32 func_088CA530(char **arg0) {
    return *(s32 *)((char *)(((V28_0 *) (arg0))->vfunc_28()) + 0x34);
}

}
