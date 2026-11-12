/* unit_088571F8: 0x088571F8-0x08857294 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;

extern int func_0880BFF0(void *, void *, int);

void func_088571F8(char *arg0, s8 *arg1) {
    u8 temp_a3;
    char *temp_s0;

    if ((*(u8 *)(arg0 + 0x6992C) == 2) && (*arg1 != 0)) {
        temp_s0 = arg0 + 0x696F4;
        temp_a3 = *(u8 *)(temp_s0 + 0x23B);
        if (((s8) temp_a3 != -1) && (func_0880BFF0(arg0 + ((temp_a3 & 0xFF) * 0x70) + 0x6975C, arg1 + 0x60, 0x10) == 0)) {
            *(u8 *)(temp_s0 + 0x23B) = 0xFFU;
        }
    }
}
