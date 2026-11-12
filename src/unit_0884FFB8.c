/* unit_0884FFB8: 0x0884FFB8-0x0884FFE0 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

u16 func_0884FFB8(s32 arg0, s32 arg1) {
    return ((u16 *)((char *)arg0 + 0x4580))[arg1 & 0xFFFF];
}

u16 func_0884FFCC(s32 arg0, s32 arg1) {
    return ((u16 *)((char *)arg0 + 0x4634))[arg1 & 0xFFFF];
}
