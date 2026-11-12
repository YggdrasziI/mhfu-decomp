/* unit_08880864: 0x08880864-0x08880884 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

void func_08880864(char *arg0, s32 arg1) {
    *(s32 *)((char *)arg0 + 0x5623D0) = arg1;
}

void func_08880874(char *arg0, s32 arg1) {
    *(s32 *)((char *)arg0 + 0x5623D4) = arg1;
}
