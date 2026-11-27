/* unit_08813388: 0x08813388-0x08813498 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern float D_08933A90;

static inline void dist3(float *b, float *a, float *pr) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
}

static inline float dist_vfpu(float *a, float *b) {
    float r;
    dist3(b, a, &r);
    return r;
}

void func_08813388(char *arg0, s32 arg1) {
    char *base = arg0 + 0x730;
    char *p = base + 0xB0;
    s32 n;
    char *q;

    arg0[0x810] = 3;
    *(s16 *)(arg0 + 0x814) = 15;
    if (arg1 != 0) {
        if ((*(s32 *)(p + 0x54) -= 1) != 0) {
            p[0] = 1;
            p[0x30] = 2;
            *(s16 *)(p + 0x36) = 15;
            *(s16 *)(p + 0x34) = 15;
        } else {
            p[0] = 0;
            p[0x30] = 0;
            *(s16 *)(p + 0x36) = 0;
        }
    } else {
        n = *(s32 *)(p + 0x54) - 1;
        if (*(u8 *)((char *)n + (s32)p + 0x31) == 5 && *(s16 *)(p + 0x36) != 0) {
            float d1, d2;
            s16 t;
            q = p + n * 16;
            d1 = dist_vfpu((float *)base, (float *)(q + 0x70));
            d2 = dist_vfpu((float *)(base + 0x10), (float *)(q + 0xA0));
            t = (s16)(s32)(D_08933A90 * (d1 + d2)) + 1;
            *(s16 *)(p + 0x36) = t;
            *(s16 *)(p + 0x34) = t;
        }
    }
}
