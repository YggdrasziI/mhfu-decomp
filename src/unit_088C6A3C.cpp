/* unit_088C6A3C: 0x088C6A3C-0x088C6AC8 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned short u16;
typedef int s32;
typedef struct V10_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); } V10_0;
typedef struct V18_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); } V18_0;

extern "C" {

extern char D_089B4F3C;
extern s32 func_088C6B84(s32);

void func_088C6A3C(char *arg0) {
    char **temp_v0;

    temp_v0 = (char **) (((s32 *)&D_089B4F3C)[*(u16 *)(arg0 + 0x288)]);
    *(char ***)arg0 = temp_v0;
    ((V10_0 *) (temp_v0))->vfunc_10();
    func_088C6B84((s32) arg0);
}

void func_088C6A90(char ***arg0) {
    char **temp_a0;

    temp_a0 = *arg0;
    ((V18_0 *) (temp_a0))->vfunc_18();
    *arg0 = 0;
}

}
