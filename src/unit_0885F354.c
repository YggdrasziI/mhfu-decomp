/* unit_0885F354: 0x0885F354-0x0885F434 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885F354: tests a 4-bit flag nibble in one of three tables at
 * D_089CC438 + 0x4A0 + {0x6A598, 0x6A14C, 0x6A737} (selected by kind 0/1/2,
 * sizes 0x33E/0x898/0xC8 entries); entry idx lives in byte idx >> 1, odd
 * entries in the high nibble. Returns 1 when (nibble & mask) != 0, else 0.
 * The two inner tests must share one `return 0` after the if/else.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;

s32 func_0885F354(s32 arg0, u8 kind, u16 idx, u8 mask) {
    char *base = D_089CC438 + 0x4A0;
    u8 *tbl;
    u16 n;

    switch (kind) {
    case 0:
        tbl = (u8 *)(base + 0x6A598);
        n = 0x33E;
        break;
    case 1:
        tbl = (u8 *)(base + 0x6A14C);
        n = 0x898;
        break;
    case 2:
        tbl = (u8 *)(base + 0x6A737);
        n = 0xC8;
        break;
    default:
        return 0;
    }
    if (idx >= n) {
        return 0;
    }
    tbl += (u32)idx >> 1;
    if (idx & 1) {
        if (*tbl & (mask << 4)) {
            return 1;
        }
    } else {
        if (*tbl & mask) {
            return 1;
        }
    }
    return 0;
}
