/* unit_088DE014: 0x088DE014-0x088DE060 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DDFE8 and func_088DE060,
 * which is still in assembly (text_088DE060).
 *
 * Returns the index of the loaded resource of id `arg1` among entries
 * 0x15-0x2A of the resource table (unit_088DD8A8), or -1.
 *
 * Optimized for speed, as unit_088DD8A8 (loop written `i <= 42`).
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

s32 func_088DE014(Table *arg0, u16 arg1) {
    Entry *e = &arg0->e[0x15];
    s32 i;

    for (i = 0x15; i <= 42; i++, e++) {
        if (e->flags & 2) {
            if (e->id == arg1) {
                return i;
            }
        }
    }
    return -1;
}

}
