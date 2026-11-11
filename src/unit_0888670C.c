/* unit_0888670C: 0x0888670C-0x08886734 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

u16 func_0888670C(s32 arg0, s32 arg1) {
    return *(u16 *)((char *)((arg0 + (arg1 * 0x10))) + 0x3C);
}

s32 func_0888671C(s32 arg0, s32 arg1) {
    return *(s32 *)((char *)((arg0 + (arg1 * 0x18))) + 8);
}
