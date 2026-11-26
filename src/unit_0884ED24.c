/* unit_0884ED24: 0x0884ED24-0x0884ED94 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_0884ED24: lookup of a 16-bit key in a table of 0x32D pairs,
 * falling back to the difference of two consecutive offsets. */

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 key;
    s32 val;
} Pair;

typedef struct {
    char pad[0x1140];
    Pair pairs[0x32D];
    char pad2[0x2AC0 - 0x1140 - 0x32D * 8];
    s32 offs[1];
} Tbl;

s32 func_0884ED24(Tbl *arg0, s32 arg1) {
    s32 i;
    u32 k = (u16)arg1;

    if (k == 0xFFFF) {
        return 0;
    }
    for (i = 0; i < 0x32D; i++) {
        if (k == arg0->pairs[i].key) {
            return arg0->pairs[i].val;
        }
    }
    return (arg0->offs[k + 1] - arg0->offs[arg1 & 0xFFFF]) << 11;
}
