/* unit_08886618: 0x08886618-0x08886638 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code (same table as unit_088865B0).
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
    u16 d;
    char pad[2];
} Entry; /* 16 bytes */

typedef struct {
    char pad[0x30];
    Entry entries[1];
} Table;

void func_08886618(Table *t, int i, int a, int b) {
    Entry *e = &t->entries[i];

    e->a = a;
    e->b = b;
    e->d = 0xFFFF;
    e->c = 0;
}
