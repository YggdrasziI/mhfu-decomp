/* unit_088DE060: 0x088DE060-0x088DE0B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DE014 and unit_088DE0B8.
 *
 * NonMatching, 93.4 %: the code stays in the assembly piece text_088DE060.
 *
 * Returns the index (0-3) of the loaded resource of id `arg1 + 0x17DF`
 * among entries 9-12 of the resource table (unit_088DD8A8), or -1. The
 * counter and the result are signed bytes (`seb` on the counter, which
 * lives in `$v0`).
 *
 * Gap, shared with func_088DDE20, func_088DDF94 and func_088DE3D4: where
 * the id `arg1 + 0x17DF` is narrowed to 16 bits. The original narrows it
 * right before the loop, after the counter is cleared (here), or inside the
 * loop at the comparison (func_088DE3D4); ours always narrows where the sum
 * is computed. Tried: `u16`, `s32`, `u32`, `s16` locals, the cast or an
 * explicit mask in the comparison, compound assignment, inline functions
 * for the id, for the comparison and for the whole search, an `s32`
 * parameter with a `u8` cast, the operands swapped, C instead of C++, size
 * mode (worse: the loops change shape).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Entry {
    u16 flags;
    u16 id;
    s32 ptr;
    s32 unk8;
};

struct Table {
    Entry e[43];
};

extern "C" {

s8 func_088DE060(Table *arg0, u8 arg1) {
    Entry *e;
    s8 i;
    u16 id;

    id = 0x17DF;
    id += arg1;
    e = &arg0->e[9];
    for (i = 0; i < 4; i++, e++) {
        if (e->flags & 2) {
            if (e->id == id) {
                return i;
            }
        }
    }
    return -1;
}

}
