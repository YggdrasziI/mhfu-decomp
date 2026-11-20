/* unit_088DE458: 0x088DE458-0x088DE4BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088DE3D4, still in assembly
 * (text_088DE3D4), and unit_088DE4BC.
 *
 * Releases (func_088DDF50) every requested or loaded entry among entries
 * 9-12 of the resource table (unit_088DD8A8).
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

extern void func_088DDF50(Table *, s32);

void func_088DE458(Table *arg0) {
    Entry *e = &arg0->e[9];
    s32 i;

    for (i = 0; i < 4; i++, e++) {
        if (e->flags & 3) {
            func_088DDF50(arg0, i + 9);
        }
    }
}

}
