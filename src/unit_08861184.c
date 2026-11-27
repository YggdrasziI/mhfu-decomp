/* unit_08861184: 0x08861184-0x088614DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08861184: writes three groups of GE words (light position through
 * the matrix at D_089CBBE4 + 0xBC0, light type, two colours) for entry arg1.
 *
 * `k` (i * 3) must be u32 and the colour word written
 * `(col.w & 0xFFFFFF) | (u32)((k + K) << 24)` for the register allocation
 * and the `or` operand order; the matrix pointer is the second argument of
 * the VFPU helper so that it gets a0. */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef union Color {
    u32 w;
    u8 c[4];
} Color;

typedef struct Vec {
    u32 w[4];
} __attribute__((aligned(16))) Vec;

extern u32 *D_089CC000;
extern char *D_089CBBE4;

static inline void xform(Vec *out, float *m, float *v) {
    asm {
        lv.q C100, 0x0(v)
        lv.q C200, 0x0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
        sv.q C000, 0x0(out)
    }
}

void func_08861184(char *arg0, s8 arg1) {
    char *base;
    s32 i;
    u32 k;
    float *e;
    Vec v;
    Color col;

    base = arg0 + arg1 * 160 + 0x10;
    i = 0;
    do {
        k = i * 3;
        e = (float *)(base + k * 16 + 0x10);
        xform(&v, (float *)(D_089CBBE4 + 0xBC0), e + 8);
        *D_089CC000++ = (v.w[0] >> 8) | ((k + 0x63) << 24);
        *D_089CC000++ = (v.w[1] >> 8) | ((k + 0x64) << 24);
        *D_089CC000++ = (v.w[2] >> 8) | ((k + 0x65) << 24);
        *D_089CC000++ = (i + 0x5F) << 24;
        col.c[0] = 255.0f * e[0];
        col.c[1] = 255.0f * e[1];
        col.c[2] = 255.0f * e[2];
        *D_089CC000++ = (col.w & 0xFFFFFF) | (u32)((k + 0x90) << 24);
        col.c[0] = 255.0f * e[3];
        col.c[1] = 255.0f * e[4];
        col.c[2] = 255.0f * e[5];
        *D_089CC000++ = (col.w & 0xFFFFFF) | (u32)((k + 0x8F) << 24);
        i++;
    } while (i < 3);
    *D_089CC000++ = 0x5C000000;
    *D_089CC000++ = 0x17000000;
}
