/* unit_08872E2C: 0x08872E2C-0x08872E48 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

s32 func_08872E2C(s32 arg0, s32 arg1) {
    return ((u32) (*(u8 *)((char *)((arg0 + arg1)) + 0x75C) << 0x18) >> 0x1F) == 1;
}
