/* unit_0885F290: 0x0885F290-0x0885F354 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885F290: ORs a 4-bit value into one of three nibble tables chosen
 * by arg1 (0, 1 or 2) inside the block at D_089CC438 + 0x4A0, at nibble
 * index arg2 (ignored when not below the table size); odd indices take the
 * high nibble of the byte arg2 / 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;

void func_0885F290(s32 arg0, u8 arg1, u16 arg2, u8 arg3) {
    u8 *p = (u8 *)(D_089CC438 + 0x4A0);
    u16 n;

    switch (arg1) {
    case 0:
        p = (u8 *)(s32)(p + 0x6A598);
        n = 0x33E;
        break;
    case 1:
        p = (u8 *)(s32)(p + 0x6A14C);
        n = 0x898;
        break;
    case 2:
        p = (u8 *)(s32)(p + 0x6A737);
        n = 0xC8;
        break;
    default:
        return;
    }
    if (arg2 < n) {
        p += (u32)arg2 >> 1;
        if (arg2 & 1) {
            *p |= (u8)(arg3 << 4);
        } else {
            *p |= arg3;
        }
    }
}
