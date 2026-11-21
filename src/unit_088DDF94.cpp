/* unit_088DDF94: 0x088DDF94-0x088DDFE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DDF50 and unit_088DDFE8.
 *
 * Returns the address of the loaded resource of id `arg1 + 0x17DF` among
 * entries 9-12 of the resource table (unit_088DD8A8), or 0.
 *
 * The id is computed inside the loop in a `u32` local and narrowed by a
 * separate `id &= 0xFFFF;`, as in func_088DE060 (C++ for the same code as
 * that unit).
 *
 * Optimized for speed, as unit_088DD8A8.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
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

s32 func_088DDF94(Table *arg0, s32 arg1) {
    Entry *e;
    s32 i;
    u32 id;

    e = &arg0->e[9];
    for (i = 0; i < 4; i++, e++) {
        if (e->flags & 2) {
            id = (arg1 & 0xFF) + 0x17DF;
            id &= 0xFFFF;
            if (e->id == id) {
                return e->ptr;
            }
        }
    }
    return 0;
}

}
