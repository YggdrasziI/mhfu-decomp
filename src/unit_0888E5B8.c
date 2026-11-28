/* unit_0888E5B8: 0x0888E5B8-0x0888E634 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern char *D_09D1A060;
extern float func_09C3DA00(char *, char *);

static inline void copy_vec4(char *src, char *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

float func_0888E5B8(char *arg0, char *arg1, char *arg2) {
    float buf[4] __attribute__((aligned(16)));

    float r = func_09C3DA00(D_09D1A060, arg1);
    if (*(float *)(arg2 + 0x204) <= r) {
        return r;
    }
    copy_vec4(arg1, (char *)buf);
    buf[1] = buf[1] + 150.0f;
    return func_09C3DA00(D_09D1A060, (char *)buf);
}
