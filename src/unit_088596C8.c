/* unit_088596C8: 0x088596C8-0x08859728 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088596C8: patches a GE display list (hypothesis): copies the two
 * words at the current pointer of list a3 to the slot before a2, then
 * writes a BASE (0x10) and JUMP (0x08) command pair aimed at a1. */
typedef int s32;
typedef unsigned int u32;

s32 func_088596C8(char *arg0, u32 *arg1, s32 arg2, s32 arg3) {
    u32 *p = *(u32 **)((char *)(arg3 * 4) + (s32)arg0 + 0x148);
    u32 *q = arg1 + (arg2 - 2);

    q[0] = p[0];
    q[1] = p[1];
    p[0] = (((u32)arg1 & 0xFF000000) >> 8) | 0x10000000;
    p[1] = (((u32)arg1 << 8) >> 8) | 0x08000000;
    *(u32 **)((char *)(arg3 * 4) + (s32)arg0 + 0x148) = q;
    return 1;
}
