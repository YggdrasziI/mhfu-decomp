/* unit_088D3F68: 0x088D3F68-0x088D5B54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D3ADC and unit_088D5B54.
 * Its jump table (0x089323EC-0x08932418) is linked from this unit.
 *
 * Kind at +0x1E8 (0 to 10). Picks a matrix of the owner (+0x190) and an
 * offset and three angles for the kind (tables D_089AD628, D_089AFB00 and
 * D_089AFC50), sets the scale, rotation and position of the first four
 * bones (0x250 bytes each, local matrix at +0x150) of the model at +0xF80,
 * runs the bone records (func_088CF2C8), passes the matrix to the virtual
 * function +0xC of the bone array (again with the second array at +0x1094
 * for kinds 3, 4, 6, 9 and 10), then walks the groups of the part at +0xF60:
 * byte 3 of each material gets the value at +0x230 (0 for some materials of
 * group 0, by kind) before the group is drawn.
 *
 * C++: virtual call, reference operands. Optimized for speed. The vector
 * and matrix operations are VFPU `asm` blocks (notes/COMPILER.md, "VFPU in
 * asm blocks").
 *
 * `ident` is set and never read; `one` holds 1.0f for the whole function and
 * is a separate local from `scale` (the original keeps both in registers).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

typedef struct Bone {
    char pad0[0x150];
    Mtx unk150;
    char pad190[0xC0];
} Bone;

typedef struct Mat {
    u8 unk0[16];
} Mat;

typedef struct Part {
    char *unk0;
    s32 unk4;
    Mat *unk8;
} Part;

typedef struct Mdl {
    char pad0[0x110];
    Bone *unk110;
    Bone *unk114;
} Mdl;

typedef struct Hdr {
    char pad0[5];
    u8 unk5;
} Hdr;

typedef struct VFx { virtual void vfunc_08(); virtual void vfunc_0C(char *, Mtx *, float, float, float); } VFx;

#define DEG_TO_RAD(a) (6.2831855f * ((a) / 360.0f))

extern "C" {

extern s32 *D_089CC000;
extern s32 D_089CBFFC;
extern float D_089AD628[][6];
extern Vec D_089AFB00[][9];
extern Vec D_089AFC50[][5];

extern void func_0884CDE4(s32, char *);
extern void func_08860648(Bone *);
extern s32 func_08862748(char *, s32);
extern u8 *func_08862768(char *, s32, s32);
extern void func_0886477C(Part *, Mdl *, char *, s32);
extern void func_088CF2C8(char *arg0, u8 arg1, u8 arg2);
extern void func_088D08D4(char *arg0, u8 arg1, s32 arg2, u8 arg3);
extern s32 func_088D27F4(char *);
extern s32 func_088D2830(char *);
extern s32 func_088D286C(char *);
extern void func_088D5B54(u8 *);

static inline void vec_copy(Vec *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_add(Vec *dst, Vec &ra, Vec &rb) {
    Vec *a = &ra;
    Vec *b = &rb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

/* Rotates and scales `src` by the upper 3x3 part of `mtx`. */
static inline void vec_tfm3(Vec *dst, Mtx *mtx, Vec *src) {
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

static inline void mtx_copy(Mtx *dst, Mtx *src) {
    asm {
        lv.q C000, 0(src)
        lv.q C010, 0x10(src)
        lv.q C020, 0x20(src)
        lv.q C030, 0x30(src)
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void vec3_set(float *dst, float x, float y, float z) {
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

static inline void vec_set(Vec *dst, float x, float y, float z, float w) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    float *pw = &w;
    asm {
        lv.s S000, 0(px)
        lv.s S001, 0(py)
        lv.s S002, 0(pz)
        lv.s S003, 0(pw)
        sv.q C000, 0(dst)
    }
}

static inline void vec3_copy(Vec *dst, float *src) {
    float x = src[0];
    float y = src[1];
    float z = src[2];
    dst->x = x;
    dst->y = y;
    dst->z = z;
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

static inline void mtx_scale(Mtx *dst, float x, float y, float z) {
    mtx_identity(dst);
    dst->m[0] = x;
    dst->m[5] = y;
    dst->m[10] = z;
}

/* Product of the upper 3x3 parts; the rest of `dst` is kept. */
static inline void mtx_mul3(Mtx *dst, Mtx *a, Mtx *b) {
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        vmmul.t E000, E100, E200
        sv.s S000, 0(dst)
        sv.s S001, 4(dst)
        sv.s S002, 8(dst)
        sv.s S010, 0x10(dst)
        sv.s S011, 0x14(dst)
        sv.s S012, 0x18(dst)
        sv.s S020, 0x20(dst)
        sv.s S021, 0x24(dst)
        sv.s S022, 0x28(dst)
    }
}

/* Rotation matrix from three angles (radians), written over `m`. */
static inline void mtx_euler(Mtx *m, float x, float y, float z) {
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

#define KIND (*(u8 *)(arg0 + 0x1E8))
#define FOG (*(u8 *)(arg0 + 0x230))
#define POS(b) (&(b)->unk150.m[12])

void func_088D3F68(char *arg0) {
    /* The stack slots are in the reverse of this order. */
    Vec ofs;
    Vec pos;
    Vec rot;
    Vec tmp;
    Vec scl;
    Vec scl2;
    Mtx world;
    Mtx smtx;
    Mtx ident;
    char *p = *(char **)(arg0 + 0x190);
    Part *part = (Part *)(arg0 + 0xF60);
    Mdl *mdl = (Mdl *)(arg0 + 0xF80);
    char *ctx = arg0 + 0x10C0;
    Bone *bones = *(Bone **)(arg0 + 0x1090);
    s32 i;
    s32 n;
    u8 *ids;
    s32 j;
    Mat *m;
    s32 idx;
    float *e;
    float one;
    float scale;
    Mtx *m2;
    Mtx *m3;

    mtx_identity(&ident);
    one = 1.0f;
    switch (KIND) {
    case 4:
        mtx_copy(&world, (Mtx *)(p + 0x1560));
        break;
    case 6:
        mtx_copy(&world, (Mtx *)(p + 0x1560));
        break;
    default:
        mtx_copy(&world, (Mtx *)(p + 0x17B0));
        break;
    }
    switch (KIND) {
    case 6:
        idx = (*(Hdr **)(arg0 + 0x7F4))->unk5;
        vec_copy(&ofs, &D_089AFB00[idx][5]);
        vec_copy(&rot, &D_089AFB00[idx][6]);
        vec_tfm3(&tmp, (Mtx *)(p + 0x1560), &ofs);
        break;
    case 10:
        idx = (*(Hdr **)(arg0 + 0x7F4))->unk5;
        vec_copy(&ofs, &D_089AFC50[idx][3]);
        vec_copy(&rot, &D_089AFC50[idx][4]);
        vec_tfm3(&tmp, (Mtx *)(p + 0x17B0), &ofs);
        break;
    default:
        e = D_089AD628[KIND];
        vec_set(&ofs, e[0], e[1], e[2], 0.0f);
        vec_set(&rot, e[3], e[4], e[5], 0.0f);
        vec_tfm3(&tmp, (Mtx *)(p + 0x17B0), &ofs);
        break;
    }
    vec_add((Vec *) &world.m[12], *(Vec *) &world.m[12], tmp);
    switch (KIND) {
    case 1:
    case 10:
        vec3_copy(&pos, POS(&bones[3]));
        mtx_scale(&bones[3].unk150, one, 0.0f, 3.0f);
        vec3_copy((Vec *) POS(&bones[3]), &pos.x);
        scale = 0.8f;
        break;
    case 5:
        vec3_copy(&pos, POS(&bones[3]));
        mtx_scale(&bones[3].unk150, 1.0f, 0.0f, 3.0f);
        vec3_copy((Vec *) POS(&bones[3]), &pos.x);
        vec3_copy(&pos, POS(&bones[2]));
        mtx_scale(&bones[2].unk150, 1.0f, 1.0f, 0.5f);
        vec3_copy((Vec *) POS(&bones[2]), &pos.x);
        scale = 1.0f;
        break;
    case 4:
    case 6:
        scale = one;
        break;
    case 3:
        scale = 0.9f;
        vec3_copy(&pos, POS(&bones[2]));
        mtx_scale(&bones[2].unk150, 1.0f, 1.0f, 0.45f);
        vec3_copy((Vec *) POS(&bones[2]), &pos.x);
        break;
    case 7:
    default:
        scale = 0.8f;
        break;
    }
    mtx_identity(&bones[0].unk150);
    mtx_euler(&bones[0].unk150, rot.x, rot.y, rot.z);
    mtx_scale(&smtx, scale, scale, scale);
    mtx_mul3(&bones[0].unk150, &bones[0].unk150, &smtx);
    switch (KIND) {
    case 2:
        vec3_copy(&pos, POS(&bones[3]));
        scl.x = one;
        mtx_scale(&bones[3].unk150, one, one, one);
        vec3_copy((Vec *) POS(&bones[3]), &pos.x);
        break;
    case 8:
        m2 = &bones[2].unk150;
        vec3_copy(&ofs, &m2->m[12]);
        m3 = &bones[3].unk150;
        vec3_copy(&pos, &m3->m[12]);
        vec_set(&rot, 0.0f, 0.0f, 0.0f, 0.0f);
        vec_set(&scl, 1.0f, 1.0f, 1.0f, 0.0f);
        rot.x = DEG_TO_RAD(rot.x);
        rot.y = DEG_TO_RAD(rot.y);
        rot.z = DEG_TO_RAD(rot.z);
        mtx_scale(m2, 1.0f, 1.0f, 1.0f);
        mtx_euler(m2, rot.x, rot.y, rot.z);
        vec3_copy((Vec *) &m2->m[12], &ofs.x);
        mtx_scale(m3, scl.x, scl.y, scl.z);
        vec3_copy((Vec *) &m3->m[12], &pos.x);
        break;
    case 0:
    case 7:
        m2 = &bones[2].unk150;
        vec3_copy(&pos, &m2->m[12]);
        m3 = &bones[3].unk150;
        vec3_copy(&ofs, &m3->m[12]);
        vec_set(&scl2, 1.0f, 1.0f, 1.0f, 0.0f);
        scl.z = 0.73f;
        mtx_scale(m2, 1.0f, 1.0f, scl.z);
        vec3_copy((Vec *) &m2->m[12], &pos.x);
        mtx_scale(m3, scl2.x, scl2.y, scl2.z);
        vec3_copy((Vec *) &m3->m[12], &ofs.x);
        break;
    case 3:
        m2 = &bones[2].unk150;
        vec3_copy(&pos, &m2->m[12]);
        scl.z = 0.45f;
        mtx_scale(m2, 1.0f, 1.0f, scl.z);
        vec3_copy((Vec *) &m2->m[12], &pos.x);
        break;
    case 1:
    case 5:
        if (KIND == 5) {
            vec3_copy(&ofs, POS(&bones[3]));
        } else {
            vec3_copy(&ofs, POS(&bones[3]));
            mtx_euler(&bones[2].unk150, DEG_TO_RAD(180.0f), 0.0f, 0.0f);
        }
        scl.x = 1.0f;
        scl.y = 1.0f;
        scl.z = 1.0f;
        mtx_euler(&bones[1].unk150, 0.0f, 0.0f, 0.0f);
        if (KIND == 1) {
            mtx_euler(&bones[2].unk150, 0, 0, 0);
        }
        mtx_euler(&bones[3].unk150, 0.0f, 0.0f, 0.0f);
        if (KIND == 5) {
            scl.y = 0.4f;
            scl.z = 2.2f;
        } else {
            scl.x = -0.5f;
            scl.z = 3.0f;
        }
        mtx_scale(&bones[3].unk150, scl.x, scl.y, scl.z);
        vec3_set(POS(&bones[3]), ofs.x, ofs.y, ofs.z);
        break;
    case 9:
        vec_set(&rot, 0.0f, 0.0f, 0.0f, 0.0f);
        rot.x = 180.0f;
        m2 = &bones[2].unk150;
        vec3_copy(&pos, &m2->m[12]);
        m3 = &bones[3].unk150;
        vec3_copy(&ofs, &m3->m[12]);
        mtx_euler(m2, DEG_TO_RAD(rot.x), 0.0f, 0.0f);
        vec3_copy((Vec *) &m2->m[12], &pos.x);
        vec_set(&rot, 0.0f, 0.0f, 0.0f, 0.0f);
        mtx_euler(m3, DEG_TO_RAD(rot.x), DEG_TO_RAD(rot.y), DEG_TO_RAD(rot.z));
        vec3_copy((Vec *) &m3->m[12], &ofs.x);
        break;
    case 10:
        m2 = &bones[2].unk150;
        vec3_copy(&pos, &m2->m[12]);
        m3 = &bones[3].unk150;
        vec3_copy(&ofs, &m3->m[12]);
        vec_set(&scl, 1.0f, 1.0f, 1.0f, 0.0f);
        vec_set(&rot, 0.0f, 0.0f, 0.0f, 0.0f);
        mtx_euler(m2, DEG_TO_RAD(rot.x), 0.0f, 0.0f);
        vec3_copy((Vec *) &m2->m[12], &pos.x);
        mtx_scale(m3, scl.x, scl.y, scl.z);
        vec3_copy((Vec *) &m3->m[12], &ofs.x);
        break;
    }
    func_088D5B54((u8 *) arg0);
    func_088CF2C8(arg0, *(u8 *)(arg0 + 0x612), 0x20);
    ((VFx *) bones)->vfunc_0C(arg0 + 0x10, &world, 1.0f, 1.0f, 1.0f);
    func_08860648(bones);
    if (KIND == 3 || KIND == 9 || KIND == 4 || KIND == 6 || KIND == 10) {
        bones = mdl->unk114;
        switch (KIND) {
        case 4:
            mtx_copy(&world, (Mtx *)(p + 0x27E0));
            mtx_euler(&bones[0].unk150, DEG_TO_RAD(-26.0f), DEG_TO_RAD(-3.0f), DEG_TO_RAD(8.0f));
            vec_set(&ofs, -21.0f, 2.2f, 5.0f, 0.0f);
            break;
        case 3:
            mtx_copy(&world, (Mtx *)(p + 0x27E0));
            mtx_euler(&bones[0].unk150, DEG_TO_RAD(21.0f), DEG_TO_RAD(-172.0f), DEG_TO_RAD(-2.5f));
            vec_set(&ofs, -18.0f, 2.0f, -14.0f, 0.0f);
            break;
        case 9:
            mtx_copy(&world, (Mtx *)(p + 0x27E0));
            vec_set(&ofs, -18.0f, 2.0f, -14.0f, 0.0f);
            vec_set(&rot, DEG_TO_RAD(21.0f), DEG_TO_RAD(172.0f), DEG_TO_RAD(-2.5f), 0.0f);
            mtx_identity(&bones[0].unk150);
            mtx_euler(&bones[0].unk150, rot.x, rot.y, rot.z);
            break;
        case 6:
            mtx_copy(&world, (Mtx *)(p + 0x1560));
            idx = (*(Hdr **)(arg0 + 0x7F4))->unk5;
            vec_copy(&ofs, &D_089AFB00[idx][7]);
            vec_copy(&rot, &D_089AFB00[idx][8]);
            mtx_identity(&bones[0].unk150);
            mtx_euler(&bones[0].unk150, rot.x, rot.y, rot.z);
            break;
        case 10:
            mtx_copy(&world, (Mtx *)(p + 0x530));
            vec_set(&ofs, 8.5f, 0.5f, -20.0f, 0.0f);
            vec_set(&rot, DEG_TO_RAD(-10.0f), 0.0f, DEG_TO_RAD(-16.0f), 0.0f);
            mtx_identity(&bones[0].unk150);
            mtx_euler(&bones[0].unk150, rot.x, rot.y, rot.z);
            break;
        }
        vec_tfm3(&tmp, &world, &ofs);
        vec_add((Vec *) &world.m[12], *(Vec *) &world.m[12], tmp);
        ((VFx *) bones)->vfunc_0C(arg0 + 0x10, &world, 1.0f, 1.0f, 1.0f);
        func_08860648(bones);
    }
    func_0884CDE4(D_089CBFFC, arg0 + 0x10);
    for (i = 0; i < *(u16 *)(part->unk0 + 0x1C); i++) {
        n = (u8) func_08862748(part->unk0, i);
        ids = func_08862768(part->unk0, i, 0);
        for (j = 0; j < n; j++) {
            m = &part->unk8[*ids++];
            m->unk0[3] = FOG;
            if (i == 0) {
                if (KIND == 1 || KIND == 5) {
                    if (j == 1) {
                        if (!(u8) func_088D286C(arg0)) {
                            m->unk0[3] = 0;
                        }
                    }
                    if (j == 2) {
                        if (KIND == 1) {
                            if (!(u8) func_088D2830(arg0)) {
                                m->unk0[3] = 0;
                                continue;
                            }
                        }
                        if (KIND == 5) {
                            if (!(u8) func_088D27F4(arg0)) {
                                m->unk0[3] = 0;
                            }
                        }
                    }
                } else if (KIND == 7) {
                    switch (j) {
                    case 0:
                    case 3:
                    case 4:
                        m->unk0[3] = FOG;
                        break;
                    default:
                        m->unk0[3] = 0;
                        break;
                    }
                }
            }
        }
        func_088D08D4(arg0, *(u8 *)(arg0 + 0x612), i, 0x20);
        func_0886477C(part, mdl, ctx, i);
        *D_089CC000 = 0x4A000000;
        D_089CC000++;
        *D_089CC000 = 0x4B000000;
        D_089CC000++;
        *D_089CC000 = 0xE0FFFFFF;
        D_089CC000++;
        if (FOG == 0xFF) {
            *D_089CC000 = 0x21000000;
            D_089CC000++;
            *D_089CC000 = 0xDBFFC007;
            D_089CC000++;
        }
    }
}

}
