/* unit_088AD378: 0x088AD378-0x088AD46C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AD348 and unit_088AD46C.
 *
 * Block heap set up by func_088AD1EC: a list of blocks from head to tail,
 * each with a size, an address and the next block. func_088AD188 /
 * func_088AD1BC take and release the heap lock.
 * Allocation in the first gap large enough, the size rounded up to the
 * granularity in unk0.
 *
 * NonMatching (92.87 %): the original keeps the current block in $a3 across
 * the call to func_088AD2FC (it relies on the callee leaving $a3 alone, see
 * notes/COMPILER.md, "Registers kept across a call"); ours keeps it in a
 * saved register, hence a larger frame and shifted registers. The rest of
 * the code is the same.
 */

typedef unsigned short u16;
typedef int s32;

typedef struct Node {
    s32 size;
    s32 addr;
    struct Node *next;
} Node;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    Node *nodes;
    s32 count;
    u16 unk14;
    Node *head;
    Node *tail;
} Heap;

extern void func_088AD188(Heap *);
extern void func_088AD1BC(Heap *);
extern Node *func_088AD2FC(Heap *);

s32 func_088AD378(Heap *h, s32 size) {
    Node *n;
    Node *next;
    Node *m;
    s32 r;

    if (size == 0) {
        return 0;
    }
    r = size % h->unk0;
    if (r != 0) {
        size += h->unk0 - r;
    }
    func_088AD188(h);
    n = h->head;
    do {
        next = n->next;
        if (next->addr - (n->addr + n->size) >= size) {
            m = func_088AD2FC(h);
            if (m == 0) {
                func_088AD1BC(h);
                return 0;
            }
            m->size = size;
            m->addr = n->addr + n->size;
            m->next = n->next;
            n->next = m;
            func_088AD1BC(h);
            return m->addr;
        }
        n = next;
    } while (next != h->tail);
    func_088AD1BC(h);
    return 0;
}
