/* unit_0885FFBC: 0x0885FFBC-0x0886005C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef float f32;

extern void func_088633CC(char *arg0, char *arg1, void *arg2, void *arg3, char *arg4, f32 f);

void func_0885FFBC(char *arg0, float *arg1, s32 arg2, f32 f0, f32 f1) {
    char c[0x28];
    float b[16] __attribute__((aligned(16)));
    float a[16] __attribute__((aligned(16)));
    char *s;
    float *p;
    float *q;

    if (arg2 == 0) {
        s = arg0 + 0x150;
    } else {
        s = arg0 + 0x1D0;
    }
    func_088633CC(s, arg0 + 0x120, c, b, s + 0x6C, f0);
    func_088633CC(s, arg0 + 0x120, c, a, s + 0x6C, f1);
    p = &a[12];
    q = &b[12];
    asm {
        lv.q C000, 0(p)
        lv.q C010, 0(q)
        vsub.q C000, C000, C010
        sv.q C000, 0(arg1)
    }
    arg1[3] = 0.0f;
}
