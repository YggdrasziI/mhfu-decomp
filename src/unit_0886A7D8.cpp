/* unit_0886A7D8: 0x0886A7D8-0x0886A87C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A7D8: returns false if, for any other active slot i (not self),
 * bit i of the selected flag byte of entry arg1 is clear. */

typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern char *D_089CC438;

static inline bool func_active(char *g, u8 i) {
    return *(u8 *)(g + i * 0x8C + 0x30) != 0;
}

extern "C" bool func_0886A7D8(char *arg0, s32 arg1) {
    u8 idx;
    bool ret;
    char *g;
    s32 i;
    u8 *e;
    s8 *sel;
    u8 self;
    idx = arg1;
    ret = true;
    g = D_089CC438;
    self = *(u8 *)(g + 0x28);
    i = 0;
    e = (u8 *)arg0 + idx * 0x2C;
    sel = (s8 *)(e + 0x787);
    for (; i < 4; i++) {
        if (self == i) {
            continue;
        }
        if (func_active(g, i) != 0) {
            if (!((e + 0x788)[*sel] & (1 << i))) {
                ret = false;
            }
        }
    }
    return ret;
}
