/* unit_0887FAEC: 0x0887FAEC-0x0887FB28 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;

extern int func_088A34E4(u8);

void func_0887FAEC(char *arg0) {
    u8 temp_a0;

    temp_a0 = *(u8 *)(arg0 + 0x14);
    if (temp_a0 == 1) {
        func_088A34E4(temp_a0);
        *(u8 *)(arg0 + 0x14) = 0U;
    }
}
