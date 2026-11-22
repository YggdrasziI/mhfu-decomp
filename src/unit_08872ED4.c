/* unit_08872ED4: 0x08872ED4-0x08872F0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef int s32;

s32 func_08872ED4(s32 arg0, s32 arg1) {
    s32 i;
    s32 v;

    for (i = 0; i < 6; i++) {
        v = *(u8 *)((char *)(arg0 + i) + 0x75C) & 0x7F;
        if (v == arg1) {
            return i;
        }
    }
    return -1;
}
