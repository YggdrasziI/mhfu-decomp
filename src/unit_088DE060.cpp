/* unit_088DE060: 0x088DE060-0x088DE0B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DE014 and unit_088DE0B8.
 *
 * Returns the index (0-3) of the loaded resource of id `arg1 + 0x17DF`
 * among entries 9-12 of the resource table (unit_088DD8A8), or -1. The
 * counter and the result are signed bytes (`seb` on the counter, which
 * lives in `$v0`).
 *
 * The id is computed inside the loop in a `u32` local and narrowed by a
 * separate `id &= 0xFFFF;` (same form as func_088DDE20, func_088DDF94 and
 * func_088DE3D4): narrowing it in the comparison or before the loop moves
 * or drops the mask.
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

s8 func_088DE060(Table *arg0, s32 arg1) {
    Entry *e;
    s8 i;
    u32 id;

    e = &arg0->e[9];
    for (i = 0; i < 4; i++, e++) {
        if (e->flags & 2) {
            id = (arg1 & 0xFF) + 0x17DF;
            id &= 0xFFFF;
            if (e->id == id) {
                return i;
            }
        }
    }
    return -1;
}

}
