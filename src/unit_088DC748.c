/* unit_088DC748: 0x088DC748-0x088DC774 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

s32 func_088DC748(char *arg0) {
    s32 var_v0;

    var_v0 = *(s32 *)(arg0 + 4);
    if (*(s32 *)arg0 & 0x80000000) {
        var_v0 -= 1;
    }
    return var_v0;
}

void func_088DC76C(void) {
}
