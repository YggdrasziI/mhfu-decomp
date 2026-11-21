/* unit_089015F8: 0x089015F8-0x08901664 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Counts, over the 31 eight-byte entries at +0x678A8 of D_089CC438, the
 * used ones (13-bit count not zero) whose 2-bit kind is 1 or 2.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 b0 : 1;
    u8 kind : 2;
    u8 b3 : 5;
    u8 pad1;
    u16 id;
    u8 pad4[4];
} Entry;

extern char *D_089CC438;

s8 func_089015F8(char *arg0) {
    Entry *p;
    s32 i;
    s8 count;

    p = (Entry *)(D_089CC438 + 0x678A8);
    count = 0;

    for (i = 0; i < 31; i++) {
        if ((p->id & 0x3FFF) == 0) {
            continue;
        }
        if ((u32)(p->kind - 1) < 2) {
            count++;
        }
        p++;
    }
    return count;
}
