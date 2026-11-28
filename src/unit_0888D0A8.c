/* unit_0888D0A8: 0x0888D0A8-0x0888D1BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Computes a target position into arg1 from the record at arg2: the
 * mode byte at +4 selects a plain copy of +0x2C (0), the point at +0x38
 * transformed by the matrix at +0x10 of the object at +0xA84 of
 * D_089CBBE4 (1), or that object's position at +0x200 plus the offset at
 * +0x44 (2). The byte at +3 then overrides some components with +0x2C.
 *
 * The transform is a VFPU `asm` block (notes/COMPILER.md, "VFPU in asm
 * blocks").
 */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;

#define F32(p, o) (*(f32 *)((char *)(p) + (o)))
#define U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define PTR(p, o) (*(char **)((char *)(p) + (o)))

static inline void vec_tfm(Vec *src, char *mtx, Vec *dst) {
    asm {
        lv.q C100, 0(src)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        lv.q C230, 0x30(mtx)
        vcst.s S003, 0
        vtfm3.t C000, E200, C100
        vadd.t C000, C000, C230
        sv.q C000, 0(dst)
    }
}

void func_0888D0A8(char *arg0, Vec *out, char *rec) {
    Vec v;
    char *g = PTR(D_089CBBE4, 0xA84);

    switch (U8(rec, 4)) {
    case 0:
        out->x = F32(rec, 0x2C);
        out->y = F32(rec, 0x30);
        out->z = F32(rec, 0x34);
        break;
    case 1:
        v.x = F32(rec, 0x38);
        v.y = F32(rec, 0x3C);
        v.z = F32(rec, 0x40);
        v.w = 1.0f;
        vec_tfm(&v, g + 0x10, out);
        break;
    case 2:
        out->x = F32(g, 0x200) + F32(rec, 0x44);
        out->y = F32(g, 0x204) + F32(rec, 0x48);
        out->z = F32(g, 0x208) + F32(rec, 0x4C);
        out->w = 1.0f;
        break;
    }
    switch (U8(rec, 3)) {
    case 0:
        out->y = F32(rec, 0x30);
        break;
    case 1:
        out->x = F32(rec, 0x2C);
        out->z = F32(rec, 0x34);
        break;
    }
}
