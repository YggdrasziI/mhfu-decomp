/* unit_0888B6AC: 0x0888B6AC-0x0888B7FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888B6AC: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct {
    f32 m[16];
} __attribute__((aligned(16))) Mtx;

extern char *D_089CBBE4;

extern void func_08897BD8(Vec *arg0, Vec *arg1, Vec *arg2);

static inline void clear(char *q, u32 n) {
    if (q != 0) {
        do {
            *q = 0;
            n--;
            q++;
        } while (n != 0);
    }
}

static inline void vec_copy(Vec *src, Vec *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

static inline void vec_tfm_pt(Vec *dst, Vec *src, Mtx *mtx) {
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

void func_0888B6AC(s32 arg0, Vec *arg1, char *arg2, Vec *arg3) {
    Vec t;
    Vec v;
    char *pl = *(char **)(D_089CBBE4 + 0xA84);

    switch (*(u8 *)(arg2 + 4)) {
    case 0:
        vec_copy(arg3, arg1);
        break;
    case 1: {
        clear((char *)&t, 16);
        t.x = *(f32 *)(arg2 + 0x290);
        t.y = *(f32 *)(arg2 + 0x294);
        t.z = *(f32 *)(arg2 + 0x298);
        vec_tfm_pt(arg1, &t, (Mtx *)(pl + 0x10));
        break;
    }
    case 2:
        clear((char *)&v, 16);
        v.x = *(f32 *)(arg2 + 0x29C);
        v.y = *(f32 *)(arg2 + 0x2A0);
        v.z = *(f32 *)(arg2 + 0x2A4);
        func_08897BD8(arg1, (Vec *)(pl + 0x200), &v);
        break;
    }
    switch (*(u8 *)(arg2 + 3)) {
    case 0:
        arg1->y = arg3->y;
        break;
    case 1:
        arg1->x = arg3->x;
        arg1->z = arg3->z;
        break;
    }
}
