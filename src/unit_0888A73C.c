/* unit_0888A73C: 0x0888A73C-0x0888A8C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct Vec {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;
extern char *D_089CC438;
typedef struct Pair {
    f32 a[3];
    f32 b[3];
} Pair;

extern Pair D_08933CA0[];
extern u8 D_089340E4[];
extern f32 D_08934048[];

extern void func_08897BD8(void *arg0, void *arg1, Vec *arg2);

static inline void vec_rot_y(Vec *v, f32 a) {
    f32 *pa = &a;
    asm {
        lv.q C000, 0(v)
        lv.q C100, 0(v)
        lv.s S110, 0(pa)
        vcst.s S111, VFPU_2_PI
        vmul.s S122, S110, S111
        vsin.s S120, S122
        vcos.s S121, S122
        vmul.s S000, S121, S100
        vmul.s S130, S120, S102
        vadd.s S000, S000, S130
        vmul.s S002, S120, S100
        vmul.s S130, S121, S102
        vsub.s S002, S130, S002
        sv.q C000, 0(v)
    }
}

s32 func_0888A73C(char *arg0, void *arg1) {
    char *e;
    Pair *t;
    f32 ang;
    s32 k;
    Vec v;

    e = *(char **)(D_089CBBE4 + 0xA84);
    k = D_089340E4[*(u16 *)(D_089CC438 + 0x6AF0E)];
    t = &D_08933CA0[k];
    ang = 9.58738e-05f * (f32)(s32)*(u16 *)(e + 0x320);
    *(f32 *)(arg0 + 0x88) = D_08934048[k];
    v.x = t->a[0];
    v.y = t->a[1];
    v.z = t->a[2];
    vec_rot_y(&v, ang);
    func_08897BD8(arg0, e + 0x200, &v);
    v.x = t->b[0];
    v.y = t->b[1];
    v.z = t->b[2];
    vec_rot_y(&v, ang);
    func_08897BD8(arg0 + 0x10, e + 0x200, &v);
    return 1;
}
