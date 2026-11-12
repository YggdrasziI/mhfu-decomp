/* unit_08872B2C: 0x08872B2C-0x08872B40 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

u16 func_08872B2C(s32 arg0, s32 arg1) {
    return ((u16 *)((char *)arg0 + 0x29C))[arg1 & 0xFF];
}
