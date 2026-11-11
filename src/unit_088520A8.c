/* unit_088520A8: 0x088520A8-0x088520C8 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad[0x42];
    u8 unk42;
    char rest[140 - 0x43];
} Entry; /* 140 bytes */

u8 func_088520A8(Entry *t, int i) {
    Entry *e = &t[i];

    return e->unk42;
}
