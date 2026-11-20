/* unit_088DE3D4: 0x088DE3D4-0x088DE458 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DE0B8 and unit_088DE458.
 *
 * NonMatching, 96.5 %: the code stays in the assembly piece text_088DE3D4.
 *
 * Releases (func_088DDF50) every requested or loaded entry of id
 * `arg1 + 0x17DF` among entries 9-12 of the resource table
 * (unit_088DD8A8).
 *
 * Gap: the original keeps the sum `arg1 + 0x17DF` in `$s0` and narrows it
 * to 16 bits inside the loop, at each comparison (`andi v1, s0, 0xFFFF`).
 * This form (an `s32` parameter masked by hand) lets the compiler drop the
 * narrowing; every form with a `u8` parameter narrows once before the
 * loop (87.3 %). Same symptom and same list of forms tried as
 * func_088DE060.
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
            if (e->id == (((arg1 & 0xFF) + 0x17DF) & 0xFFFF)) {
                func_088DDF50(arg0, i + 9);
            }
        }
    }
}

}
