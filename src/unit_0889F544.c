/* unit_0889F544: 0x0889F544-0x0889F5D8 (ULES01213) */

typedef int s32;

typedef struct Node {
    s32 pad0;
    s32 value;
    struct Node *next;
    struct Node *prev;
} Node;

extern s32 D_09A0C5EC;
extern char D_09A0C5E8[];
extern Node *D_09A0C5E4;
extern s32 D_09A0C5DC;

s32 func_0889F544(void) {
    char *list;
    Node *node;

    list = D_09A0C5E8;
    if (D_09A0C5EC == 0) {
        return 0;
    }
    node = (*(Node **)(list + 8))->prev;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    *(s32 *)(list + 4) -= 1;
    node->next = D_09A0C5E4->next;
    node->prev = D_09A0C5E4;
    node->next->prev = node;
    node->prev->next = node;
    D_09A0C5DC++;
    return node->value;
}
