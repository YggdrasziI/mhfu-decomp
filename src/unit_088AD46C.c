/* unit_088AD46C: 0x088AD46C-0x088AD4EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AD378 (NonMatching,
 * still in assembly) and code still in assembly.
 *
 * Block heap set up by func_088AD1EC: a list of blocks from head to tail,
 * each with a size, an address and the next block. func_088AD188 /
 * func_088AD1BC take and release the heap lock.
 * Release of the block at an address.
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
