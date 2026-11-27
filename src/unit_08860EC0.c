/* unit_08860EC0: 0x08860EC0-0x08861184 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08860EC0: appends display-list words for three entries through
 * D_089CC000 (hypothesis: GE light type, position and colour commands). */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef union Color {
    u32 w;
    u8 c[4];
} Color;

typedef struct Vec {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec;

typedef struct Ent { float f[12]; } Ent;

extern char *D_089CBBE4;
extern u32 *D_089CC000;

extern void func_08860CB0(Color *out, char *arg1, char *arg2, s32 idx);

static inline void vec_transform(float *m, float *src, Vec *dst) {
    asm {
        lv.q C100, 0x0(src)
        lv.q C200, 0x0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        vmov.s S003, S103
        vtfm3.t C000, E200, C100
        sv.q C000, 0x0(dst)
    }
}

void func_08860EC0(char *arg0, char *arg1) {
    s32 i;
    Ent *e;
    float *v;
    Vec p;
    Color c;
    Color tmp;

    e = (Ent *)(arg0 + 0xB0);
    i = 0;
    do {
        v = e[i].f + 4;
        func_08860CB0(&tmp, arg0, arg1, i);
        c = tmp;
        *D_089CC000++ = (i + 0x5F) << 24;
        vec_transform((float *)(D_089CBBE4 + 0xBC0), v + 8, &p);
        *D_089CC000++ = (*(u32 *)&p.x >> 8) | ((i * 3 + 0x63) << 24);
        *D_089CC000++ = (*(u32 *)&p.y >> 8) | ((i * 3 + 0x64) << 24);
        *D_089CC000++ = (*(u32 *)&p.z >> 8) | ((i * 3 + 0x65) << 24);
        *D_089CC000++ = (c.w & 0xFFFFFF) | ((i * 3 + 0x90) << 24);
        c.c[0] = (u32)(255.0f * v[3]);
        c.c[1] = (u32)(255.0f * v[4]);
        c.c[2] = (u32)(255.0f * v[5]);
        *D_089CC000++ = (c.w & 0xFFFFFF) | ((i * 3 + 0x8F) << 24);
        i++;
    } while (i < 3);
    *D_089CC000++ = 0x17000001;
}
