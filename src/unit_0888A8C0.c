/* unit_0888A8C0: 0x0888A8C0-0x0888AF68 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Case 0 of the state switch is `if (mode != 0) { ...; break; } return;`:
 * an `if` whose join is an explicit `return;` keeps, for the whole function,
 * the dead copies of branch-likely slot instructions after each `b` that the
 * original has. The jump table of the second switch is jtbl_08931984
 * (0x08931984, 6 words, 0x18 bytes).
 */

/* func_0888A8C0: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    Vec pos;
    Vec tgt;
    char pad20[0x60];
    f32 f80;
    char pad84[4];
    f32 f88;
    char pad8C[5];
    u8 f91;
} Cam;

typedef struct {
    u8 state;
    char pad01[3];
    char *ptr[3];
    Vec v10;
    Vec v20;
    u8 mode;
    u8 kind[3];
    s16 duration;
    s16 timer;
    f32 a[3];
    f32 b[3];
    f32 f50;
    s32 count;
    f32 c[6];
    Vec pos[3];
    Vec tgt[3];
} State;

extern char *D_089CBBE4;
extern s32 D_08A62C68;

extern float func_0888AF68(s32 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_08897BD8(Vec *arg0, Vec *arg1, Vec *arg2);

/* Parameter order (source first) sets the base registers of the original. */
static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

/* dst = a * ta + b * tb; the parameter order sets the base registers. */
static inline void vec_blend(Vec *b, Vec *a, Vec *dst, float ta, float tb) {
    float *pa = &ta;
    float *pb = &tb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        lv.s S020, 0(pa)
        lv.s S021, 0(pb)
        vscl.t C100, C000, S020
        vscl.t C110, C010, S021
        vadd.t C000, C100, C110
        sv.q C000, 0(dst)
    }
}

/* Same as vec_blend, other parameter order (first midpoint of case 0). */
static inline void vec_blend_mid(Vec *a, Vec *dst, Vec *b, float ta, float tb) {
    float *pa = &ta;
    float *pb = &tb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        lv.s S020, 0(pa)
        lv.s S021, 0(pb)
        vscl.t C100, C000, S020
        vscl.t C110, C010, S021
        vadd.t C000, C100, C110
        sv.q C000, 0(dst)
    }
}

static inline void vec_sub3(Vec *dst, Vec *a, Vec *b) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        sv.q C000, 0(dst)
    }
}

static inline void vec_normalize4(Vec *dst, Vec *src) {
    asm {
        lv.q C000, 0(src)
        vdot.q S010, C000, C000
        vzero.s S011
        vcmp.s ez, S010, S010
        nop
        vrsq.s S010, S010
        vcmovt.s S010, S011, 0
        vpfxd [-1:1],[-1:1],[-1:1],[-1:1]
        vscl.q C000, C000, S010
        sv.q C000, 0(dst)
    }
}

static inline void vec_scale3(Vec *dst, Vec *src, float s) {
    float *ps = &s;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(ps)
        vscl.t C000, C000, S010
        sv.q C000, 0(dst)
    }
}

void func_0888A8C0(Cam *arg0, State *arg1) {
    char *g;
    char *base;
    Cam *cam;
    s32 i;
    u8 state;
    char *p;
    float t;
    float hiA, loA, loB, hiB;
    Vec dir;

    g = D_089CBBE4;
    base = *(char **)(g + 0xA84);
    {
        char *e = g + *(u8 *)(g + 0xA8D) * 0x1A0;
        cam = (Cam *)(e + 0xB0);
        arg0->f91 = 0;
        vec_copy(&cam->pos, &arg1->pos[0]);
        vec_copy(&cam->tgt, &arg1->tgt[0]);
        arg1->c[0] = cam->f88;
    }

    state = arg1->state;
    switch (state) {
    case 0:
        if (arg1->mode != 0) {
            if (arg1->mode == 1) {
                arg1->timer = 0;
            }
            arg1->state++;
            if (arg1->count != 0) {
                vec_copy(&arg0->pos, &arg1->pos[arg1->count]);
                vec_copy(&arg0->tgt, &arg1->tgt[arg1->count]);
                arg1->c[arg1->count] = arg0->f88;
            }
            arg1->count++;
            break;
        }
        return;
    case 1:
        if (arg1->mode == 3) {
            arg1->state = state + 1;
            break;
        }
        if (arg1->timer < arg1->duration) {
            if (++arg1->timer >= arg1->duration) {
                arg1->mode = 2;
            }
        }
        break;
    case 2:
        if (arg1->timer > 0) {
            arg1->timer--;
        }
        if (arg1->mode == 1) {
            arg1->state = 1;
            break;
        }
        if (arg1->timer == 0) {
            if (--arg1->count != 0) {
                arg1->state = 1;
                arg1->mode = 2;
                arg1->timer = 15;
                arg1->duration = 15;
            } else {
                arg1->state = 0;
                arg1->mode = 0;
                arg1->timer = 0;
                return;
            }
        }
        break;
    }

    i = arg1->count - 1;
    t = func_0888AF68((s32)arg0, arg1->timer, arg1->duration, arg1->state);
    switch (arg1->kind[i]) {
    case 0:
        p = arg1->ptr[i];
        if (*(u8 *)(p + 0x1E8) == 4) {
            vec_blend_mid((Vec *)(base + 0x200), &arg1->v20, (Vec *)(p + 0x200), 0.5f, 0.5f);
            arg1->v20.y += 64.0f;
        } else {
            vec_blend(&arg1->v10, (Vec *)(base + 0x200), &arg1->v20, 0.5f, 0.5f);
            arg1->v20.y += 150.0f;
        }
        vec_copy(&arg1->pos[i], &arg0->pos);
        break;
    case 1:
    case 4:
    case 5:
        if (*(u8 *)(D_089CBBE4 + 0xAA9) == 1) {
            switch (arg1->kind[i]) {
            case 1:
            case 5:
                hiA = 160.0f;
                loA = 40.0f;
                loB = 120.0f;
                hiB = 375.0f;
                break;
            case 4:
                hiA = 175.0f;
                loA = 120.0f;
                loB = loA;
                hiB = 375.0f;
                break;
            }
            if (D_08A62C68 & 0x10) {
                arg1->a[i] += 2.0f;
                if (arg1->a[i] > hiA) {
                    arg1->a[i] = hiA;
                }
            }
            if (D_08A62C68 & 0x40) {
                arg1->a[i] -= 2.0f;
                if (arg1->a[i] < loA) {
                    arg1->a[i] = loA;
                }
            }
            if (D_08A62C68 & 0x80) {
                arg1->b[i] -= 8.0f;
                if (arg1->b[i] < loB) {
                    arg1->b[i] = loB;
                }
            }
            if (D_08A62C68 & 0x20) {
                arg1->b[i] += 8.0f;
                if (arg1->b[i] > hiB) {
                    arg1->b[i] = hiB;
                }
            }
        }
    case 3:
        vec_copy((Vec *)(base + 0x200), &arg1->v20);
        arg1->v20.y += arg1->a[i];
        vec_sub3(&dir, &arg1->pos[i], &arg1->v20);
        vec_normalize4(&dir, &dir);
        vec_scale3(&dir, &dir, arg1->b[i]);
        func_08897BD8(&dir, &arg1->v20, &dir);
        vec_blend(&arg1->pos[i], &dir, &arg0->pos, t, 1.0f - t);
        break;
    case 2:
        vec_blend(&arg1->pos[i], &arg1->v10, &arg0->pos, t, 1.0f - t);
        break;
    }

    vec_blend(&arg1->tgt[i], &arg1->v20, &arg0->tgt, t, 1.0f - t);
    arg0->f88 = arg1->f50 * t + arg1->c[i] * (1.0f - t);
    arg0->f80 = cam->f80;
    arg0->f91 = 1;
}
