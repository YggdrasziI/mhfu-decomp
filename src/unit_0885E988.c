/* unit_0885E988: 0x0885E988-0x0885E9F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

void func_0885E988(s32 arg0, char *arg1) {
    u16 temp_a0;
    s32 temp_a2;
    u16 temp_a3;
    u16 temp_v1;

    temp_a3 = *(u16 *)(arg1 + 8);
    temp_a2 = *(u16 *)(arg1 + 6);
    temp_a0 = *(u16 *)(arg1 + 0xA);
    if ((temp_a0 + (temp_a2 + temp_a3)) != 0) {
        if (temp_a2 == 0) {
            if (temp_a3 != 0) {
                *(u16 *)(arg1 + 6) = temp_a3;
                *(u16 *)(arg1 + 8) = 0U;
            } else if (temp_a0 != 0) {
                *(u16 *)(arg1 + 6) = temp_a0;
                *(u16 *)(arg1 + 0xA) = 0U;
            }
        }
        if (*(u16 *)(arg1 + 8) == 0) {
            temp_v1 = *(u16 *)(arg1 + 0xA);
            if (temp_v1 != 0) {
                *(u16 *)(arg1 + 8) = temp_v1;
                *(u16 *)(arg1 + 0xA) = 0U;
            }
        }
    }
}
