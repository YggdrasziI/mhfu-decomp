/* unit_0887FAB4: 0x0887FAB4-0x0887FAEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;

extern void func_088A3480(void);

void func_0887FAB4(char *arg0) {
    if (*(u8 *)(arg0 + 0x14) == 0) {
        func_088A3480();
        *(u8 *)(arg0 + 0x14) = 1U;
    }
}
