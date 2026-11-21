/* unit_088AD2FC: 0x088AD2FC-0x088AD63C (ULES01213)
 *
 * Bounds (hypothesis): 5 functions between unit_088AD1EC and unit_088AD63C.
 * func_088AD2FC and func_088AD348 are `static` and defined before their
 * only callers (func_088AD378, func_088AD4EC): the original keeps $a3 /
 * $a0 across those calls, which the compiler does only for a static
 * function it has already compiled; with extern callees the registers are
 * saved or reloaded.
 *
 * Block heap set up by func_088AD1EC: a list of blocks from head to tail,
 * each with a size, an address and the next block. func_088AD188 /
 * func_088AD1BC take and release the heap lock.
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
extern int func_0880C1A8(void *, void *, s32);

/* First free entry (size 0) of the 0xC-byte block table. */
static Node *func_088AD2FC(Heap *arg0_) {
    char *arg0 = (char *) arg0_;
    char *temp_v1;
    char *var_a0;
    s32 temp_a1;
    s32 var_a2;

    temp_a1 = *(s32 *)(arg0 + 0x10);
    var_a2 = 0;
    if (temp_a1 > 0) {
        temp_v1 = (char *) (*(s32 **)(arg0 + 0xC));
        var_a0 = temp_v1;
loop_2:
        if (*(s32 *)var_a0 == 0) {
            return (Node *) (temp_v1 + (var_a2 * 0xC));
        }
        var_a2 += 1;
        var_a0 += 0xC;
        if (var_a2 >= temp_a1) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return 0;
}

/* Lookup of the block at an address. */
static Node *func_088AD348(Heap *h, s32 addr) {
    Node *n = h->head;

    do {
        if (n->addr == addr) {
            return n;
        }
        n = n->next;
    } while (n != h->tail);
    return 0;
}

/* Allocation in the first gap large enough, the size rounded up to the
 * granularity in unk0. */
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
        if (size <= next->addr - (n->addr + n->size)) {
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
        if (next == h->tail) {
            func_088AD1BC(h);
            return 0;
        }
        n = next;
    } while (1);
}

/* Release of the block at an address. */
void func_088AD46C(Heap *h, s32 addr) {
    Node *prev;
    Node *n;
    Node *tail;

    func_088AD188(h);
    prev = h->head;
    tail = h->tail;
    n = prev;
    for (;;) {
        if (n->next == tail) {
            func_088AD1BC(h);
            return;
        }
        n = prev->next;
        if (n->addr == addr) {
            n->size = 0;
            n->addr = 0;
            prev->next = n->next;
            n->next = 0;
            func_088AD1BC(h);
            return;
        }
        prev = n;
    }
}

/* Reallocation. The lock flag unk14 is cleared around the nested allocation
 * and release so that they do not take the lock again. */
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
