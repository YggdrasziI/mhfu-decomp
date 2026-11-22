/* unit_0889F288: 0x0889F288-0x0889F42C (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef short s16;
typedef int s32;

typedef struct Node {
    s16 id;
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

extern void *func_0889F744(unsigned int i);

extern Node D_09A0C638[];
extern Node D_09A0C828;

extern s16 D_09A0C618;
extern void *D_09A0C61C;
extern Node *D_09A0C620;
extern Node *D_09A0C624;
extern s16 D_09A0C628;
extern void *D_09A0C62C;
extern Node *D_09A0C630;
extern Node *D_09A0C634;
extern s16 D_09A0C5F8;
extern void *D_09A0C5FC;
extern Node *D_09A0C600;
extern Node *D_09A0C604;
extern s16 D_09A0C608;
extern void *D_09A0C60C;
extern Node *D_09A0C610;
extern Node *D_09A0C614;
extern s32 D_09A0C5D8;
extern s32 D_09A0C5DC;
extern Node *D_09A0C5E0;
extern Node *D_09A0C5E4;
extern s32 D_09A0C5E8;
extern s32 D_09A0C5EC;
extern Node *D_09A0C5F0;
extern Node *D_09A0C5F4;

s32 func_0889F288(void) {
    s32 i;
    Node *p;

    i = 0;
    p = D_09A0C638;
    for (; i < 32; i++, p++) {
        p->id = i;
        p->prev = (i == 0) ? (Node *)&D_09A0C618 : &D_09A0C638[i - 1];
        p->next = (i == 31) ? (Node *)&D_09A0C628 : &D_09A0C638[i + 1];
        p->data = func_0889F744(i);
    }
    D_09A0C618 = -1;
    D_09A0C620 = 0;
    D_09A0C624 = D_09A0C638;
    D_09A0C61C = 0;
    D_09A0C628 = -1;
    D_09A0C630 = &D_09A0C828;
    D_09A0C634 = 0;
    D_09A0C62C = 0;
    D_09A0C5F8 = -1;
    D_09A0C600 = 0;
    D_09A0C604 = (Node *)&D_09A0C608;
    D_09A0C5FC = 0;
    D_09A0C608 = -1;
    D_09A0C610 = (Node *)&D_09A0C5F8;
    D_09A0C614 = 0;
    D_09A0C60C = 0;
    D_09A0C5E8 = 0;
    D_09A0C5EC = 32;
    D_09A0C5F0 = (Node *)&D_09A0C618;
    D_09A0C5F4 = (Node *)&D_09A0C628;
    D_09A0C5D8 = 1;
    D_09A0C5DC = 0;
    D_09A0C5E0 = (Node *)&D_09A0C5F8;
    D_09A0C5E4 = (Node *)&D_09A0C608;
    return 0;
}
