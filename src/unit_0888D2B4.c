/* unit_0888D2B4: 0x0888D2B4-0x0888D36C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} Vec __attribute__((aligned(16)));

extern char *D_09D1A060;
extern s32 func_09C3E2D0(char *, Vec *, Vec *, Vec *, u16);

static inline void vec_copy(Vec *d, Vec *s) {
    asm {
        lv.q C000, 0x0(s)
        sv.q C000, 0x0(d)
    }
}

u8 func_0888D2B4(char *arg0) {
    f32 d;
    Vec hit;
    Vec a;
    Vec b;
    char *p = arg0 + 0xA0;
    if ((u8)func_09C3E2D0(D_09D1A060, (Vec *)(p + 0x50), (Vec *)(p + 0x40), &hit, 0x8009) != 0) {
        vec_copy(&a, &hit);
        vec_copy(&b, (Vec *)(p + 0x40));
        a.y = 0.0f;
        b.y = 0.0f;
        {
            Vec *pa = &a;
            Vec *pb = &b;
            f32 *pd = &d;
            asm {
                lv.q C000, 0x0(pa)
                lv.q C010, 0x0(pb)
                vsub.t C000, C000, C010
                nop
                vdot.t S010, C000, C000
                vsqrt.s S010, S010
                sv.s S010, 0x0(pd)
            }
        }
        if (d > 50.0f) {
            return 1;
        }
    }
    return 0;
}
