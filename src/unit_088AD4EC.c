/* unit_088AD4EC: 0x088AD4EC-0x088AD63C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AD46C and unit_088AD63C.
 *
 * Block heap (see unit_088AD348): reallocation. The lock flag unk14 is
 * cleared around the nested allocation and release so that they do not
 * take the lock again.
 *
 * NonMatching (97.98 %): the original passes the heap to func_088AD378 without
 * loading $a0 again after func_088AD348 (it relies on the callee leaving
 * $a0 alone, see notes/COMPILER.md, "Registers kept across a call"); ours
 * reloads it.
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
extern Node *func_088AD348(Heap *, s32);
extern s32 func_088AD378(Heap *, s32);
extern void func_088AD46C(Heap *, s32);
extern int func_0880C1A8(void *, void *, s32);

s32 func_088AD4EC(Heap *h, s32 addr, s32 size) {
    Node *n;
    s32 m;
    s32 old;
    u16 lock;
    s32 r;

    r = size % h->unk0;
    if (r != 0) {
        size += h->unk0 - r;
    }
    if (addr == 0) {
        return func_088AD378(h, size);
    }
    if (size == 0) {
        func_088AD46C(h, addr);
        return 0;
    }
    func_088AD188(h);
    n = func_088AD348(h, addr);
    if (n == 0) {
        func_088AD1BC(h);
        return 0;
    }
    old = n->size;
    lock = h->unk14;
    h->unk14 = 0;
    m = func_088AD378(h, size);
    h->unk14 = lock;
    if (m == 0) {
        func_088AD1BC(h);
        return 0;
    }
    lock = h->unk14;
    h->unk14 = 0;
    func_088AD46C(h, addr);
    h->unk14 = lock;
    if (old < size) {
        func_0880C1A8((void *) m, (void *) addr, old);
    } else {
        func_0880C1A8((void *) m, (void *) addr, size);
    }
    func_088AD1BC(h);
    return m;
}
