/* unit_088C1430: 0x088C1430-0x088C14C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;
typedef struct V34_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(s32, s32, s32, s32, s32, s32); } V34_0;

extern "C" {

extern char **D_089CC434;
extern int func_0880C464(void *, s32, s32);
extern void func_088BF858(void *, s32);

void func_088C1430(char *arg0) {
    ((V34_0 *) (D_089CC434))->vfunc_34(0xC, *(s32 *)(arg0 + 0x10), -1, 0, 0, 1);
    ((V34_0 *) (D_089CC434))->vfunc_34(0xD, *(s32 *)(arg0 + 0x14), -1, 0, 0, 1);
    func_0880C464(*(char **)(arg0 + 0x94C), 0, 0x16A100);
    func_088BF858(arg0, 0);
}

}
