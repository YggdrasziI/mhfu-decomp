/* unit_08886E50: 0x08886E50-0x088883B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08886E50: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks").
 *
 * NonMatching (99.15 %): the code is the same except for the stack slots of the
 * 4-byte objects. The original puts the angle triple {0, +0x82, 0} (one stored
 * copy) and 16 unused bytes below the inline temporaries (0x160-0x17B); here the
 * caller's Ang and the by-value parameter copy of mtx_rot_ang are both stored and
 * sit above them, which shifts the sqrt / lerp / atan2 / rotation slots by 0xC and
 * reorders the stores around the matrix set-up.
 */

#pragma optimize_for_size off

typedef signed char s8;
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

/* Entry of the 0x20-byte tables at +0x6C / +0x70 of the camera. */
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Ent;

typedef struct {
    Vec unk0;
    Vec unk10;
    Vec unk20;
    f32 unk30;
    s8 unk34;
    u8 pad35[0xB];
    Vec unk40;
    Vec unk50;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    Ent *unk6C;
    Ent *unk70;
    u8 unk74[0xC];
    s16 unk80;
    s16 unk82;
    u16 unk84;
    u16 unk86;
    u8 unk88;
    u8 unk89;
    u8 unk8A;
    u8 unk8B;
    u8 unk8C;
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
    u8 unk90;
    s8 unk91;
    u8 unk92;
    u8 unk93;
} Cam;

typedef struct {
    Vec unk0;
    Vec unk10;
    u8 pad20[0x20];
    Vec unk40;
    Vec unk50;
    u8 pad60[0x20];
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    u8 unk90;
    u8 unk91;
    u8 unk92;
    u8 pad93[5];
    u8 unk98;
    u8 pad99[3];
    u8 unk9C;
    u8 pad9D[3];
    Cam unkA0;
} Obj;

typedef struct {
    u8 pad0[0x1F4];
    s32 unk1F4;
    u8 pad1F8[8];
    Vec unk200;
    u8 pad210[0x8C];
    u8 unk29C;
    u8 pad29D[0x23];
    s32 unk2C0;
} Pl;

typedef struct {
    u8 pad0[0x14];
    u8 unk14;
    u8 pad15[0xB];
    Vec unk20;
    Vec unk30;
    u8 pad40[0x60];
    f32 unkA0;
    f32 unkA4;
    f32 unkA8;
    u8 padAC[0x1A4];
    Vec unk250;
    u8 pad260[0x821];
    u8 unkA81;
    u8 padA82[2];
    Pl *unkA84;
    u8 unkA88;
    u8 unkA89;
    u8 padA8A[2];
    u8 unkA8C;
    u8 unkA8D;
    u8 padA8E[2];
    char *unkA90;
} G;

typedef struct {
    s32 x, y, z;
} Ang;

extern G *D_089CBBE4;
extern char *D_089CC438;
extern char *D_09D1A060;
extern Ent D_08933AE0[];
extern Ent D_08933BE0[];
extern Ent D_08933BFC[];

extern void func_0888FBD4(Obj *);
extern void func_0888D004(Obj *);
extern s32 func_0888D734(Obj *);
extern s32 func_0888E494(Obj *);
extern s32 func_0888E634(Obj *, u32, f32, f32, f32);
extern void func_0888E324(Obj *, s32);
extern s32 func_08865CB8(Pl *, s32, s32);
extern s32 func_09C3AAA8(char *, Vec *, Vec *, f32, Vec *, u16);
extern float func_09C3DA00(char *, Vec *);
extern float func_0888E5B8(Obj *, Vec *, Pl *);
extern s32 func_0888FCE4(Obj *);
extern void func_09C36C30(char *, Vec *);
extern void func_09C36AA8(char *, void *, Vec *, Vec *);
extern void func_0888E350(Obj *, u8 *);
extern void func_0888D36C(Obj *);
extern float func_0888D1BC(Obj *);
extern float func_0888E3DC(Obj *);
extern void func_0888F6A0(Obj *);

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

static inline float sqrt_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
    return r;
}

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

static inline void vec_tfm3(Vec *src, Mtx *mtx, Vec *dst) {
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

static inline void vec_lerp(Vec *dst, Vec *a, Vec *b, float t, float u) {
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


static inline s32 angle_of(Vec *a, Vec *b) {
    return (s32)(10430.3779f * atan2_vfpu(a->x - b->x, a->z - b->z));
}


static inline void mtx_rot_ang(Mtx *m, Ang a) {
    Vec rad;
    rad.x = 9.58738019e-05f * (f32)(a.x & 0xFFFF);
    rad.y = 9.58738019e-05f * (f32)(a.y & 0xFFFF);
    rad.z = 9.58738019e-05f * (f32)(a.z & 0xFFFF);
    rad.w = 0.0f;
    mtx_identity(m);
    mtx_rot_xyz(m, rad.x, rad.y, rad.z);
}

void func_08886E50(Obj *arg0) {
    Ang ang;
    Vec tmp;
    Vec res;
    Mtx m;
    Vec p;
    Vec p2;
    Vec tD0;
    Vec tC0;
    Vec tB0;
    Vec tA0;
    Vec t90;
    Vec ta;
    Vec tb;
    Vec t60;
    Vec sq;
    G *g;
    Cam *c;
    Pl *pl;
    u8 *s2;
    s32 mode;
    s32 t;
    u8 hold;
    s32 hit;
    u16 mask;
    f32 rad28;
    f32 lim;
    f32 h;

    g = D_089CBBE4;
    if (g->unkA8D != 0) {
        arg0->unk91 = 0;
        arg0->unk98 = 0;
        arg0->unk9C = 0;
        return;
    }
    c = &arg0->unkA0;
    if ((s32)((*(s32 *)(D_089CC438 + 0x6AF14) & 1) != 0) == 1) {
        vec_copy(&c->unk0, &arg0->unk0);
        vec_copy(&c->unk10, &arg0->unk10);
        arg0->unk80 = c->unk68;
        arg0->unk88 = c->unk60;
        return;
    }
    pl = g->unkA84;
    s2 = (u8 *)g->unkA90;
    arg0->unk91 = 1;
    g->unkA88 = 1;
    g->unkA89 = 0xFF;
    func_0888FBD4(arg0);
    func_0888D004(arg0);
    vec_copy(&c->unk0, &c->unk20);
    c->unk64 = c->unk6C->unk0;
    if (s2[2] != 0) {
        c->unk6C = D_08933AE0;
    } else {
        c->unk6C = (Ent *)(s2 + 0x20);
    }
    if ((u8)func_0888D734(arg0) == 1) {
        c->unk70 = D_08933BFC;
        mode = 7;
    } else if (c->unk8B == 60) {
        c->unk70 = D_08933BE0;
        mode = 6;
    } else {
        mode = g->unk14;
        if (*(s8 *)(D_089CC438 + 0x6ADE1) == 0) {
            if (c->unk86 & 0x40) {
                if (mode > 0) {
                    g->unk14 = mode - 1;
                }
            }
            if (c->unk86 & 0x10) {
                if (g->unk14 < 4) {
                    g->unk14++;
                }
            }
        } else {
            if (c->unk86 & 0x10) {
                if (mode > 0) {
                    g->unk14 = mode - 1;
                }
            }
            if (c->unk86 & 0x40) {
                if (g->unk14 < 4) {
                    g->unk14++;
                }
            }
        }
        t = g->unk14;
        if ((u16)mode != t) {
            c->unk8D = 8;
            t = g->unk14;
            mode = t;
        }
        if ((u8)t == 0) {
            c->unk70 = c->unk6C + 5;
            c->unk64 = 0.959931076f;
        } else {
            c->unk70 = (Ent *)((char *)c->unk6C + ((u8)t - 1) * 0x20 + 0x20);
            c->unk64 = 0.87266463f;
        }
    }
    if (c->unk8B != 0) {
        c->unk64 = 1.22173059f;
    }

    hold = 0;
    if (g->unkA81 != 0) {
        c->unk89 = 0;
        c->unk80 = pl->unk2C0 + 0x8000;
    } else if (arg0->unk92 != 0xFF) {
        char *e;
        u8 idx = arg0->unk92;
        arg0->unk92 = 0xFF;
        e = (char *)g + idx * 0x1A0;
        c->unk82 = c->unk80 = angle_of((Vec *)(e + 0xB0), (Vec *)(e + 0xC0));
        c->unk8D = 1;
    } else if (g->unkA8C != 0 && g->unkA8C != 1) {
        c->unk82 = c->unk80 = angle_of(&g->unk20, &g->unk30);
    } else if (c->unk84 & 0xA0) {
        s16 d;
        if (*(s8 *)(D_089CC438 + 0x6ADE1) != 2) {
            d = 0x47E;
        } else {
            d = -0x47E;
        }
        if (c->unk84 & 0x80) {
            c->unk80 += d;
        }
        if (c->unk84 & 0x20) {
            c->unk80 -= d;
        }
        c->unk8D = 8;
    } else if (func_0888E494(arg0) != 0) {
        c->unk80 = pl->unk1F4 + 0x8000;
        c->unk8E = 1;
        c->unk8D = 20;
        hold = c->unk8F;
    } else if ((u8)func_0888D734(arg0) == 0 && c->unk91 >= 0 && *(s8 *)(D_089CC438 + 0x6ADE0) != 1) {
        u32 da = (u16)((pl->unk1F4 ^ 0x8000) - c->unk80);
        if (c->unk91 == 0) {
            c->unk80 = c->unk80 + func_0888E634(arg0, da, 4096.0f, 26624.0f, 0.000217013891f);
        } else {
            c->unk80 = c->unk80 + func_0888E634(arg0, da, 0.0f, 26624.0f, 0.000217013891f);
        }
        hold = 1;
    } else if (c->unk89 != 0) {
        c->unk80 += (s16)((s16)((pl->unk1F4 ^ 0x8000) - c->unk80) >> 3);
        c->unk89 = 0;
    }
    c->unk8F = hold;

    c->unk82 += (s16)((s16)(c->unk80 - c->unk82) >> 2);
    if (c->unk8E != 0) {
        u32 d = (u16)(c->unk80 - c->unk82);
        if (d < 0x1000 || d > 0xF000) {
            c->unk8E = 0;
        }
    }

    if (g->unkA8C == 1 && c->unk8F == 0) {
        func_0888E324(arg0, 20);
        if (*(s8 *)(D_089CC438 + 0x6ADE0) != 0) {
            Ent *t;
            f32 best;
            f32 d;
            s32 i;
            s32 bi;
            vec_sub3(&pl->unk200, &g->unk250, &tmp);
            t = c->unk6C + 2;
            best = 100000000.0f;
            bi = 0;
            for (i = 2; i < 5; i++, t++) {
                d = t->unk4 - tmp.y;
                d = d * d;
                if (best > d) {
                    best = d;
                    bi = i;
                }
            }
            g->unk14 = bi;
            mode = (u8)bi;
            c->unk70 = (Ent *)((char *)c->unk6C + bi * 0x20 + 0x20);
        }
    }

    tmp.x = 0.0f;
    if (pl->unk29C != 3 && pl->unk29C != 0) {
        tmp.y = 400.0f;
        tmp.z = 400.0f;
        c->unk50.y = 100.0f + pl->unk200.y;
    } else if (pl->unk29C != 0 || func_08865CB8(pl, 0, 0x11) != 0 || func_08865CB8(pl, 0, 0x1B) != 0 ||
               func_08865CB8(pl, 0, 0x1E) != 0 || func_08865CB8(pl, 0, 0x3A) != 0) {
        tmp.y = 20.0f;
        tmp.z = c->unk70->unk8;
        c->unk50.y = 30.0f + pl->unk200.y;
    } else {
        tmp.y = c->unk70->unk4;
        tmp.z = c->unk70->unk8;
        c->unk50.y = pl->unk200.y + c->unk70->unk10;
    }
    c->unk50.x = pl->unk200.x;
    c->unk50.z = pl->unk200.z;
    ang.x = 0;
    ang.y = c->unk82;
    ang.z = 0;
    mtx_rot_ang(&m, ang);
    vec_tfm3(&tmp, &m, &res);
    c->unk40.x = c->unk50.x + res.x;
    c->unk40.y = pl->unk200.y + res.y;
    c->unk40.z = c->unk50.z + res.z;
    if (arg0->unk98 == 0) {
        arg0->unk98++;
        vec_copy(&c->unk40, &c->unk0);
        vec_copy(&c->unk50, &c->unk10);
        c->unk60 = c->unk64;
    }
    c->unk10.x = c->unk50.x;
    c->unk10.z = c->unk50.z;
    c->unk10.y = c->unk10.y + 0.5f * (c->unk50.y - c->unk10.y);
    if ((s32)(*((u8 *)arg0 + 0x133) != 0) == 1) {
        p.x = pl->unk200.x;
        p.y = 60.0f + pl->unk200.y;
        p.z = pl->unk200.z;
        if ((u8)func_09C3AAA8(D_09D1A060, &p, &c->unk10, 33.0f, &tmp, 4) != 0) {
            vec_copy(&tmp, &c->unk10);
        }
    }
    c->unk60 = c->unk60 + 0.05f * (c->unk64 - c->unk60);
    lim = 100.0f;
    h = func_09C3DA00(D_09D1A060, &c->unk50);
    if (-(h - c->unk30) < 210.0f) {
        c->unk34 = 0;
        c->unk30 = h;
        if (c->unk90 != 0) {
            c->unk90 = 0;
            lim = 256.0f;
        }
    } else {
        switch (c->unk34) {
        case 0:
            c->unk34 = 1;
        case 1:
            lim = 256.0f;
            break;
        default:
            c->unk34 = 0;
            c->unk30 = h;
            break;
        }
        c->unk90 = 0;
    }
    h = func_0888E5B8(arg0, &c->unk40, pl);
    if (h - c->unk40.y < lim) {
        h = h + c->unk70->unk18;
        if (h > c->unk40.y) {
            c->unk40.y = h;
            c->unk90 = 1;
        } else {
            c->unk34 = -1;
        }
    }

    if ((u8)func_0888D734(arg0) == 1) {
        c->unk8C = 0;
        mask = 0x8009;
        c->unk0.y = c->unk0.y + 0.25f * (c->unk40.y - c->unk0.y);
        c->unk0.x = c->unk40.x;
        c->unk0.z = c->unk40.z;
        c->unk8D = 8;
        rad28 = 28.0f;
        p2.x = c->unk10.x;
        p2.y = c->unk0.y;
        p2.z = c->unk10.z;
        if (func_09C3AAA8(D_09D1A060, &p2, &c->unk0, rad28, &tD0, mask) != 0) {
            vec_copy(&tD0, &c->unk0);
            c->unk80 += 0x400;
        }
    } else if (c->unk8C == 0) {
        rad28 = 28.0f;
        mask = 0x8009;
        hit = (u8)func_09C3AAA8(D_09D1A060, &c->unk0, &c->unk40, rad28, &tB0, mask);
        c->unk89 = func_09C3AAA8(D_09D1A060, &c->unk50, &c->unk40, 28.0f, &tC0, 0x8009);
        if (hit != 0 && c->unk89 != 0) {
            if ((u8)func_0888FCE4(arg0) == 1) {
                vec_copy(&tC0, &c->unk0);
                c->unk89 = 0;
                c->unk8C = 1;
            } else {
                vec_copy(&tB0, &c->unk0);
            }
        } else {
            c->unk0.y = c->unk0.y + 0.125f * (c->unk40.y - c->unk0.y);
            c->unk0.x = c->unk40.x;
            c->unk0.z = c->unk40.z;
        }
    } else {
        vec_copy(&c->unk50, &tB0);
        if (c->unk40.y < tB0.y) {
            tB0.y = 0.5f * (tB0.y + c->unk40.y);
        }
        rad28 = 28.0f;
        mask = 0x8009;
        if ((u8)func_09C3AAA8(D_09D1A060, &tB0, &c->unk40, rad28, &tC0, mask) != 0) {
            if (c->unk8D != 0) {
                vec_copy(&tC0, &c->unk0);
                vec_copy(&tC0, &c->unk20);
            } else {
                f32 r;
                f32 dx;
                f32 dz;
                f32 d2;
                dx = c->unk0.x - c->unk50.x;
                r = c->unk70->unk8;
                tB0.x = dx;
                dz = c->unk0.z - c->unk50.z;
                tB0.z = dz;
                d2 = dx * dx + dz * dz;
                if (d2 > r * r) {
                    f32 k = r / sqrt_vfpu(d2);
                    tA0.x = c->unk50.x + dx * k;
                    tA0.y = c->unk0.y;
                    tA0.z = c->unk50.z + dz * k;
                    if ((u8)func_09C3AAA8(D_09D1A060, &c->unk10, &tA0, rad28, &tC0, mask) != 0) {
                        vec_copy(&tC0, &c->unk0);
                    } else {
                        c->unk0.x = c->unk0.x + 0.666666687f * (tA0.x - c->unk0.x);
                        c->unk0.y = c->unk0.y + 0.666666687f * (tA0.y - c->unk0.y);
                        c->unk0.z = c->unk0.z + 0.666666687f * (tA0.z - c->unk0.z);
                    }
                } else {
                    vec_copy(&tC0, &c->unk0);
                }
            }
        } else {
            c->unk0.y = c->unk0.y + 0.125f * (c->unk40.y - c->unk0.y);
            c->unk0.x = c->unk40.x;
            c->unk0.z = c->unk40.z;
            c->unk8C = 0;
        }
    }

    if (c->unk8C == 0) {
        func_09C36C30(D_09D1A060, &c->unk0);
        func_09C36AA8(D_09D1A060, c->unk74, &c->unk0, &c->unk20);
    }
    if (c->unk8D != 0) {
        c->unk8D--;
    }
    if (func_09C3AAA8(D_09D1A060, &c->unk0, &c->unk40, rad28, &t90, mask) != 0) {
        f32 l;
        vec_sub3(&c->unk10, &c->unk0, &t90);
        l = t90.x * t90.x + t90.z * t90.z;
        if (l > (150.0f + c->unk70->unk8) * (150.0f + c->unk70->unk8)) {
            vec_copy(&c->unk40, &c->unk0);
            vec_copy(&c->unk50, &c->unk20);
            func_09C36C30(D_09D1A060, &c->unk0);
            func_09C36AA8(D_09D1A060, c->unk74, &c->unk0, &c->unk20);
        }
    }

    if (c->unk8C != 0) {
        if ((u16)mode >= 2 && (u16)mode < 5) {
            f32 d1, d2, s;
            ta.x = c->unk50.x - c->unk40.x;
            ta.z = c->unk50.z - c->unk40.z;
            d1 = ta.x * ta.x + ta.z * ta.z;
            tb.x = c->unk10.x - c->unk0.x;
            tb.z = c->unk10.z - c->unk0.z;
            d2 = tb.x * tb.x + tb.z * tb.z;
            if (d1 > d2) {
                s = sqrt_vfpu(d2);
                if (s > 0.0f) {
                    s = sqrt_vfpu(d1) / s;
                    c->unk10.x = c->unk0.x + tb.x * s;
                    c->unk10.z = c->unk0.z + tb.z * s;
                }
            }
        }
    }

    h = func_0888E5B8(arg0, &c->unk0, pl);
    h = h + c->unk70->unk18;
    if (h > c->unk0.y) {
        c->unk0.y = h;
    }
    if (c->unk0.y < c->unk10.y) {
        f32 len, hz;
        vec_sub3(&c->unk0, &c->unk10, &t60);
        sq.x = t60.x * t60.x;
        sq.y = t60.y * t60.y;
        sq.z = t60.z * t60.z;
        len = sq.z + (sq.x + sq.y);
        if (len > 0.0f) {
            hz = sq.x + sq.z;
            if (0.75f > hz / len) {
                hz = sqrt_vfpu(hz);
                hz *= 0.57735002f;
                c->unk10.y = c->unk0.y + hz;
            }
        }
    }

    func_0888E350(arg0, s2);
    func_0888D36C(arg0);
    vec_copy(&c->unk0, &arg0->unk0);
    vec_copy(&c->unk10, &arg0->unk10);
    arg0->unk0.y = arg0->unk0.y + func_0888D1BC(arg0);
    switch (arg0->unk9C) {
    case 0:
        arg0->unk80 = c->unk68;
        arg0->unk88 = c->unk60;
        break;
    case 1:
        vec_copy(&g->unk20, &arg0->unk40);
        vec_copy(&g->unk30, &arg0->unk50);
        arg0->unk84 = g->unkA0;
        arg0->unk8C = g->unkA8;
        arg0->unk9C++;
    case 2: {
        f32 t = func_0888E3DC(arg0);
        f32 u = 1.0f - t;
        vec_lerp(&arg0->unk0, &arg0->unk40, &arg0->unk0, t, u);
        vec_lerp(&arg0->unk10, &arg0->unk50, &arg0->unk10, t, u);
        arg0->unk80 = arg0->unk84 * t + c->unk68 * u;
        arg0->unk88 = arg0->unk8C * t + c->unk60 * u;
        break;
    }
    }

    func_0888F6A0(arg0);
}
