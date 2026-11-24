/* unit_08852FA0: 0x08852FA0-0x08853004 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

u8 func_08852FA0(u8 *arg0, s32 n) {
    s32 i;
    s32 count;
    s32 m;
    s32 b;

    if ((u8)n > 62) {
        n = 62;
    }
    m = (u8)n;
    count = 1;
    for (i = 0; i < m; i++) {
        b = arg0[(i >> 3) + 0x44AC];
        if (b & (1 << (i & 7))) {
            count++;
        }
    }
    return count;
}
