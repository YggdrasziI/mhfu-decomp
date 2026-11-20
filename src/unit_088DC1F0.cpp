/* unit_088DC1F0: 0x088DC1F0-0x088DC40C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DC1C8 and unit_088DC40C.
 *
 * NonMatching, 95.2 %: the code stays in the assembly piece text_088DC1F0.
 *
 * Sets up the object `arg1` from the resource of entry 8 of the table of
 * D_09A4F0D0 (parts 0-3 of func_088B89B0): copies part 1 into memory of
 * func_08866B8C (DMA copy) for func_08862510, builds the node tree of part
 * 0 (func_088DC40C, 0x250 bytes a node), passes part 2 to func_088626D0 and
 * keeps part 3 at +0x1AC.
 *
 * Gaps: the original keeps the index 8 of the lookup in `$a0` and builds
 * the offset from it (`li a0, 8`; `li v0, 0x10`; `addu v0, v0, a0`; `sll
 * s1, v0, 2`), keeps that offset in `$s1` for the second lookup and loads
 * the table pointer into `$v1` first; ours folds the offset into the two
 * loads (`lhu v0, 0x60(v1)`). The saved registers of the first part differ
 * after that. Same lookup, same registers as in func_088DB608 (`$v1` table,
 * `$a0` index). Tried for the lookup: an inline function on a stepped
 * pointer, on the table indexed twice, on an address local, a member
 * function, a `u8` index, an index local, an index from an inline
 * function (sum, conditional, `switch`), a `static const` or `static`
 * index, a volatile index, a counted loop, and two-level inlining
 * (`#pragma inline_bottom_up on`).
 *
 * Optimized for speed, as its neighbour unit_088DC40C (not checked apart).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Entry {
    u16 flags;
    char *value;
    s32 unk8;
};

struct Heap {
    char pad0[0x80000];
    char alloc[0x28];
};

struct Node {
    char pad0[0x250];
};

struct Model;

extern "C" {

extern Entry *D_09A4F0D0;
extern Heap *D_08A62C5C;

extern char *func_08859B44(void *, s32, s32);
extern void func_08862510(char *, char *, char *, s32);
extern void func_088626D0(char *, char *, char *);
extern char *func_08862710(char *);
extern s32 func_0886271C(char *);
extern s32 func_088627AC(char *);
extern s32 func_08866B8C(Heap *, s32, s32);
extern char *func_088B89B0(char *, s32);
extern s32 func_088B8A0C(char *, s32);
extern void sceKernelDcacheWritebackInvalidateAll(void);
extern s32 sceDmacMemcpy(s32, char *, s32);
extern s32 func_088DC40C(Model *, Node *, char *, float, float, float);

static inline char *entry_value(Entry *tbl, s32 i) {
    s32 n = i;

    if (tbl[n].flags & 2) {
        return tbl[n].value;
    }
    return 0;
}

void func_088DC1F0(s32 arg0, char *arg1) {
    char *res;
    char *res2;
    char *r;
    char *r2;
    char *buf;
    s32 size;
    s32 dst;
    s32 n;
    s32 cnt;

    res = entry_value(D_09A4F0D0, 8);
    r = func_088B89B0(res, 1);
    n = *(u16 *)(r + 0x1C);
    size = func_088627AC(r) * 16;
    buf = func_08859B44(D_08A62C5C->alloc, size + n * 8, 0x10);
    res2 = entry_value(D_09A4F0D0, 8);
    func_088B8A0C(res2, 1);
    r2 = func_088B89B0(res2, 1);
    dst = func_08866B8C(D_08A62C5C, 1, 0);
    size = func_0886271C(r2);
    sceKernelDcacheWritebackInvalidateAll();
    sceDmacMemcpy(dst, func_08862710(r2), size);
    func_08862510(arg1, buf, r, dst);

    r = func_088B89B0(res, 0);
    cnt = *(s32 *)(r + 4);
    if (*(s32 *) r & 0x80000000) {
        cnt--;
    }
    func_088DC40C((Model *)(arg1 + 0x80), (Node *) func_08859B44(D_08A62C5C->alloc, cnt * 0x250, 0x10), r,
                  *(float *)(arg1 + 0x60), *(float *)(arg1 + 0x64), *(float *)(arg1 + 0x68));

    r = func_088B89B0(res, 2);
    func_088626D0(arg1, func_08859B44(D_08A62C5C->alloc, *(s32 *)(r + 8) << 5, 0x10), r);
    *(char **)(arg1 + 0x1AC) = func_088B89B0(res, 3);
}

}
