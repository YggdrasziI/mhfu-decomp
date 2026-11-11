/* unit_088597FC: 0x088597FC-0x0885981C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

s32 func_088597FC(char *arg0) {
    return *(s32 *)(arg0 + 0x80198);
}

void func_0885980C(char *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x80198) = arg1;
}
