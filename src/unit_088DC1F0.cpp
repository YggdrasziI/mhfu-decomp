/* unit_088DC1F0: 0x088DC1F0-0x088DC40C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DC1C8 and unit_088DC40C.
 *
 * Sets up the object `arg1` from the resource of entry 8 of the table of
 * D_09A4F0D0 (parts 0-3 of func_088B89B0): copies part 1 into memory of
 * func_08866B8C (DMA copy) for func_08862510, builds the node tree of part
 * 0 (func_088DC40C, 0x250 bytes a node), passes part 2 to func_088626D0 and
 * keeps part 3 at +0x1AC.
 *
 * The lookup of entry 8 (`li a0, 8`; `li v0, 0x10`; `addu v0, v0, a0`;
 * `sll s1, v0, 2`, offset kept in `$s1` for the second lookup) comes from
 * `#pragma opt_propagation off`, an index local `idx = 8` shared by both
 * lookups and an inline helper without a copy of its index. The saved
 * registers come from the locals shared across roles (all `s32`) and their
 * declaration order: `part` (first part-1 pointer, `$s4`) declared before
 * `part2` (second part-1 pointer, `$s3`).
 *
 * Optimized for speed, as its neighbour unit_088DC40C (not checked apart).
 */

#pragma optimize_for_size off
#pragma opt_propagation off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Entry {
    u16 flags;
    s32 value;
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

extern s32 func_08859B44(void *, s32, s32);
extern void func_08862510(char *, s32, s32, s32);
extern void func_088626D0(char *, s32, s32);
extern s32 func_08862710(s32);
extern s32 func_0886271C(s32);
extern s32 func_088627AC(s32);
extern s32 func_08866B8C(Heap *, s32, s32);
extern s32 func_088B89B0(s32, s32);
extern s32 func_088B8A0C(s32, s32);
extern void sceKernelDcacheWritebackInvalidateAll(void);
extern s32 sceDmacMemcpy(s32, s32, s32);
extern s32 func_088DC40C(Model *, Node *, s32, float, float, float);

static inline s32 entry_value(Entry *tbl, s32 i) {
    if (tbl[i].flags & 2) {
        return tbl[i].value;
    }
    return 0;
}

void func_088DC1F0(s32 arg0, char *arg1) {
    s32 part;
    s32 part2;
    s32 dst;
    s32 res2;
    s32 size;
    s32 n;
    s32 idx = 8;
    s32 size2;
    s32 res;

    res = entry_value(D_09A4F0D0, idx);
    part = func_088B89B0(res, 1);
    n = *(u16 *)(part + 0x1C);
    size = func_088627AC(part) * 16;
    n = func_08859B44(D_08A62C5C->alloc, size + n * 8, 0x10);
    res2 = entry_value(D_09A4F0D0, idx);
    func_088B8A0C(res2, 1);
    part2 = func_088B89B0(res2, 1);
    dst = func_08866B8C(D_08A62C5C, 1, 0);
    size2 = func_0886271C(part2);
    sceKernelDcacheWritebackInvalidateAll();
    sceDmacMemcpy(dst, func_08862710(part2), size2);
    func_08862510(arg1, n, part, dst);

    part2 = func_088B89B0(res, 0);
    n = *(s32 *)(part2 + 4);
    if (*(s32 *) part2 & 0x80000000) {
        n--;
    }
    func_088DC40C((Model *)(arg1 + 0x80), (Node *) func_08859B44(D_08A62C5C->alloc, n * 0x250, 0x10), part2,
                  *(float *)(arg1 + 0x60), *(float *)(arg1 + 0x64), *(float *)(arg1 + 0x68));

    part = func_088B89B0(res, 2);
    func_088626D0(arg1, func_08859B44(D_08A62C5C->alloc, *(s32 *)(part + 8) << 5, 0x10), part);
    *(s32 *)(arg1 + 0x1AC) = func_088B89B0(res, 3);
}

}
