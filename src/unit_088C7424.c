/* unit_088C7424: 0x088C7424-0x088C75D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C7424 (ULES01213)
 *
 * Returns the id of the 0x34-byte area record (same records as
 * func_088C72B0) nearest to a point in the XZ plane, or a default id from
 * D_09CE470C when the owner has no records. Type 0 areas: distance to the
 * circle edge (VFPU vsqrt.s); other types: func_088C75D4.
 * Optimized for speed (constant built with lui/ori); the local vectors are
 * 16-byte aligned.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Area {
    u16 id;
    s16 type;
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
    f32 height;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    char pad24[0x10];
} Area;

typedef struct Owner {
    void *src;
    char pad4[0x280];
    s32 unk284;
} Owner;

extern u16 *D_09CE470C[];
extern Area *func_088C7280(Owner *);
extern s8 func_088C7298(Owner *);
extern f32 func_088C75D4(Owner *, Vec *, Vec *, Vec *, f32);

static inline void sqrt_p(f32 *px, f32 *pr) {
    asm {
        lv.s S000, 0(px)
        vsqrt.s S000, S000
        sv.s S000, 0(pr)
    }
}

u16 func_088C7424(Owner *arg0, s32 arg1, Vec *arg2) {
    f32 sx;
    f32 sr;
    Vec v3 __attribute__((aligned(16)));
    Vec v2 __attribute__((aligned(16)));
    Vec v1 __attribute__((aligned(16)));
    Area *a;
    u16 id;
    s8 i;
    f32 best;
    f32 d;
    f32 dx;
    f32 dz;

    a = func_088C7280(arg0);
    if (a == 0) {
        return *D_09CE470C[arg0->unk284 * 2];
    } else {
        best = 1e10f;
        id = 0;
        for (i = 0; i < func_088C7298(arg0); i++, a++) {
            if (a->type == 0) {
                dx = a->x;
                dz = a->z;
                dx -= arg2->x;
                dz -= arg2->z;
                sx = dx * dx + dz * dz;
                sqrt_p(&sx, &sr);
                d = sr - a->radius;
            } else {
                v3.x = a->x;
                v3.y = 0.0f;
                v3.z = a->z;
                v3.w = 1.0f;
                v2.x = a->unk18;
                v2.y = 0.0f;
                v2.z = a->unk20;
                v2.w = 1.0f;
                v1.x = arg2->x;
                v1.y = 0.0f;
                v1.z = arg2->z;
                v1.w = 1.0f;
                d = func_088C75D4(arg0, &v1, &v3, &v2, a->radius);
            }
            if (best > d) {
                id = a->id;
                best = d;
            }
        }
        return id;
    }
}
