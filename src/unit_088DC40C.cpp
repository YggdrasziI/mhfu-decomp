/* unit_088DC40C: 0x088DC40C-0x088DC6E8 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between func_088DC1F0, still in assembly
 * (text_088DC1F0), and unit_088DC6E8.
 *
 * func_088DC40C builds a tree of `n` 0x250-byte nodes in `arg1` from the
 * data `arg2`: constructs the nodes, links each to the nodes of its three
 * indices (-1: none), records the root nodes at +0x110 and their count at
 * +0x120, the depth at +0x122, then applies the identity matrix scaled by
 * 1 / (arg3, arg4, arg5) to the roots. func_088DC6D0 writes an identity
 * matrix (VFPU).
 *
 * Optimized for speed (float constant as an immediate, stepped pointers).
 * The first loop multiplies by the unsigned `sizeof` (not strength
 * reduced); the last loop has its own counter.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Header {
    s32 unk0;
    u32 count;
    s32 unk8;
    s32 index[1];
};

struct Block {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad1C[0x34];
    u32 unk50;
};

struct Node {
    char pad0[0x250];
};

struct Model {
    char pad0[0x110];
    Node *node[4];
    u16 count;
    u16 unk122;
    s32 total;
};

extern "C" {

extern char *func_08860758(s32, Node *);
extern void func_0886005C(Node *, Block *);
extern void func_0886053C(Node *, float *);
extern void func_088640F8(Model *, char *, float, float, float);
extern void func_088641C0(Model *);
extern void func_088642FC(Model *);
extern Block *func_088DC6E8(Node *, Block *);
extern void func_088DC6F4(Node *, Node *);
extern void func_088DC6FC(Node *, Node *);
extern void func_088DC704(Node *, Node *);
extern Block *func_088DC70C(Node *, Header *);
extern Header *func_088DC718(Node *, char *);
extern char *func_088DC720(char *);
extern s32 func_088DC748(char *);

void func_088DC6D0(float *m);

s32 func_088DC40C(Model *arg0, Node *arg1, char *arg2, float arg3, float arg4, float arg5) {
    float mtx[16];
    s32 i;
    char *p;
    Block *blk;
    Header *hdr;
    s32 k;
    s32 n;
    s32 *idx;
    u32 j;
    s32 m;

    if (arg0 != 0) {
        func_088642FC(arg0);
        n = func_088DC748(arg2);
        arg0->total = n;
        for (i = 0; i < n; i++) {
            p = func_08860758(sizeof(Node), (Node *)((char *) arg1 + i * sizeof(Node)));
            if (p != 0) {
                func_088DC720(p);
            }
        }
        hdr = func_088DC718(arg1, arg2);
        blk = func_088DC70C(arg1, hdr);
        arg0->unk122 = 0;
        for (k = 0; k < n; k++) {
            func_0886005C(&arg1[k], blk);
            if (blk->unk10 != -1) {
                func_088DC704(&arg1[k], &arg1[blk->unk10]);
            }
            if (blk->unk14 != -1) {
                func_088DC6FC(&arg1[k], &arg1[blk->unk14]);
            }
            if (blk->unk18 != -1) {
                func_088DC6F4(&arg1[k], &arg1[blk->unk18]);
            }
            if (arg0->unk122 <= blk->unk50) {
                arg0->unk122 = blk->unk50 + 1;
            }
            blk = func_088DC6E8(&arg1[k], blk);
        }
        idx = hdr->index;
        for (j = 0; j < hdr->count; j++) {
            arg0->node[j] = &arg1[idx[j]];
        }
        arg0->count = hdr->count;
        func_088DC6D0(mtx);
        mtx[0] /= arg3;
        mtx[5] /= arg4;
        mtx[10] /= arg5;
        for (m = 0; m < arg0->count; m++) {
            func_0886053C(arg0->node[m], mtx);
        }
        func_088640F8(arg0, 0, 1.0f, 1.0f, 1.0f);
        func_088641C0(arg0);
        return 1;
    }
    return 0;
}

void func_088DC6D0(float *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

}
