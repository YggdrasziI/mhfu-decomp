/* unit_088AD0D4: 0x088AD0D4-0x088AD0F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_088AD0D4(s32 arg0) {
    u32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    return (((temp_a0 << 8) & 0xFF00) | ((temp_a0 >> 8) & 0xFF)) & 0xFFFF;
}
