/* unit_08868678: 0x08868678-0x08868680 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

void func_08868678(s32 arg0, char *arg1) {
    *(s32 *)(arg1 + 0x1AC) = 0;
}
