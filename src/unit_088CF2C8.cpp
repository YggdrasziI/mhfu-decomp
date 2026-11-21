/* unit_088CF2C8: 0x088CF2C8-0x088D08D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088CF210 and unit_088D08D4.
 *
 * Runs the 0x18-byte bone animation records of the table at +0x7F4 (records
 * at +8 of the table, count in its byte 2): with bit 0x10 of the flags it
 * updates the 8-byte state of each record (at +0x7F8), with bit 0x20 it
 * applies the state to the local matrix of the record's bone (0x250-byte
 * bones at +0x1090, matrix at +0x150): rotations, scales, translations,
 * key-framed rotations and scales.
 *
 * C++: bool conversions, reference operands. Optimized for speed. The vector
 * and matrix operations are VFPU `asm` blocks (notes/COMPILER.md, "VFPU in
 * asm blocks").
 *
 * Each rotation is a helper (its own matrix, the angle read before the
 * identity) that calls the rotation block, two levels below the function:
 * fully inlined only with the build flag `-inline bottomup`
 * (notes/COMPILER.md, "Inlining depth").
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

typedef struct Item {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    s32 unk4[5];
} Item;

typedef struct Hdr {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    char pad4[4];
    Item *unk8;
} Hdr;

typedef union State {
    float f[2];
    u16 h[2];
    u8 b;
} State;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern float D_089AF984[];
extern u8 D_089AF994[];
extern float D_089AF998[];
extern float D_089AF9A8[];
extern s32 D_089AF9B8[];

extern void func_08852618(char *, s32, float *, float);
extern u32 func_088900C4(char *, s32);
extern char *func_088CF1B0(char *, s32, s32);
extern char *func_088CF1E0(char *, s32, s32);
extern void func_088D1398(char *arg0, char *arg1, float *arg2);
extern void func_088D153C(char *arg0, char *arg1, float *arg2, float *arg3);
extern s32 func_088D1CA8(char *);

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
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

static inline void row3_copy(float *src, float *dst) {
    asm {
        lv.s S000, 0(src)
        lv.s S001, 4(src)
        lv.s S002, 8(src)
        sv.s S000, 0(dst)
        sv.s S001, 4(dst)
        sv.s S002, 8(dst)
    }
}

static inline void mtx_copy(Mtx *dst, Mtx &rs) {
    Mtx *src = &rs;
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

static inline void mtx_mul(Mtx *dst, Mtx *a, Mtx &rb) {
    Mtx *b = &rb;
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C130, 0x30(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        lv.q C230, 0x30(b)
        vmmul.q E000, E100, E200
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
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

static inline void rot_x(Mtx *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vidt.q C000
        vrot.q C010, S100, [0,C,S,0]
        vrot.q C020, S100, [0,-S,C,0]
        vidt.q C030
        vmmov.q E200, E000
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        lv.q C130, 0x30(m)
        vmmul.q E200, E100, E000
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

static inline void rot_y(Mtx *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,0,-S,0]
        vidt.q C010
        vrot.q C020, S100, [S,0,C,0]
        vidt.q C030
        vmmov.q E200, E000
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        lv.q C130, 0x30(m)
        vmmul.q E200, E100, E000
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
    }
}

static inline void rot_z(Mtx *m, float ang) {
    float *pa = &ang;
    asm {
        lv.s S100, 0(pa)
        vcst.s S101, VFPU_2_PI
        vmul.s S100, S100, S101
        vrot.q C000, S100, [C,S,0,0]
        vrot.q C010, S100, [-S,C,0,0]
        vidt.q C020
        vidt.q C030
        vmmov.q E200, E000
        lv.q C100, 0(m)
        lv.q C110, 0x10(m)
        lv.q C120, 0x20(m)
        lv.q C130, 0x30(m)
        vmmul.q E200, E100, E000
        sv.q C200, 0(m)
        sv.q C210, 0x10(m)
        sv.q C220, 0x20(m)
        sv.q C230, 0x30(m)
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

static inline void apply_rot_x(Mtx *mtx, float ang) {
    Mtx m;
    mtx_identity(&m);
    rot_x(&m, ang);
    mtx_mul3(mtx, &m, mtx);
}

static inline void apply_rot_y(Mtx *mtx, float ang) {
    Mtx m;
    mtx_identity(&m);
    rot_y(&m, ang);
    mtx_mul3(mtx, &m, mtx);
}

static inline void apply_rot_z(Mtx *mtx, float ang) {
    Mtx m;
    mtx_identity(&m);
    rot_z(&m, ang);
    mtx_mul3(mtx, &m, mtx);
}

/* The angles are 16-bit turns: degrees first, then radians. */
#define TO_RAD(a) (6.2831855f * (360.0f * (a) / 65536.0f / 360.0f))
#define DEG_TO_RAD(a) (6.2831855f * ((a) / 360.0f))

void func_088CF2C8(char *arg0, u8 arg1, u8 arg2) {
    Vec pos;
    Mtx mtx;
    Mtx scale;
    Vec rot;
    Vec scl;
    Bone *bones;
    Item *item;
    State *state;
    s32 i;
    s32 val;
    u8 flags;
    Bone *bone;
    float f;
    float t;
    float cur;
    s32 in;
    u8 k;
    u16 idx;
    u16 a;
    u32 n;
    float s1;
    float s2;
    float *src;
    u16 w;
    float amp;

    bones = *(Bone **)(arg0 + 0x1090);
    item = (*(Hdr **)(arg0 + 0x7F4))->unk8;
    state = (State *)(arg0 + 0x7F8);
    for (i = 0; i < (*(Hdr **)(arg0 + 0x7F4))->unk2; i++, item++, state++) {
        val = item->unk4[arg1];
        if (item->unk1 == 0xFF) {
            continue;
        }
        if (!(item->unk2 & 8) || !(item->unk2 & 0x60)) {
            bone = &bones[item->unk1];
            vec3_copy(&pos, &bone->unk150.m[12]);
            mtx_identity(&mtx);
            if (item->unk2 & 0x80) {
                src = bones[item->unk1].unk150.m;
                row3_copy(src, &mtx.m[0]);
                row3_copy(src + 4, &mtx.m[4]);
                row3_copy(src + 8, &mtx.m[8]);
            }
        }
        switch (item->unk0) {
        case 0:
        case 1:
        case 2:
            flags = arg2;
            if (flags & 0x10) {
                k = D_089AF994[val];
                if (k != 0) {
                    f = TO_RAD(1 << k);
                } else {
                    f = 0.0f;
                }
                w = item->unk2;
                if (w & 4) {
                    f *= -1.0f;
                }
                if ((w & 0xF00) != 0 && (flags & 3) == 0) {
                    in = 0;
                    cur = state->f[0];
                    if (f - DEG_TO_RAD(5.0f) < cur && cur < DEG_TO_RAD(5.0f) + f) {
                        in = 1;
                    }
                    if (!(u8) in) {
                        state->f[0] = f - D_089AF984[(item->unk2 & 0xF00) >> 8] * (f - cur);
                        state->f[1] = state->f[1] + state->f[0];
                    } else {
                        if (k != 0) {
                            state->f[1] = state->f[1] + f;
                        }
                        state->f[0] = f;
                    }
                } else {
                    state->f[1] = state->f[1] + f;
                }
            }
            if (flags & 0x20) {
                switch (item->unk0) {
                case 0:
                    apply_rot_x(&mtx, state->f[1]);
                    break;
                case 1:
                    apply_rot_y(&mtx, state->f[1]);
                    break;
                case 2:
                    apply_rot_z(&mtx, state->f[1]);
                    break;
                }
            }
            break;
        case 3:
        case 4:
        case 5:
            flags = arg2;
            if (flags & 0x10) {
                if (arg1 != state->b) {
                    state->b = arg1;
                    state->h[1] = 0;
                }
                func_08852618(D_089CC438, val, &state->f[1], (float) state->h[1]);
                if (state->h[1] != 0xFFFF) {
                    state->h[1]++;
                } else {
                    state->h[1] = 0;
                }
            }
            if (flags & 0x20) {
                switch (item->unk0) {
                case 3:
                    apply_rot_x(&mtx, state->f[1]);
                    break;
                case 4:
                    apply_rot_y(&mtx, state->f[1]);
                    break;
                case 5:
                    apply_rot_z(&mtx, state->f[1]);
                    break;
                }
            }
            break;
        case 6:
        case 7:
        case 8:
            flags = arg2;
            if (flags & 0x10) {
                if ((item->unk2 & 0xF00) != 0 && (flags & 3) == 0) {
                    in = 0;
                    t = DEG_TO_RAD((float) val);
                    cur = state->f[0];
                    if (t - DEG_TO_RAD(3.0f) < cur && cur < DEG_TO_RAD(3.0f) + t) {
                        in = 1;
                    }
                    if (!(u8) in) {
                        state->f[0] = t - D_089AF984[(item->unk2 & 0xF00) >> 8] * (t - cur);
                    } else {
                        state->f[0] = t;
                    }
                } else {
                    state->f[0] = DEG_TO_RAD((float) val);
                }
            }
            if (flags & 0x20) {
                switch (item->unk0) {
                case 6:
                    apply_rot_x(&mtx, state->f[0]);
                    break;
                case 7:
                    apply_rot_y(&mtx, state->f[0]);
                    break;
                case 8:
                    apply_rot_z(&mtx, state->f[0]);
                    break;
                }
            }
            break;
        case 9:
        case 10:
        case 11:
            flags = arg2;
            if (flags & 0x10) {
                if ((item->unk2 & 0xF00) != 0 && (flags & 3) == 0) {
                    in = 0;
                    t = 0.01f * (float) val;
                    cur = state->f[0];
                    if (t - 0.001f < cur && cur < 0.001f + t) {
                        in = 1;
                    }
                    if (!(u8) in) {
                        state->f[0] = t - D_089AF984[(item->unk2 & 0xF00) >> 8] * (t - cur);
                    } else {
                        state->f[0] = t;
                    }
                } else {
                    state->f[0] = 0.01f * (float) val;
                }
            }
            if (flags & 0x20) {
                switch (item->unk0) {
                case 9:
                    mtx_scale(&scale, state->f[0], 1.0f, 1.0f);
                    break;
                case 10:
                    mtx_scale(&scale, 1.0f, state->f[0], 1.0f);
                    break;
                case 11:
                    mtx_scale(&scale, 1.0f, 1.0f, state->f[0]);
                    break;
                }
                mtx_mul(&mtx, &mtx, scale);
            }
            break;
        case 12:
        case 13:
        case 14:
            flags = arg2;
            if (flags & 0x10) {
                if ((item->unk2 & 0xF00) != 0 && (flags & 3) == 0) {
                    in = 0;
                    cur = state->f[0];
                    if ((float) val - 0.001f < cur && cur < 0.001f + (float) val) {
                        in = 1;
                    }
                    if (!(u8) in) {
                        state->f[0] = (float) val - D_089AF984[(item->unk2 & 0xF00) >> 8] * ((float) val - cur);
                    } else {
                        state->f[0] = (float) val;
                    }
                } else {
                    state->f[0] = (float) val;
                }
            }
            if (flags & 0x20) {
                switch (item->unk0) {
                case 12:
                    pos.x = state->f[0];
                    break;
                case 13:
                    pos.y = state->f[0];
                    break;
                case 14:
                    pos.z = state->f[0];
                    break;
                }
            }
            break;
        case 15:
            if (arg2 & 0x20) {
                switch (item->unk4[0]) {
                case 0:
                    vec_set(&rot, 0.0f, 0.0f, 0.0f, 0.0f);
                    if (arg1 == 3) {
                        idx = (u8) func_088D1CA8(arg0) - 1;
                        if (func_088CF1B0(arg0, idx, *(u16 *) &item->unk4[1]) != 0) {
                            func_088D153C(arg0, func_088CF1B0(arg0, idx, *(u16 *) &item->unk4[1]), &rot.x, &rot.z);
                        }
                    }
                    vec_set(&rot, DEG_TO_RAD(rot.x), DEG_TO_RAD(rot.y), DEG_TO_RAD(rot.z), 0.0f);
                    mtx_scale(&mtx, 1.0f, 1.0f, 1.0f);
                    mtx_euler(&mtx, rot.x, rot.y, rot.z);
                    break;
                case 1:
                    vec_set(&scl, 1.0f, 1.0f, 1.0f, 0.0f);
                    if (arg1 == 3) {
                        idx = (u8) func_088D1CA8(arg0) - 1;
                        if (func_088CF1E0(arg0, idx, *(u16 *) &item->unk4[1]) != 0) {
                            func_088D1398(arg0, func_088CF1E0(arg0, idx, *(u16 *) &item->unk4[1]), &scl.x);
                        }
                    }
                    mtx_scale(&mtx, scl.x, scl.y, scl.z);
                    break;
                }
            }
            break;
        case 16:
        case 17:
        case 18:
            flags = arg2;
            if (flags & 0x10) {
                if (val != 0) {
                    state->f[0] = (float) func_088900C4(D_08A631A0, 1) / 32768.0f;
                    state->f[0] = state->f[0] * D_089AF998[val] - D_089AF998[val];
                }
            }
            if (flags & 0x20) {
                switch (item->unk0) {
                case 16:
                    pos.x += state->f[0];
                    break;
                case 17:
                    pos.y += state->f[0];
                    break;
                case 18:
                    pos.z += state->f[0];
                    break;
                }
            }
            break;
        case 19:
            if (arg2 & 0x10) {
                if (D_089AF9A8[arg1] != 0.0f) {
                    s1 = sin_vfpu(TO_RAD(state->h[0] << 2));
                    a = (u32) ((float) state->h[0] * s1);
                    s2 = sin_vfpu(TO_RAD(a << D_089AF9B8[arg1]));
                    amp = D_089AF9A8[arg1];
                    f = amp * s2;
                    state->f[1] = f + amp * sin_vfpu(TO_RAD(state->h[0] << 10));
                }
            }
            if (arg2 & 0x20) {
                bone = &bones[item->unk1];
                vec3_copy(&pos, &bone->unk150.m[12]);
                mtx_identity(&mtx);
                apply_rot_z(&mtx, state->f[1]);
                vec3_copy((Vec *) &mtx.m[12], &pos.x);
            }
            state->h[0]++;
            break;
        case 0xFFFF:
            break;
        }
        if (!(item->unk2 & 8) || !(item->unk2 & 0x30)) {
            mtx.m[12] = pos.x;
            mtx.m[13] = pos.y;
            mtx.m[14] = pos.z;
            mtx_copy(&bones[item->unk1].unk150, mtx);
        }
    }
}

}
