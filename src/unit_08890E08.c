/* unit_08890E08: 0x08890E08-0x08890E38 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;

void func_08890E08(void *arg0, s8 arg1) {
    if (arg1 < 0) {
        arg1 = 0;
    }
    if (arg1 >= 6) {
        arg1 = 5;
    }
    *((s8 *)arg0 + 0x12F) = arg1;
}
