/* unit_088C9B00: 0x088C9B00-0x088C9D9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C9B00 (ULES01213), piece text_088C9B00, size 0x29C.
 *
 * Scrolls the texture U offset from the value at +0x1C2 (GE command 0x4A),
 * the V offset from the counter at +0x1C0 modulo the period of arg2 (0x4B),
 * builds a matrix (translation from arg2 +0x10, rotation about Y from +0x1C2)
 * and passes it to func_08862354, then func_0886171C and the offset reset.
 *
 * Optimized for speed (float constants built with lui/ori). The U offset is
 * a union local kept on the stack across the call; the translation is read
 * into locals (last component first) before the identity. VFPU blocks as in
 * unit_08815964.
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef union Bits {
    f32 f;
    u32 u;
} Bits;

typedef struct Mtx {
    f32 m[16];
} __attribute__((aligned(16))) Mtx;

typedef struct Anim {
    u16 period;
    char pad2[0xE];
    f32 x;
    f32 y;
    f32 z;
} Anim;

extern u32 *D_089CC000;
extern f32 func_08897D28(f32 x);
extern void func_08862354(char *, char *);
extern void func_0886171C(char *, s32, char *, s32);

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void rot_y(Mtx *m, f32 ang) {
    f32 *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,0,-S,0]
        vidt.q C010
        vrot.q C020, S100, [S,0,C,0]
        vidt.q C030
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        vmmul.t E200, E100, E000
        lv.q C230, 0x30(m)
        vcst.t R203, 0
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

void func_088C9B00(char *arg0, char *arg1, Anim *arg2, s32 arg3) {
    Bits a;
    Bits b;
    Mtx m;
    f32 x;
    f32 y;
    f32 z;

    a.f = 0.033333335f * (360.0f * (f32)(u32)*(u16 *)(arg0 + 0x1C2) / 65536.0f);
    a.f = a.f - func_08897D28(a.f);
    *D_089CC000 = (a.u >> 8) | 0x4A000000;
    D_089CC000++;
    if (arg2->period != 0) {
        b.f = (f32)(*(u16 *)(arg0 + 0x1C0) % arg2->period) / (f32)(u32)arg2->period;
        *D_089CC000 = (b.u >> 8) | 0x4B000000;
        D_089CC000++;
    }
    z = arg2->z;
    y = arg2->y;
    x = arg2->x;
    mtx_identity(&m);
    m.m[12] = x;
    m.m[13] = y;
    m.m[14] = z;
    rot_y(&m, 6.2831855f * (360.0f * (f32)(u32)*(u16 *)(arg0 + 0x1C2) / 65536.0f / 360.0f));
    func_08862354((char *)&m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    *D_089CC000 = 0x4A000000;
    D_089CC000++;
    *D_089CC000 = 0x4B000000;
    D_089CC000++;
    func_08862354(arg0 + 0x10, arg1 + 0x10);
}
