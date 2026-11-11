/* unit_0887FBC4: 0x0887FBC4-0x0887FBF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

void func_0887FBC4(s32 arg0, s32 arg1) {
    char *temp_a0;

    temp_a0 = (char *) (arg0 + (arg1 * 0x14));
    *(s32 *)(temp_a0 + 0x18) = 0;
    *(s32 *)(temp_a0 + 0x1C) = 0;
    *(s32 *)(temp_a0 + 0x20) = 0;
    *(u16 *)(temp_a0 + 0x24) = 0xFFFF;
    *(u16 *)(temp_a0 + 0x26) = 0xFFFF;
    *(u16 *)(temp_a0 + 0x28) = 0xFFFF;
    *(u16 *)(temp_a0 + 0x2A) = 0;
}
