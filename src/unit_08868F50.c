/* unit_08868F50: 0x08868F50-0x08869424 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08868F50: reads the pad, derives stick angle and magnitude. */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u32 time;
    u32 buttons;
    u8 lx;
    u8 ly;
    u8 rsrv[6];
} Pad;

typedef struct {
    u16 buttons;  /* 0x00 */
    s16 lx;       /* 0x02 */
    s16 ly;       /* 0x04 */
    s16 mag;      /* 0x06 */
    s16 angle;    /* 0x08 */
    f32 angf;     /* 0x0C */
    u32 prev;     /* 0x10 */
    u8 cnt;       /* 0x14 */
    u8 f15;       /* 0x15 */
    u8 f16;       /* 0x16 */
    u8 f17;       /* 0x17 */
} Stick;

extern int sceCtrlReadBufferPositive(Pad *, s32);
extern void memset(void *, s32, s32);
extern u16 D_089A607C[];
extern s32 D_08A62C68;
extern s32 D_08A62C6C;
extern s32 D_08A62C70;
extern s32 D_08A62C74;
extern u16 D_08A62C78;
extern u16 D_08A62C7A;

/* The compiler's assembler has no syntax for these prefixes and constant. */
#define VPFXS_ABS .word 0xDC000FE4
#define VPFXS_TWO .word 0xDC00F0AA
#define VPFXS_NEG_Y .word 0xDC0200E4
#define VPFXT_ABS .word 0xDD000FE4
#define VPFXT_HALF .word 0xDD00F0FF
#define VPFXD_SAT_Y .word 0xDE000004
#define VFIM_S010_M1 .word 0xDF81BC00

static inline float atan2_vfpu(float y, float x) {
    float r;
    float *pr = &r;
    float *py = &y;
    float *px = &x;
    asm {
        .set noreorder
        lv.s S000, 0(py)
        lv.s S001, 0(px)
        vcmp.p es, C000, C000
        bvt 4, special
        vzero.s S002
        vcmp.s ge, S001, S002
        vcst.s S010, VFPU_PI
        vcmovt.s S010, S002, 0
        vcmp.s ez, S000, S000
        bvt 0, done
        vcst.s S002, VFPU_PI_2
        vrcp.s S003, S001
        vmul.s S003, S000, S003
        vcmp.s en, S003, S003
        bvt 0, done
        vmov.s S010, S003
        vcmp.s es, S003, S003
        bvtl 0, quadrant
        vsgn.s S010, S000
        vmul.s S011, S003, S003
        vcmp.s es, S011, S011
        bvt 0, overflow
        vone.s S003
        VPFXS_ABS
        vcmp.s lt, S010, S003
        vadd.s S003, S011, S003
        bvfl 0, steep
        vrcp.s S003, S003
        vrsq.s S003, S003
        vmul.s S010, S010, S003
        b quadrant
        vasin.s S010, S010
    special:
        vcmp.p en, C000, C000
        VFIM_S010_M1
        bvt 4, done
        vrsq.s S010, S010
        vcmp.p ei, C000, C000
        bvt 5, both_inf
        nop
        vi2f.s S000, S000, 0
        VPFXT_HALF
        vadd.s S000, S000, S000
        vsgn.s S000, S000
        vcst.s S002, VFPU_PI_2
        bvt 0, finish
        vone.s S010
        vzero.s S003
        vcmp.s ge, S001, S003
        vcmovt.s S010, S003, 0
        b finish
        vcst.s S002, VFPU_PI
    both_inf:
        vsgn.p C000, C000
        VPFXS_TWO
        vsub.s S010, S010, S001
        b finish
        vcst.s S002, VFPU_PI_4
    overflow:
        vsgn.s S000, S000
        vcst.s S002, VFPU_PI_2
        bvt 0, finish
        vone.s S010
        vsgn.s S011, S001
        b finish
        vsub.s S010, S010, S011
    steep:
        vmul.s S003, S011, S003
        vpfxd [0:1],[0:1],[0:1],[0:1]
        vocp.s S003, S003
        vsqrt.s S003, S003
        vasin.s S003, S003
        vocp.s S010, S003
    quadrant:
        VPFXD_SAT_Y
        VPFXS_NEG_Y
        vsgn.p C000, C000
        vcmp.s ez, S001, S001
        bvt 0, finish
        nop
        VPFXS_TWO
        VPFXT_ABS
        vsub.s S010, S010, S010
    finish:
        VPFXS_ABS
        vmul.s S010, S010, S000
        vmul.s S010, S010, S002
    done:
        sv.s S010, 0(pr)
    }
    return r;
}

void func_08868F50(Stick *s) {
    Pad pad;
    s32 n;
    s32 lx, ly;
    s32 a, b, t, m;
    f32 f;
    u16 v;
    u32 cur;
    u32 prev;

    n = sceCtrlReadBufferPositive(&pad, 1);
    if (n > 0) {
        if (pad.buttons & 0x10000) {
            s->f16 = 1;
        } else {
            s->f16 = 0;
        }
        if (pad.buttons & 0x20000) {
            s->f15 = 1;
        } else {
            s->f15 = 0;
        }
    }
    if (s->f17 == 1 || s->f15 == 1 || n <= 0) {
        memset(s, 0, 0x10);
    } else {
        s->buttons = pad.buttons;
        s->lx = pad.lx - 0x80;
        if (s->lx < -0x7F) {
            s->lx = -0x7F;
        }
        s->ly = pad.ly - 0x80;
        if (s->ly < -0x7F) {
            s->ly = -0x7F;
        }
    }
    lx = s->lx;
    ly = s->ly;
    if ((lx | ly) == 0) {
        f = 0.0f;
    } else {
        f = atan2_vfpu((f32)-ly, (f32)lx);
        if (f < 0.0f) {
            f += 6.2831855f;
        }
    }
    s->angf = f;
    s->angle = 360.0f * (s->angf / 6.2831855f);
    a = s->lx;
    if (a < 0) {
        a = -a;
    }
    b = s->ly;
    if (b < 0) {
        b = -b;
    }
    if (a < b) {
        t = a ^ b;
        b ^= t;
        a = t ^ b;
    }
    m = b + (b >> 1);
    s->mag = (m >> 6) + ((m >> 2) + (a - (a >> 5) - (a >> 7)));
    if (s->mag > 0x7F) {
        s->mag = 0x7F;
    }
    if (pad.lx < 0x40 || pad.lx >= 0xC1 || pad.ly < 0x40 || pad.ly > 0xC0) {
        v = D_089A607C[(u32)(s->angle / 22.5f)];
    } else {
        s->lx = 0;
        s->ly = 0;
        s->angf = 0.0f;
        s->angle = 0;
        s->mag = 0;
        v = 0;
    }
    s->prev = D_08A62C68;
    cur = s->buttons | (v << 16);
    D_08A62C68 = cur;
    prev = s->prev;
    D_08A62C6C = ~prev & cur;
    D_08A62C70 = ~cur & prev;
    D_08A62C74 = 0;
    if (prev == cur) {
        s->cnt++;
        if (s->cnt > 0xC) {
            s->cnt = 0xA;
            D_08A62C74 = D_08A62C68;
        }
    } else {
        D_08A62C74 = D_08A62C6C;
        s->cnt = 0;
    }
    D_08A62C78 = (s->angle << 16) / 360;
    D_08A62C7A = s->mag;
}
