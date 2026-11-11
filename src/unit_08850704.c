/* unit_08850704: 0x08850704-0x08850724 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    char pad[11];
} Entry;

typedef struct {
    char pad[0x548];
    Entry entries[1];
} Table;

int func_08850704(Table *t, int i) {
    return t->entries[i].unk0 == 0;
}
