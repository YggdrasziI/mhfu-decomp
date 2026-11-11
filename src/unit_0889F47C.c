/* unit_0889F47C: 0x0889F47C-0x0889F4BC (ULES01213)
 *
 * Bounds (hypothesis): one function (steps a global list cursor) between unrelated code.
 */

typedef struct Node {
    char pad0[4];
    int unk4;
    char pad8[4];
    struct Node *next;
} Node;

extern Node *D_09A0C5D0;

int func_0889F47C(void) {
    Node *n = D_09A0C5D0;

    if (n == 0) {
        return 0;
    }
    n = n->next;
    D_09A0C5D0 = n;
    if (n->next == 0) {
        D_09A0C5D0 = 0;
        return 0;
    }
    return n->unk4;
}
