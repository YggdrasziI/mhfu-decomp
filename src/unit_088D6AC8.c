/* unit_088D6AC8: 0x088D6AC8-0x088D6B00 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

u8 func_088D6AC8(s32 arg0, s32 arg1) {
    s32 var_a2;
    char *temp_v1;

    var_a2 = 0;
loop_1:
    temp_v1 = (char *) (arg0 + var_a2);
    if (*(u8 *)(temp_v1 + 0x634) == (arg1 & 0xFF)) {
        return *(u8 *)(temp_v1 + 0x676);
    }
    var_a2 += 1;
    if (var_a2 >= 6) {
        return 0U;
    }
    goto loop_1;
}
