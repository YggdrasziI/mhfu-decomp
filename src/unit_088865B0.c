/* unit_088865B0: 0x088865B0-0x088865D0 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
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

void func_088865B0(Table *t, int i) {
    Entry *e = &t->entries[i];

    e->a = 0;
    e->b = 0;
    e->d = 0xFFFF;
    e->c = 0;
}
