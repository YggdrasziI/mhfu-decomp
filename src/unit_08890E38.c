/* unit_08890E38: 0x08890E38-0x08890E48 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;

void func_08890E38(char *arg0, s8 arg1) {
    *(s8 *)(arg0 + 0x12E) = arg1;
}

void func_08890E40(char *arg0, s8 arg1) {
    *(s8 *)(arg0 + 0x15F) = arg1;
}
