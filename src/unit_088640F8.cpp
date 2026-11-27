/* unit_088640F8: 0x088640F8-0x088641C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct Mtx {
    float m[16];
} __attribute__((aligned(16))) Mtx;

struct Node {
    virtual void vfunc_08();
    virtual void vfunc_0C(Mtx *a, Mtx *b, f32 x, f32 y, f32 z);
};

struct Owner {
    char pad[0x110];
    Node *child[4];
    u16 count;
};

extern "C" {

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

void func_088640F8(Owner *arg0, Mtx *arg1, f32 x, f32 y, f32 z) {
    Mtx tmp;
    s32 i;

    mtx_identity(&tmp);
    if (arg1 == 0) {
        arg1 = &tmp;
    }
    for (i = 0; i < arg0->count; i++) {
        arg0->child[i]->vfunc_0C(arg1, &tmp, x, y, z);
    }
}

}
