/* unit_088DAD58: 0x088DAD58-0x088DADD8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DACF8 and unit_088DADD8.
 *
 * Matching. Clears the 0x30 bytes at +0x7F8 and points +0x7F4 at the
 * 0x14-byte entry of the table at 0x089B07A0 whose key is `arg1` (the first
 * entry when none; the list after it ends with 0xFFFF). The list pointer is
 * set through an integer cast, `(Entry *) (s32) D_089B07B4`, so that it is
 * built with `lui` / `addiu` before the first test.
 *
 * Optimized for speed (loop entered without a jump to its test).
 */

#pragma optimize_for_size off

typedef unsigned short u16;
typedef int s32;

typedef struct Entry {
    u16 key;
    char pad2[0x12];
} Entry;

extern Entry D_089B07A0;
extern Entry D_089B07B4[];

extern void memset(char *, s32, s32);

void func_088DAD58(char *arg0, u16 arg1) {
    Entry *e;

    *(Entry **)(arg0 + 0x7F4) = &D_089B07A0;
    memset(arg0 + 0x7F8, 0, 0x30);
    for (e = (Entry *)(s32)D_089B07B4; e->key != 0xFFFF; e++) {
        if (e->key == arg1) {
            *(Entry **)(arg0 + 0x7F4) = e;
        }
    }
}
