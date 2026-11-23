/* unit_0886B064: 0x0886B064-0x0886B0E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886B064 */

typedef int s32;

extern s32 func_0886A30C(char *, s32);
extern void func_0886E92C(char *, s32);

s32 func_0886B064(char *arg0) {
    s32 t;

    if (*(s32 *)(arg0 + 0x14) <= 0) {
        return 2;
    }
    t = *(s32 *)(arg0 + 0x14) - *(s32 *)(arg0 + 0x18);
    *(s32 *)(arg0 + 0x14) = t;
    if (t <= 0) {
        if (func_0886A30C(arg0, 1) == 0) {
            func_0886E92C(arg0, 0);
        }
        if (*(s32 *)(arg0 + 0x14) <= 0) {
            *(s32 *)(arg0 + 0x14) = 0;
        }
        return 1;
    }
    return 0;
}
