/* unit_0886E27C: 0x0886E27C-0x0886E2EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern void func_0886E2EC(char *, s32 *);

void func_0886E27C(char *arg0) {
    s32 *p;
    s32 i;

    *(signed char *)(arg0 + 0x67C) = *(signed char *)(*(char **)(arg0 + 0x68) + 0x1E);
    p = (s32 *)(*(char **)(arg0 + 0x68) + 0x20);
    for (i = 0; i < 2; i++, p += 2) {
        if (*p != 0) {
            func_0886E2EC(arg0, p);
        }
    }
}
