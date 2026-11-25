/* unit_0885F928: 0x0885F928-0x0885F9A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

typedef struct Node Node;
struct Node {
    char pad0[0x114];
    u16 id;
    char pad116[0x144 - 0x116];
    Node *parent;
    Node *next;
    Node *child;
};

Node *func_0885F928(s32 arg0, Node *arg1, s32 arg2) {
    Node *root = arg1;

loop:
    if (arg1->id == arg2 || arg2 == -1) {
        return arg1;
    }
    if (arg1->child != 0) {
        arg1 = arg1->child;
        goto loop;
    }
    if (arg1->next != 0) {
        arg1 = arg1->next;
        goto loop;
    }
    if (arg1 != root) {
        do {
            if (arg1->next != 0) {
                arg1 = arg1->next;
                goto loop;
            }
            arg1 = arg1->parent;
        } while (arg1 != root);
    }
    return 0;
}
