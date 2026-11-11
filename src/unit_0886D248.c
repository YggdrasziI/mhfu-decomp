/* unit_0886D248: 0x0886D248-0x0886D26C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

extern char D_08A62C9C;

void func_0886D248(char *arg0, s8 arg1) {
    *(&D_08A62C9C + *(s8 *)(arg0 + 0x21)) = arg1;
    *(s8 *)(arg0 + 0x21) = (s8) (*(s8 *)(arg0 + 0x21) + 1);
}
