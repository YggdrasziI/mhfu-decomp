/* unit_088B059C: 0x088B059C-0x088B05B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0554 and unit_088B05B8.
 *
 * Returns the number of entries of a peer list (linked through +0).
 */

typedef unsigned char u8;
typedef int s32;

typedef struct Entry {
    struct Entry *next;
    char unk4[0x80];
    u8 mac[6];
} Entry;

s32 func_088B059C(Entry *e) {
    s32 n;

    n = 0;
    if (e != 0) {
        do {
            e = e->next;
            n++;
        } while (e != 0);
    }
    return n;
}
