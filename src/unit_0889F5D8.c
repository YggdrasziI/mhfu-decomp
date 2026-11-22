/* unit_0889F5D8: 0x0889F5D8-0x0889F6A0 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;

typedef struct Node {
    s32 unk0;
    s32 id;
    struct Node *prev;
    struct Node *next;
} Node;

extern s32 D_09A0C5DC;
extern Node *D_09A0C5E0;
extern s32 D_09A0C5EC;
extern Node *D_09A0C5F4;

s32 func_0889F5D8(s32 arg0) {
    Node *node;
    Node *next;

    if (D_09A0C5DC == 0) {
        return 0x8000001C;
    }
    node = D_09A0C5E0->next;
    for (next = node->next; next != 0; next = next->next) {
        if (node->id == arg0) {
            node->prev->next = next;
            node->next->prev = node->prev;
            D_09A0C5DC--;
            node->prev = D_09A0C5F4->prev;
            node->next = D_09A0C5F4;
            node->prev->next = node;
            node->next->prev = node;
            D_09A0C5EC++;
            return 0;
        }
        node = next;
    }
    return 0x8000001C;
}
