/* unit_08886B68: 0x08886B68-0x08886E50 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Sets up the record at arg0 + 0xA0: picks a 0x20-byte element table
 * (D_08933AE0 or the table of the object at +0xA90 of D_089CBBE4) and one of
 * its elements, builds a rotation from the angle at +0x1F4 of the object at
 * +0xA84 (plus 0x8000), rotates the element offset with it and sets the
 * positions, then clears the state fields.
 *
 * Optimized for speed. The vector and matrix operations are VFPU `asm`
 * blocks (notes/COMPILER.md, "VFPU in asm blocks"). The first angle goes
 * through an `s32` local `ix` (the conversion of the zero angle is then
 * scheduled before the constant). `vec_tfm3` takes `src` before `dst` so
 * that the source address gets the first base register.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct IVec {
    s32 x, y, z, w;
} __attribute__((aligned(16))) IVec;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern char *D_089CBBE4;
extern char *D_09D1A060;
extern char D_08933AE0[];

extern float func_09C3DA00(char *, char *);

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

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

static inline void vec_copy(void *dst, void *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

typedef struct Elem {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char padC[4];
    f32 unk10;
    char pad14[0xC];
} Elem;

typedef struct Obj {
    Vec unk0;
    Vec unk10;
    Vec unk20;
    f32 unk30;
    s8 unk34;
    u8 unk35;
    s16 unk36;
    s32 unk38;
    char pad3C[4];
    Vec unk40;
    Vec unk50;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    Elem *unk6C;
    Elem *unk70;
    s32 unk74;
    s32 unk78;
    char pad7C[4];
    s16 unk80;
    s16 unk82;
    char pad84[4];
    u8 unk88;
    u8 unk89;
    u8 unk8A;
    u8 unk8B;
    u8 unk8C;
    u8 unk8D;
    u8 unk8E;
    u8 unk8F;
    u8 unk90;
    char pad91[3];
    s32 unk94;
} Obj;

#define F32(p, o) (*(f32 *)((char *)(p) + (o)))
#define S32(p, o) (*(s32 *)((char *)(p) + (o)))
#define U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define PTR(p, o) (*(char **)((char *)(p) + (o)))

void func_08886B68(char *arg0) {
    Mtx m;
    Vec v;
    Vec out;
    IVec iang;
    Vec rot;
    Obj *q = (Obj *)(arg0 + 0xA0);
    char *ctx = D_089CBBE4;
    char *g = PTR(ctx, 0xA84);
    char *t;
    u8 n;
    s32 ix;

    U8(arg0, 0x92) = 0xFF;
    t = PTR(ctx, 0xA90);
    if (U8(t, 2) != 0) {
        q->unk6C = (Elem *)D_08933AE0;
    } else {
        q->unk6C = (Elem *)(t + 0x20);
    }
    n = U8(ctx, 0x14);
    if (n == 0) {
        q->unk70 = q->unk6C + 5;
    } else {
        q->unk70 = (Elem *)((char *)q->unk6C + (n - 1) * 0x20 + 0x20);
    }
    q->unk60 = q->unk64 = q->unk6C->unk0;
    q->unk68 = q->unk6C->unk4;
    iang.x = 0;
    iang.y = q->unk82 = S32(g, 0x1F4) + 0x8000;
    iang.z = 0;
    iang.w = 0;
    ix = (u16)iang.x;
    rot.x = 9.58738e-5f * (f32)ix;
    rot.y = 9.58738e-5f * (f32)(s32)(u16)iang.y;
    rot.z = 9.58738e-5f * (f32)(s32)(u16)iang.z;
    rot.w = 0.0f;
    mtx_identity(&m);
    mtx_euler(&m, rot.x, rot.y, rot.z);
    v.x = 0.0f;
    v.w = 0.0f;
    v.y = q->unk70->unk4;
    v.z = q->unk70->unk8;
    vec_tfm3(&m, &v, &out);
    q->unk10.x = F32(g, 0x200);
    q->unk10.y = F32(g, 0x204) + q->unk70->unk10;
    q->unk10.z = F32(g, 0x208);
    q->unk0.x = q->unk10.x + out.x;
    q->unk0.y = F32(g, 0x204) + out.y;
    q->unk0.z = q->unk10.z + out.z;
    q->unk80 = q->unk82;
    vec_copy(&q->unk40, &q->unk0);
    vec_copy(&q->unk50, &q->unk10);
    q->unk30 = func_09C3DA00(D_09D1A060, (char *)&q->unk10);
    q->unk34 = -1;
    q->unk90 = 0;
    vec_copy(&q->unk20, &q->unk0);
    q->unk88 = 0;
    q->unk74 = 0;
    q->unk38 = 0;
    q->unk78 = 0;
    q->unk8A = 0;
    q->unk35 = 0;
    q->unk36 = 0;
    q->unk94 = 0x1E;
    q->unk8C = 0;
    q->unk8B = 0;
    q->unk8E = 0;
    q->unk8F = 0;
    q->unk8D = 0;
}
