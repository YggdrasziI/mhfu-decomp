/* unit_0888EAF8: 0x0888EAF8-0x0888F6A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_0888EAF8: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks").
 *
 * The two lerps of the mode-0 paths take 1.0f - t at the call (common
 * subexpression with u, copied through $f0); the case-1 lerps take u. The
 * random terms of the side/up oscillators (osc[0], osc[1]) are computed into a
 * dead local: only the call and the u8 -> float branches stay, as in the
 * original. The initialised vector and the jump table are the object's own
 * data (D_089AD220 / D_089AD228, 0x10 bytes; jtbl_08931A6C, 0x18 bytes).
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    f32 m[16];
} __attribute__((aligned(16))) Mtx;

/* Oscillator of the camera: phase, phase step, two amplitudes. */
typedef struct {
    s16 phase;
    s16 step;
    s16 a;
    s16 b;
} Osc;

typedef struct {
    Vec unk0;
    Vec unk10;
    Vec unk20;
    Vec unk30;
    u8 pad40[8];
    u8 unk48;
    u8 unk49;
    u8 unk4A;
    u8 unk4B;
    u8 unk4C;
    u8 unk4D;
    u8 pad4E[6];
    f32 unk54;
    f32 unk58;
    u8 pad5C[8];
    s16 unk64;
    s16 unk66;
    s16 unk68;
    s16 unk6A;
    Osc osc[4];
    u8 rnd[4];
    u8 pad90[4];
    f32 unk94;
    u8 unk98;
    u8 pad99[2];
    u8 unk9B;
} Cam;

typedef struct {
    Vec unk0;
    Vec unk10;
    u8 pad20[0x60];
    f32 unk80;
    f32 unk84;
    f32 unk88;
    u8 pad8C[8];
    s16 unk94;
    s16 unk96;
    u8 pad98[8];
    Cam unkA0;
} Obj;

typedef struct {
    u8 pad0[0xD0];
    Mtx m;
    u8 pad110[0x140];
} Part;

typedef struct {
    u8 pad0[0x10];
    Mtx unk10;
    u8 pad50[0x140];
    Part *unk190;
} Pl;

extern char *D_089CBBE4;
extern char *D_09D1A060;
extern char *D_08A631A0;

extern float func_08897D4C(float, float);
extern void func_0888E28C(Obj *, s16 *);
extern Mtx *func_0888E218(Obj *);
extern void func_08897BD8(Vec *, Vec *, Vec *);
extern s32 func_09C3AAA8(char *, Vec *, Vec *, f32, Vec *, u16);
extern float func_09C3DA00(char *, Vec *);
extern s32 func_088900C4(char *, s32);
extern void func_08897DE0(Vec *, Vec *, f32);
extern void func_08897D7C(Mtx *, Vec *);

static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_sub3(Vec *b, Vec *a, Vec *dst) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_add3(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_cross(Vec *a, Vec *dst, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vzero.s S023
        vcrsp.t C020, C000, C010
        sv.q C020, 0(dst)
    }
}

static inline void vec_normalize(Vec *v) {
    asm {
        lv.q C000, 0(v)
        vdot.q S010, C000, C000
        vzero.s S011
        vcmp.s ez, S010, S010
        nop
        vrsq.s S010, S010
        vcmovt.s S010, S011, 0
        vpfxd [-1:1],[-1:1],[-1:1],[-1:1]
        vscl.q C000, C000, S010
        sv.q C000, 0(v)
    }
}

static inline void vec_scale(Vec *v, float s) {
    float *ps = &s;
    asm {
        lv.q C000, 0(v)
        lv.s S010, 0(ps)
        vscl.q C000, C000, S010
        sv.q C000, 0(v)
    }
}

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_rot_xyz(Mtx *m, float x, float y, float z) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    asm {
        lv.q C000, 0(m)
        lv.q C010, 0x10(m)
        lv.q C020, 0x20(m)
        lv.q C030, 0x30(m)
        lv.s S100, 0(px)
        lv.s S101, 0(py)
        lv.s S102, 0(pz)
        vcst.s S103, VFPU_2_PI
        vscl.t C130, C100, S103
        vsin.t C110, C130
        vcos.t C120, C130
        vmul.s S000, S122, S121
        vmul.s S130, S112, S120
        vmul.s S010, S111, S122
        vmul.s S010, S010, S110
        nop
        vsub.s S010, S010, S130
        vmul.s S020, S110, S112
        vmul.s S131, S111, S122
        vmul.s S131, S131, S120
        vadd.s S020, S020, S131
        vmul.s S001, S112, S121
        vmul.s S011, S122, S120
        vmul.s S131, S111, S112
        vmul.s S131, S131, S110
        vadd.s S011, S011, S131
        vmul.s S130, S110, S122
        vmul.s S021, S111, S112
        vmul.s S021, S021, S120
        nop
        vsub.s S021, S021, S130
        vneg.s S002, S111
        vmul.s S012, S110, S121
        vmul.s S022, S121, S120
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

static inline void vec_tfm3(Mtx *mtx, Vec *src, Vec *dst) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
        sv.q C000, 0(dst)
    }
}

static inline void vec_lerp(Vec *b, Vec *a, Vec *dst, float t, float u) {
    float *pt = &t;
    float *pu = &u;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        lv.s S020, 0(pt)
        lv.s S021, 0(pu)
        vscl.t C100, C000, S020
        vscl.t C110, C010, S021
        vadd.t C000, C100, C110
        sv.q C000, 0(dst)
    }
}

static inline float cos_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_0888EAF8(Obj *arg0, char *arg1) {
    s16 ang[2];
    Pl *pl;
    Cam *c;
    f32 t;
    f32 u;
    f32 a;
    f32 h;
    u8 flag;
    f32 amp;
    f32 cs;

    pl = *(Pl **)(D_089CBBE4 + 0xA84);
    c = &arg0->unkA0;
    if (arg0->unk96 > 0) {
        t = (f32)arg0->unk94 / (f32)arg0->unk96;
        switch (c->unk98) {
        case 1:
            t = func_08897D4C(t, c->unk94);
            break;
        case 2:
            t = 1.0f - func_08897D4C(1.0f - t, c->unk94);
            break;
        case 3:
            if (t < 0.5f) {
                t = 0.5f * func_08897D4C(2.0f * t, c->unk94);
            } else {
                t = 1.0f - 0.5f * func_08897D4C(2.0f * (1.0f - t), c->unk94);
            }
            break;
        }
    } else {
        t = 1.0f;
    }
    {
        Vec v = {0.0f, 0.0f, 500.0f, 0.0f};
        Mtx m;
        Vec tmp;
        Vec w;
        Mtx m2;
        Vec side;
        Vec up;
        Vec diff;
        Vec q;
        u = 1.0f - t;
        switch (c->unk48) {
        case 0:
            func_0888E28C(arg0, ang);
            mtx_identity(&m);
            mtx_rot_xyz(&m, 9.58738019e-05f * (f32)ang[0], 9.58738019e-05f * (f32)ang[1], 0.0f);
            if (c->unk4D == 1) {
                vec_lerp(&c->unk10, &c->unk0, &arg0->unk0, t, 1.0f - t);
                vec_tfm3(&m, &v, &v);
                switch (c->unk49) {
                case 2: {
                    Part *pp = pl->unk190;
                    vec_tfm3(&pp[c->unk4C].m, &v, &v);
                    break;
                }
                case 0:
                    vec_tfm3(&pl->unk10, &v, &v);
                    break;
                case 3: {
                    Mtx *e = func_0888E218(arg0);
                    if (e != 0) {
                        vec_tfm3(e, &v, &v);
                    }
                    break;
                }
                case 1:
                case 4:
                case 5:
                    break;
                }
                func_08897BD8(&arg0->unk10, &arg0->unk0, &v);
            } else {
                vec_lerp(&c->unk30, &c->unk20, &arg0->unk10, t, 1.0f - t);
                v.z = c->unk54 * t + c->unk58 * u;
                vec_tfm3(&m, &v, &v);
                switch (c->unk4A) {
                case 2: {
                    Part *pp = pl->unk190;
                    vec_tfm3(&pp[c->unk4B].m, &v, &v);
                    break;
                }
                case 0:
                    vec_tfm3(&pl->unk10, &v, &v);
                    break;
                case 3: {
                    Mtx *e = func_0888E218(arg0);
                    if (e != 0) {
                        vec_tfm3(e, &v, &v);
                    }
                    break;
                }
                case 1:
                    break;
                case 4:
                    break;
                }
                func_08897BD8(&arg0->unk0, &arg0->unk10, &v);
            }
            break;
        case 1:
            vec_lerp(&c->unk30, &c->unk20, &arg0->unk10, t, u);
            vec_lerp(&c->unk10, &c->unk0, &arg0->unk0, t, u);
            break;
        }

        if (c->unk9B != 0) {
            if (func_09C3AAA8(D_09D1A060, &arg0->unk10, &arg0->unk0, 28.0f, &tmp, 0x8009) != 0) {
                vec_copy(&tmp, &arg0->unk0);
            }
            tmp.y = func_09C3DA00(D_09D1A060, &arg0->unk0);
            h = 30.0f + tmp.y;
            if (h > arg0->unk0.y) {
                arg0->unk0.y = h;
            }
        }

        arg0->unk80 = 9.58738019e-05f * (f32)c->unk64 * t + 9.58738019e-05f * (f32)c->unk66 * u;
        arg0->unk88 = 9.58738019e-05f * (f32)c->unk68 * t + 9.58738019e-05f * (f32)c->unk6A * u;

        if (c->osc[2].step != 0) {
            amp = (f32)c->osc[2].a * t + (f32)c->osc[2].b * u;
            cs = cos_vfpu(3.14159274f * (f32)c->osc[2].phase / 32768.0f);
            c->osc[2].phase += c->osc[2].step;
            a = amp * cs;
            if (c->rnd[2] != 0) {
                a = a + 3.06372567e-05f * (a * (f32)c->rnd[2] * (f32)(s32)((u8)func_088900C4(D_08A631A0, 1) - 0x80));
            }
            arg0->unk80 += 9.58738019e-05f * a;
        }
        if (c->osc[3].step != 0) {
            amp = (f32)c->osc[3].a * t + (f32)c->osc[3].b * u;
            cs = cos_vfpu(3.14159274f * (f32)c->osc[3].phase / 32768.0f);
            c->osc[3].phase += c->osc[3].step;
            a = amp * cs;
            if (c->rnd[3] != 0) {
                a = a + 3.06372567e-05f * (a * (f32)c->rnd[3] * (f32)(s32)((u8)func_088900C4(D_08A631A0, 1) - 0x80));
            }
            arg0->unk88 += 9.58738019e-05f * a;
        }

        w.x = w.y = 0.0f;
        flag = 0;
        if (c->osc[0].step != 0) {
            amp = (f32)c->osc[0].a * t + (f32)c->osc[0].b * u;
            cs = cos_vfpu(3.14159274f * (f32)c->osc[0].phase / 32768.0f);
            c->osc[0].phase += c->osc[0].step;
            w.x = amp * cs;
            flag |= 1;
            if (c->rnd[0] != 0) {
                a = w.x + 3.06372567e-05f * (w.x * (f32)c->rnd[0] * (f32)(s32)((u8)func_088900C4(D_08A631A0, 1) - 0x80));
            }
        }
        if (c->osc[1].step != 0) {
            amp = (f32)c->osc[1].a * t + (f32)c->osc[1].b * u;
            cs = cos_vfpu(3.14159274f * (f32)c->osc[1].phase / 32768.0f);
            c->osc[1].phase += c->osc[1].step;
            w.y = amp * cs;
            flag |= 1;
            if (c->rnd[1] != 0) {
                a = w.y + 3.06372567e-05f * (w.y * (f32)c->rnd[1] * (f32)(s32)((u8)func_088900C4(D_08A631A0, 1) - 0x80));
            }
        }

        if (flag & 1) {
            vec_sub3(&arg0->unk0, &arg0->unk10, &diff);
            up.y = 1.0f;
            up.z = 0.0f;
            up.x = 0.0f;
            vec_cross(&up, &side, &diff);
            vec_normalize(&side);
            vec_cross(&diff, &up, &side);
            vec_normalize(&up);
            vec_scale(&side, w.x);
            vec_scale(&up, w.y);
            vec_add3(&w, &side, &up);
            func_08897DE0(&q, &diff, arg0->unk80);
            func_08897D7C(&m2, &q);
            vec_tfm3(&m2, &w, &v);
            vec_add3(&arg0->unk0, &arg0->unk0, &v);
            vec_add3(&arg0->unk10, &arg0->unk10, &v);
        }
    }
}
