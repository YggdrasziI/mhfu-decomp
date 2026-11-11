/* unit_0887FF24: 0x0887FF24-0x0887FF74 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

s32 func_0887FF24(s32 arg0, s32 arg1) {
    char *temp_a0;
    char *temp_v0;

    temp_v0 = (char *) (arg0 + (arg1 * 0x14));
    temp_a0 = temp_v0 + 0x18;
    if ((*(u16 *)(temp_v0 + 0x24) != 0xFFFF) && (*(u16 *)(temp_a0 + 0xE) != 0xFFFF) && (*(u16 *)(temp_a0 + 0x10) != 0xFFFF)) {
        return 1;
    }
    return 0;
}
