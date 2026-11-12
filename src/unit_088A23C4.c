/* unit_088A23C4: 0x088A23C4-0x088A2404 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088A1798(void *);

void func_088A23C4(char *arg0) {
    if (*(s32 *)(arg0 + 0x54) == 6) {
        func_088A1798(arg0);
        *(s32 *)(arg0 + 0x54) = 0;
        *(s32 *)(arg0 + 0x58) = 0;
        *(s32 *)(arg0 + 0x5C) = 0;
    }
}
