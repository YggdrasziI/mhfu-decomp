/* unit_088DAD58: 0x088DAD58-0x088DADD8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DACF8 and unit_088DADD8.
 *
 * NonMatching, 88.9 %. Clears the 0x30 bytes at +0x7F8 and points +0x7F4
 * at the 0x14-byte entry of the table at 0x089B07A0 whose key is `arg1`
 * (the first entry when none; the list after it ends with 0xFFFF).
 *
 * Gaps: the original builds the list pointer with `lui` / `addiu` before
 * the first test and reads the first key through it (ours reads the symbol
 * directly, then builds the pointer), and keeps `arg1` in `$s1` and `arg0`
 * in `$s0` (ours swapped). Tried: `while` with a key local, one pointer
 * from the first entry stepped after the call, the pointer from an inline
 * function, the loop as an inline function, the pointer initialised at its
 * declaration (kept in a saved register); indexed loops give the saved
 * registers but read the key twice (82 %), an endless indexed loop with a
 * `break` builds the pointer first but tests in another order (78 %).
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

extern void func_0880C464(char *, s32, s32);

void func_088DAD58(char *arg0, u16 arg1) {
    Entry *e;

    *(Entry **)(arg0 + 0x7F4) = &D_089B07A0;
    func_0880C464(arg0 + 0x7F8, 0, 0x30);
    for (e = D_089B07B4; e->key != 0xFFFF; e++) {
        if (e->key == arg1) {
            *(Entry **)(arg0 + 0x7F4) = e;
        }
    }
}
