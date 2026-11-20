/* unit_088DDE20: 0x088DDE20-0x088DDF10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DD8A8 and unit_088DDF10.
 *
 * NonMatching, 96.6 %: the code stays in the assembly piece text_088DDE20.
 *
 * Copies the loaded resource of id `arg1 + 0x17DF` (searched in entries
 * 0x16-0x19) into the first free entry from `9 + n`, n being the number of
 * slots counted from D_08A62C7C (func_088DDCF4, tail call).
 *
 * Gap: the original keeps the sum `arg1 + 0x17DF` in `$v1` and masks it to
 * 16 bits after the loop set-up (`addiu a2, a0, 0x108`; `addu v0, zero,
 * zero`; `andi a1, v1, 0xFFFF`); ours masks at once from `$v0`. Tried: a
 * `u16` or `s32` local, the cast in the comparison, the local assigned
 * after the counter, in the `for` header, the search as an inline function
 * with a `u16` parameter, every declaration order.
 *
 * C++ with `#pragma exceptions off` for the tail call. Optimized for
 * speed, as unit_088DD8A8.
 */

#pragma optimize_for_size off
#pragma exceptions off

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
    u32 unk204;
    u32 unk208;
    u32 unk20C;
    u32 unk210;
    u8 unk214;
    u8 unk215;
    u8 unk216;
};

extern "C" {

extern char *D_08A62C7C;

extern void func_088DDCF4(Table *, s32, s32);

static inline s32 slot_count(void) {
    char *g = D_08A62C7C;
    s32 n = 0;

    if (*(s8 *)(g + 0x786) > 0) {
        n++;
    }
    if (*(s8 *)(g + 0x7B2) > 0) {
        if (*(s8 *)(g + 0x77C) != *(s8 *)(g + 0x7A8)) {
            n++;
        }
    }
    return n;
}

void func_088DDE20(Table *arg0, u8 arg1) {
    Entry *e;
    s32 i;
    s32 k;

    e = &arg0->e[0x16];
    for (i = 0; i < 4; i++, e++) {
        if (e->flags & 2) {
            if (e->id == (u16) (arg1 + 0x17DF)) {
                break;
            }
        }
    }
    e = &arg0->e[slot_count() + 9];
    for (k = slot_count(); k < 4; k++, e++) {
        if (!(e->flags & 3)) {
            break;
        }
    }
    func_088DDCF4(arg0, k + 9, i + 0x16);
}

}
