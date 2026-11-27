/* unit_08814674: 0x08814674-0x088147C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;

extern float *D_08A62C40;

static inline void vec4_scale(float *dst, float *src, float f) {
    float *pf = &f;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(pf)
        vscl.q C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void mtx_apply(float *dst, float *m, float *v) {
    asm {
        lv.q C100, 0(v)
        lv.q C200, 0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        lv.q C230, 0x30(m)
        vtfm4.q C000, E200, C100
        sv.q C000, 0(dst)
    }
}

void func_08814674(char *arg0, float *arg1, float *arg2) {
    float tmp[4] __attribute__((aligned(16)));
    u8 flag;
    vec4_scale(arg1, arg2, *D_08A62C40);
    arg1[3] = 1.0f;
    mtx_apply(tmp, (float *)(arg0 + 0xBC0), arg1);
    mtx_apply(arg1, (float *)(arg0 + 0xC00), tmp);
    flag = 0;
    if (-1e-5f < arg1[3] && arg1[3] < 1e-5f) flag = 1;
    if (flag == 1) arg1[3] = 1.0f;
    arg1[0] = *(float *)(arg0 + 0xDAC) + *(float *)(arg0 + 0xDA0) * arg1[0] / arg1[3];
    arg1[1] = *(float *)(arg0 + 0xDB0) + *(float *)(arg0 + 0xDA4) * arg1[1] / arg1[3];
    arg1[2] = *(float *)(arg0 + 0xDB4) + *(float *)(arg0 + 0xDA8) * arg1[2] / arg1[3];
    arg1[0] -= *(float *)(arg0 + 0xB70);
    arg1[1] -= *(float *)(arg0 + 0xB74);
}
