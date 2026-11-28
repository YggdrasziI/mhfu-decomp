/* unit_0888E8E8: 0x0888E8E8-0x0888EA44 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888E8E8: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern char *D_089CBBE4;

extern char *func_0888E218(char *);
extern void func_08897BD8(Vec *, Vec *, Vec *);

static inline void to_world(char *mtx, Vec *v) {
    asm {
        lv.q C100, 0(v)
        lv.q C200, 0(mtx)
        lv.q C210, 0x10(mtx)
        lv.q C220, 0x20(mtx)
        lv.q C230, 0x30(mtx)
        vcst.s S003, 0
        vtfm3.t C000, E200, C100
        vadd.t C000, C000, C230
        sv.q C000, 0(v)
    }
}

void func_0888E8E8(char *arg0, Vec *arg1, s32 *arg2) {
    char *pl;
    char *c;
    char *m;

    c = arg0 + 0xA0;
    pl = *(char **)(D_089CBBE4 + 0xA84);
    arg1->x = 0.000244140625f * (f32)arg2[1];
    arg1->y = 0.000244140625f * (f32)arg2[2];
    arg1->z = 0.000244140625f * (f32)arg2[3];
    switch (*(u8 *)(arg0 + 0xEA)) {
    case 2:
        m = *(char **)(pl + 0x190);
        m += *(u8 *)(c + 0x4C) * 0x250;
        to_world(m + 0xD0, arg1);
        break;
    case 0:
        to_world(pl + 0x10, arg1);
        break;
    case 1:
        func_08897BD8(arg1, arg1, (Vec *)(pl + 0x200));
        break;
    case 3:
        m = func_0888E218(arg0);
        if (m != 0) {
            to_world(m, arg1);
        }
        break;
    case 4:
        break;
    }
}
