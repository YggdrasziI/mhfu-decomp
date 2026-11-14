/* unit_08864634: 0x08864634-0x088646A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;
typedef struct P3FC { char pad[0x3FC]; void (P3FC::*pmf)(); } P3FC;
typedef struct V1C_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); } V1C_0;

extern "C" {

void func_08864634(P3FC *arg0) {
    if (arg0->pmf) {
        (arg0->*arg0->pmf)();
        if ((bool) (*(s32 *)((char *) arg0 + 4) & 1) != 0) {
            ((V1C_0 *) arg0)->vfunc_18();
            ((V1C_0 *) arg0)->vfunc_1C();
        }
    }
}

}
