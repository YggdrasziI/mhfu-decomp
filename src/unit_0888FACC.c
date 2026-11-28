/* unit_0888FACC: 0x0888FACC-0x0888FBD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888FACC */
typedef int s32;
typedef short s16;

typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;

extern void func_08865F24(s32 arg0, Vec *arg1, s16 arg2);

static inline void vec_sub3(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline float vec_dot(Vec *a, Vec *b) {
    float r;
    Vec *pa;
    float *pr;
    pr = &r;
    pa = a;
    asm {
        lv.q C000, 0(pa)
        lv.q C010, 0(b)
        vdot.t S100, C000, C010
        sv.s S100, 0(pr)
    }
    return r;
}

s32 func_0888FACC(Vec *arg0, Vec *arg1) {
    Vec d;
    s32 obj = *(s32 *)(D_089CBBE4 + 0xA84);

    func_08865F24(obj, arg1, 0x14);
    if (arg1->y >= arg0->y) {
        return 0;
    }
    vec_sub3(&d, arg1, arg0);
    if (vec_dot(arg0 + 3, &d) > 0.0f) {
        return 1;
    }
    func_08865F24(obj, arg1, 2);
    vec_sub3(&d, arg1, arg0);
    if (vec_dot(arg0 + 3, &d) > 0.0f) {
        return 1;
    }
    return 0;
}
