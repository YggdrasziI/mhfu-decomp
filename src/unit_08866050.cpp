/* func_08866050 (ULES01213)
 *
 * C++: virtual calls through the object at *D_09A4F060. The distance is VFPU
 * code in an `asm { }` block; its base registers follow the order of the
 * pointer locals (result pointer first). The table pointer is read into its
 * own local before indexing (keeps the `addu` operand order). Bit 2 of the
 * entry is extracted as `(u32)(e << 29) >> 31` (sll/srl pair).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct Vec4 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct Zone {
    f32 x, y, z;
    f32 near_r;
    f32 far_r;
    u16 near_i;
    u16 far_i;
} Zone;

typedef struct Tbl {
    char pad[0xC];
    u8 *ent;
} Tbl;

struct Obj {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual Tbl *vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual Zone *vfunc_34();
};

extern "C" {

extern Obj **D_09A4F060;
extern char *func_088CC4A8(Obj *);
extern Zone *func_088CC478(Obj *);

static inline f32 dist_vfpu(Vec4 *pa, char *pb) {
    f32 r;
    f32 *pr = &r;
    Vec4 *a = pa;
    char *b = pb;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vsub.t C000, C000, C010
        nop
        vdot.t S010, C000, C000
        vsqrt.s S010, S010
        sv.s S010, 0(pr)
    }
    return r;
}

static inline void pick(char *arg0, char *base, Zone *z) {
    Vec4 v;
    f32 d;

    v.x = z->x;
    v.y = z->y;
    v.z = z->z;
    v.w = 0;
    d = dist_vfpu(&v, arg0 + 0x200);
    if (d <= z->far_r) {
        if (d <= z->near_r) {
            *(char **)(arg0 + 0x1DC) = base + z->near_i * 32;
        } else {
            *(char **)(arg0 + 0x1DC) = base + z->far_i * 32;
        }
    }
}

void func_08866050(char *arg0) {
    u8 a;
    char *base;
    Obj *o;
    u8 b;
    Tbl *t;
    Zone *z;
    u8 e;
    u8 *p;

    *(char **)(arg0 + 0x1DC) = 0;
    o = *D_09A4F060;
    if (o == 0) {
        return;
    }
    base = func_088CC4A8(o);
    if (base == 0) {
        return;
    }
    t = o->vfunc_28();
    if (t == 0) {
        return;
    }
    p = t->ent;
    e = p[*(u8 *)(arg0 + 0x290) * 4];
    a = e & 3;
    b = (u32)(e << 29) >> 31;
    if (a != 0) {
        z = func_088CC478(o);
        if (z != 0) {
            pick(arg0, base, &z[a]);
            return;
        }
    }
    if (b != 0) {
        z = o->vfunc_34();
        if (z != 0) {
            pick(arg0, base, &z[b]);
        }
    }
}

}
