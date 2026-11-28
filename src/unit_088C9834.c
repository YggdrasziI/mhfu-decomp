/* unit_088C9834: 0x088C9834-0x088C9988 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Builds a scale matrix from base + amp * sin(phase) and a translation,
 * then draws through func_0886171C between two func_08862354 calls.
 * The 2*pi-like constant is 0x40C90F12 as stored in the original.
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Anim {
    u16 period;
    u16 pad[7];
    f32 trans[4];
    f32 base[4];
    f32 amp[4];
} Anim;

extern void func_08862354(float *, char *);
extern void func_0886171C(char *, s32, char *, s32);

static inline void mtx_identity(f32 *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

void func_088C9834(char *arg0, char *arg1, Anim *arg2, s32 arg3) {
    f32 x;
    f32 r;
    f32 s;
    f32 v[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 *px;
    f32 *pr;
    f32 *ps;
    f32 *a;
    f32 *b;
    f32 *out;

    x = 6.28308964f * ((f32)(*(u16 *)(arg0 + 0x1C0) % arg2->period) / (f32)(u32)arg2->period);
    pr = &r;
    px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    s = r;
    out = v;
    a = arg2->amp;
    ps = &s;
    asm {
        lv.q C000, 0(a)
        lv.s S010, 0(ps)
        vscl.t C000, C000, S010
        sv.q C000, 0(out)
    }
    b = arg2->base;
    asm {
        lv.q C000, 0(out)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(out)
    }
    {
        f32 dx, dy, dz;
        f32 tx, ty, tz;
        dz = v[2];
        dy = v[1];
        dx = v[0];
        mtx_identity(m);
        m[0] = dx;
        m[5] = dy;
        m[10] = dz;
        tz = arg2->trans[2];
        ty = arg2->trans[1];
        tx = arg2->trans[0];
        m[12] = tx;
        m[13] = ty;
        m[14] = tz;
    }
    func_08862354(m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    func_08862354((f32 *)(arg0 + 0x10), arg1 + 0x10);
}
