/* unit_0884860C: 0x0884860C-0x08848630 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char *D_08A62CB4;

void func_0884860C(char *arg0, char *arg1) {
    *(s16 *)(arg0 + 0x59E) = 0x1F;
    *(u8 *)(arg0 + 0x5A0) = (u8) *(u8 *)(arg1 + 0x55D);
}

void func_08848620(void) {
    *(s32 *)(D_08A62CB4 + 0x20) = 0;
}
