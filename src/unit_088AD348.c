/* unit_088AD348: 0x088AD348-0x088AD378 (ULES01213)
 *
 * Bounds (hypothesis): first function of the old asm piece text_088AD348,
 * after unit_088AD2FC.
 *
 * Block heap set up by func_088AD1EC: a list of blocks from head to tail,
 * each with a size, an address and the next block. func_088AD188 /
 * func_088AD1BC take and release the heap lock.
 * Lookup of the block at an address.
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

Node *func_088AD348(Heap *h, s32 addr) {
    Node *n = h->head;

    do {
        if (n->addr == addr) {
            return n;
        }
        n = n->next;
    } while (n != h->tail);
    return 0;
}
