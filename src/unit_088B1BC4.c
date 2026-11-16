/* unit_088B1BC4: 0x088B1BC4-0x088B1BF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;

void func_088B1BC4(char *arg0) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 0x23);
    if (temp_a1 == 1) {
        *(s8 *)(arg0 + 0x21) = 1;
        *(s8 *)(arg0 + 0x22) = 0;
    } else {
        if (temp_a1 == 2) {
            *(s8 *)(arg0 + 0x21) = 2;
            *(s8 *)(arg0 + 0x22) = 0;
        }
    }
}
