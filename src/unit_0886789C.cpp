/* unit_0886789C: 0x0886789C-0x08867B34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * func_0886789C: same shape as func_088DC40C (unit_088DC40C.cpp): builds
 * `n` 0x250-byte nodes in arg2, links them by the indices of each block,
 * records the root nodes and applies an identity matrix scaled by
 * 1 / (arg3, arg4, arg5) (VFPU asm block). Optimized for speed. The count
 * stored after the root loop is read as `s32` so that it is reloaded.
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
    char pad0[0x8];
    s32 size;
    char pad0C[0x4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    char pad1C[0x34];
    u32 unk50;
};

struct Node {
    char pad0[0x144];
    Node *unk144;
    Node *unk148;
    Node *unk14C;
    char pad150[0x100];
};

struct Model {
    char pad0[0x110];
    Node *node[4];
    u16 count;
    u16 unk122;
    s32 total;
};

struct File {
    u32 flags;
    s32 count;
    s32 unk8;
    Header hdr;
};

extern "C" {

extern char *func_08860758(s32, Node *);
extern void func_0886005C(Node *, Block *);
extern void func_0886053C(Node *, float *);
extern char D_089BAB08;

static inline void mtx_identity(float *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

void func_0886789C(Model *arg0, File *arg1, Node *arg2, float arg3, float arg4, float arg5) {
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

    n = arg1->count;
    if (arg1->flags & 0x80000000) {
        n--;
    }
    arg0->total = n;
    for (i = 0; i < n; i++) {
        p = func_08860758(sizeof(Node), (Node *)((char *) arg2 + i * sizeof(Node)));
        if (p != 0) {
            *(char **)p = &D_089BAB08;
            *(s32 *)(p + 0x1B4) = 0;
            *(s32 *)(p + 0x234) = 0;
            *(s32 *)(p + 0x14C) = 0;
            *(s32 *)(p + 0x148) = 0;
            *(s32 *)(p + 0x144) = 0;
        }
    }
    hdr = &arg1->hdr;
    blk = (Block *)((char *)hdr + hdr->unk8);
    arg0->unk122 = 0;
    for (k = 0; k < n; k++) {
        func_0886005C(&arg2[k], blk);
        if (blk->unk10 != -1) {
            arg2[k].unk144 = &arg2[blk->unk10];
        }
        if (blk->unk14 != -1) {
            arg2[k].unk14C = &arg2[blk->unk14];
        }
        if (blk->unk18 != -1) {
            arg2[k].unk148 = &arg2[blk->unk18];
        }
        if (arg0->unk122 <= blk->unk50) {
            arg0->unk122 = blk->unk50 + 1;
        }
        blk = (Block *)((char *)blk + blk->size);
    }
    idx = hdr->index;
    for (j = 0; j < hdr->count; j++) {
        arg0->node[j] = &arg2[idx[j]];
    }
    arg0->count = *(s32 *)&hdr->count;
    mtx_identity(mtx);
    mtx[0] /= arg3;
    mtx[5] /= arg4;
    mtx[10] /= arg5;
    for (m = 0; m < arg0->count; m++) {
        func_0886053C(arg0->node[m], mtx);
    }
}

}
