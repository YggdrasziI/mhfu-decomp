/* unit_0885FC9C: 0x0885FC9C-0x0885FE44 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct Node {
    char pad0[0x114];
    u16 id;
    char pad116[0x144 - 0x116];
    struct Node *parent;
    struct Node *next;
    struct Node *child;
    char a[0x40];
    f32 pa[3];
    char pad19C[0x80 - 0x4C];
    char b[0x40];
    f32 pb[3];
} Node;

extern void func_0885FE44(char *m, f32 *x, f32 *y);

static inline void blend(char *m1, char *m0, f32 *o1, f32 *o0, f32 s, f32 t) {
    f32 *ps = &s;
    f32 *pt = &t;
    asm {
        lv.q C100, 0x0(m0)
        lv.q C110, 0x10(m0)
        lv.q C120, 0x20(m0)
        lv.q C130, 0x30(m0)
        lv.q C200, 0x0(m1)
        lv.q C210, 0x10(m1)
        lv.q C220, 0x20(m1)
        lv.q C230, 0x30(m1)
        lv.s S300, 0x0(ps)
        lv.s S301, 0x0(pt)
        vscl.t C310, C100, S300
        vscl.t C320, C200, S301
        vadd.t C000, C310, C320
        nop
        vscl.t C310, C110, S300
        vscl.t C320, C210, S301
        vadd.t C010, C310, C320
        vmidt.q E400
        vscl.t C310, C130, S300
        vscl.t C320, C230, S301
        vadd.t C430, C310, C320
        sv.q C000, 0x0(o0)
        sv.q C010, 0x0(o1)
        sv.q C400, 0x0(m0)
        sv.q C410, 0x10(m0)
        sv.q C420, 0x20(m0)
        sv.q C430, 0x30(m0)
    }
}

void func_0885FC9C(Node *root, f32 s, f32 t, s32 id) {
    Node *n;
    Node *q;
    f32 y[4] __attribute__((aligned(16)));
    f32 x[4] __attribute__((aligned(16)));

    n = root;
top:
    if (n->id == id || id == -1) {
        n->pa[0] = n->pa[0] * s + n->pb[0] * t;
        n->pa[1] = n->pa[1] * s + n->pb[1] * t;
        n->pa[2] = n->pa[2] * s + n->pb[2] * t;
        blend(n->b, n->a, y, x, s, t);
        func_0885FE44(n->a, x, y);
        if (n->child != 0) {
            n = n->child;
            goto top;
        }
    }
    if (n->next != 0 && n != root) {
        n = n->next;
        goto top;
    }
    while (n != root) {
        q = n->next;
        if (q != 0) {
            do {
                n = q;
                if (q->id == id || id == -1) {
                    goto top;
                }
                q = q->next;
            } while (q != 0);
        }
        n = n->parent;
    }
}
