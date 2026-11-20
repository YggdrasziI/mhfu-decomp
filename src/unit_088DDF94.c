/* unit_088DDF94: 0x088DDF94-0x088DDFE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DDF50 and unit_088DDFE8.
 *
 * Returns the address of the loaded resource of id `arg1 + 0x17DF` among
 * entries 9-12 of the resource table (unit_088DD8A8), or 0.
 *
 * NonMatching, 79.9 %: the code stays in the assembly piece text_088DDF94.
 *
 * Gap: the original sets the entry pointer first, then computes
 * `(arg1 & 0xFF) + 0x17DF`, clears the counter and only then narrows the
 * id to 16 bits; ours starts with `andi v0, a1, 0xFF` and narrows before
 * the counter. Same symptom and same list of forms tried as func_088DE060
 * (unit_088DE060); every form gives this same code.
 *
 * Optimized for speed, as unit_088DD8A8.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Entry {
    u16 flags;
    u16 id;
    s32 ptr;
    s32 unk8;
} Entry;

typedef struct Table {
    Entry e[43];
} Table;

s32 func_088DDF94(Table *arg0, u8 arg1) {
    Entry *e = &arg0->e[9];
    u16 id = arg1 + 0x17DF;
    s32 i;

    for (i = 0; i < 4; i++, e++) {
        if (e->flags & 2) {
            if (e->id == id) {
                return e->ptr;
            }
        }
    }
    return 0;
}
