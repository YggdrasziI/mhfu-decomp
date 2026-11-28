/* unit_088C9988: 0x088C9988-0x088C9B00 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C9988: virtual method (vtable entries at 0x089BAD64, 0x089BF690,
 * 0x089BF74C). For each point of the list that passes func_08816060, sets the
 * translation of a local identity matrix (VFPU vmidt.q, notes/COMPILER.md),
 * then picks one of two bytes by the squared distance to func_088140C4. */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

typedef struct Vec {
    Vec3 v;
    f32 w;
} Vec;

typedef struct Mtx {
    f32 m[12];
    Vec3 t;
    f32 tw;
} Mtx;

typedef struct Pts {
    s16 count;
    u8 b2;
    u8 b3;
    f32 radius;
    Vec *pts;
} Pts;

extern char *D_089CBBE4;
extern s32 func_08816060(char *, char *, f32);
extern s32 func_08862354(char *, char *);
extern void func_088140C4(char *, Vec *);
extern s32 func_0886171C(char *, s32, char *, s32);

static inline void dist2(Vec *a, Vec *b, f32 *pr) {
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        sv.s S010, 0(pr)
    }
}

static inline void mtx_identity(Mtx *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

void func_088C9988(char *arg0, char *arg1, Pts *arg2) {
    f32 d;
    Mtx mtx __attribute__((aligned(16)));
    Vec cam __attribute__((aligned(16)));
    Vec *p;
    f32 one;
    s32 i;

    p = arg2->pts;
    one = 1.0f;
    mtx_identity(&mtx);
    mtx.m[0] = one;
    mtx.m[5] = one;
    mtx.m[10] = one;
    for (i = 0; i < arg2->count; i++, p++) {
        if ((u8)func_08816060(D_089CBBE4, (char *)p, arg2->radius) == 1) {
            {
                f32 z = p->v.z;
                f32 y = p->v.y;
                f32 x = p->v.x;
                mtx.t.x = x;
                mtx.t.y = y;
                mtx.t.z = z;
            }
            func_08862354((char *)&mtx, arg1 + 0x10);
            func_088140C4(D_089CBBE4, &cam);
            dist2(p, &cam, &d);
            if (d <= 2250000.0f + arg2->radius * arg2->radius) {
                func_0886171C(arg1, 0, arg0 + 0x70, arg2->b3);
            } else {
                func_0886171C(arg1, 0, arg0 + 0x70, arg2->b2);
            }
        }
    }
    func_08862354(arg0 + 0x10, arg1 + 0x10);
}
