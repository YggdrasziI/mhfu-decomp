/* unit_0884FF24: 0x0884FF24-0x0884FF4C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

u16 func_0884FF24(s32 arg0, s32 arg1) {
    return ((u16 *)((char *)arg0 + 0x46E8))[arg1 & 0xFF];
}

u16 func_0884FF38(s32 arg0, s32 arg1) {
    return ((u16 *)((char *)arg0 + 0x44CC))[arg1 & 0xFF];
}
