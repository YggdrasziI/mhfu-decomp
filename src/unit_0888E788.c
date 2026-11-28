/* unit_0888E788: 0x0888E788-0x0888E8E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888E788: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;
extern void func_08897BD8(Vec *arg0, Vec *arg1, Vec *arg2);
extern char *func_0888E218(char *arg0);

static inline void xform(Vec *v, char *m) {
    asm {
        lv.q C100, 0(v)
        lv.q C200, 0(m)
        lv.q C210, 0x10(m)
        lv.q C220, 0x20(m)
        lv.q C230, 0x30(m)
        vcst.s S003, 0
        vtfm3.t C000, E200, C100
        vadd.t C000, C000, C230
        sv.q C000, 0(v)
    }
}

void func_0888E788(char *arg0, Vec *out, s32 *src) {
    char *g;
    char *sub;
    char *m;

    sub = arg0 + 0xA0;
    g = *(char **)(D_089CBBE4 + 0xA84);
    out->x = 0.000244140625f * (f32)src[1];
    out->y = 0.000244140625f * (f32)src[2];
    out->z = 0.000244140625f * (f32)src[3];
    switch (*(u8 *)(arg0 + 0xE9)) {
    case 2:
    {
        char *b = *(char **)(g + 0x190);
        s32 i = *(u8 *)(sub + 0x4B);

        xform(out, b + i * 0x250 + 0xD0);
        break;
    }
    case 0:
        xform(out, g + 0x10);
        break;
    case 1:
        func_08897BD8(out, out, (Vec *)(g + 0x200));
        break;
    case 3:
        m = func_0888E218(arg0);
        if (m != 0) {
            xform(out, m);
        }
        break;
    case 4:
        func_08897BD8(out, out, (Vec *)(sub + 0x20));
        break;
    case 5:
        break;
    }
}
