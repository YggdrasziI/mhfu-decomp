/* unit_088DE3D4: 0x088DE3D4-0x088DE458 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DE0B8 and unit_088DE458.
 *
 * Releases (func_088DDF50) every requested or loaded entry of id
 * `arg1 + 0x17DF` among entries 9-12 of the resource table
 * (unit_088DD8A8).
 *
 * The id is computed inside the loop in a `u32` local and narrowed with a
 * compound `&= 0xFFFF`: the sum is hoisted into `$s0` and the mask stays at
 * each comparison (`andi v1, s0, 0xFFFF`), as in the original.
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

void func_088DE3D4(Table *arg0, s32 arg1) {
    Entry *e = &arg0->e[9];
    s32 i;

    for (i = 0; i < 4; i++, e++) {
        if (e->flags & 3) {
            u32 id = (arg1 & 0xFF) + 0x17DF;
            id &= 0xFFFF;
            if (e->id == id) {
                func_088DDF50(arg0, i + 9);
            }
        }
    }
}

}
