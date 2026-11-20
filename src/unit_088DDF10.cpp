/* unit_088DDF10: 0x088DDF10-0x088DDF50 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088DDE20, still in assembly
 * (text_088DDE20), and unit_088DDF50.
 *
 * Tells whether entry `arg1` of the resource table (unit_088DD8A8) is
 * requested and not loaded yet.
 *
 * C++: bool conversion.
 */

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

s32 func_088DDF10(Table *arg0, s32 arg1) {
    u16 f = arg0->e[arg1].flags;
    s32 r = 0;

    if (f & 1) {
        if ((bool) (f & 2) ^ 1) {
            r = 1;
        }
    }
    return r;
}

}
