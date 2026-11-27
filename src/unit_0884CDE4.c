/* unit_0884CDE4: 0x0884CDE4-0x0884D06C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

extern f32 *D_08A62C40;
extern char *D_089CBBE4;
extern u32 *D_089CC000;

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_mul(Mtx *dst, Mtx *a, Mtx *b) {
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C130, 0x30(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        lv.q C230, 0x30(b)
        vmmul.q E000, E200, E100
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

void func_0884CDE4(s32 arg0, Mtx *arg1) {
    Mtx m;
    f32 s;
    u32 *p;

    s = *D_08A62C40;
    mtx_identity(&m);
    m.m[0] = s;
    m.m[5] = s;
    m.m[10] = s;
    mtx_mul(&m, &m, arg1);
    mtx_mul(&m, (Mtx *)(D_089CBBE4 + 0xBC0), &m);
    *D_089CC000 = 0x3A000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[0] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[1] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[2] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[4] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[5] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[6] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[8] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[9] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[10] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[12] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[13] >> 8) | 0x3B000000;
    p = D_089CC000;
    D_089CC000 = p + 1;
    p[1] = (*(u32 *)&m.m[14] >> 8) | 0x3B000000;
    D_089CC000++;
}
