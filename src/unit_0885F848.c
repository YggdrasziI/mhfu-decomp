/* unit_0885F848: 0x0885F848-0x0885F8E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885F848: walks the node tree under arg1 (child at 0x14C, next
 * sibling at 0x148, parent at 0x144) in pre-order; every node whose u16 at
 * 0x114 equals arg3 (or all when arg3 is -1) gets the current record of
 * arg2 stored at 0x1B4 (or 0x234 when arg4 is set), then the record pointer
 * advances by the record's size word at +8. */

typedef unsigned short u16;
typedef int s32;

typedef struct Node {
    char pad0[0x114];
    u16 id;
    char pad116[0x144 - 0x116];
    struct Node *parent;
    struct Node *next;
    struct Node *child;
    char pad150[0x80];
    char a[0x80];
    char b[0x80];
} Node;

void func_0885F848(s32 arg0, Node *n, char *arg2, s32 arg3, s32 arg4) {
    Node *root;
    char *p;
    Node *s;
    char *q;

    p = arg2 + 0x14;
    root = n;
top:
    if (n->id == arg3 || arg3 == -1) {
        if (arg4 == 0) {
            q = (char *)n + 0x150;
        } else {
            q = (char *)n + 0x1D0;
        }
        *(char **)(q + 0x64) = p;
        p += *(s32 *)(p + 8);
        if (n->child != 0) {
            n = n->child;
            goto top;
        }
    }
    if (n->next != 0 && n != root) {
        n = n->next;
        goto top;
    }
    while (n != root) {
        s = n->next;
        if (s != 0) {
            do {
                n = s;
                if (s->id == arg3 || arg3 == -1) {
                    goto top;
                }
                s = s->next;
            } while (s != 0);
        }
        n = n->parent;
    }
}
