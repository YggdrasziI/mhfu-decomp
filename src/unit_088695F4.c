/* unit_088695F4: 0x088695F4-0x08869750 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Entry {
    u16 id;
    u16 pad;
    f32 x;
    f32 y;
    f32 z;
} Entry;

extern Entry D_089A609C[];
extern char *D_089CC438;

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

static inline float vec_dist2(Vec *a, Vec *b) {
    float r;
    float *pr = &r;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_088695F4(void *arg0, f32 *out, f32 *pos) {
    Vec base;
    Vec v;
    s32 n;
    u32 i;
    Entry *e;

    e = D_089A609C;
    vec_set(&base, pos[0], pos[1], pos[2], 1.0f);
    n = 0;
    for (i = 0; i < 0x172; i++, e++) {
        if (e->id == *(u16 *)(D_089CC438 + 0x6AF0E)) {
            vec_set(&v, e->x, e->y, e->z, 1.0f);
            if (vec_dist2(&base, &v) <= pos[3] * pos[3]) {
                out[0] = v.x;
                out[1] = v.y;
                out[2] = v.z;
                n++;
            }
        }
    }
    if (n == 0) {
        out[0] = base.x;
        out[1] = base.y;
        out[2] = base.z;
    }
}
