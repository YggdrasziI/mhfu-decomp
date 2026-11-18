/* unit_088B05B8: 0x088B05B8-0x088B0604 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B059C and unit_088B0604.
 *
 * Writes the address (+0x84) of each entry of a peer list to the 8-byte
 * slots of arg0 (func_088B0534). Returns 0.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct Entry {
    struct Entry *next;
    char unk4[0x80];
    u8 mac[6];
} Entry;

extern s32 func_088B0534(char *, u8 *);

s32 func_088B05B8(char *arg0, Entry *e) {
    if (e != 0) {
        do {
            func_088B0534(arg0, e->mac);
            e = e->next;
            arg0 += 8;
        } while (e != 0);
    }
    return 0;
}
