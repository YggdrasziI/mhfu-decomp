/* unit_08886664: 0x08886664-0x08886674 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_08886664(s32 arg0, s32 arg1) {
    return *(s32 *)((char *)((arg0 + (arg1 * 0x10))) + 0x30);
}
