/* unit_08841520: 0x08841520-0x088415D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

void func_08841520(char *arg0) {
    u8 temp_a1;
    u8 temp_v1;
    char *temp_a2;

    if (!(*(s32 *)(arg0 + 0x1194) & 0x10) && (temp_a2 = *(char **)(arg0 + 0x530), (*(u8 *)(temp_a2 + 0x1E8) == 8))) {
        if (*(u8 *)(temp_a2 + 0x1103) == 0) {
            *(u8 *)(arg0 + 0x11A4) = (u8) *(u8 *)(temp_a2 + 0x1102);
            *(u8 *)(arg0 + 0x11A5) = 0U;
            *(u8 *)(arg0 + 0x11A6) = 0U;
            *(u8 *)(arg0 + 0x11A7) = 0U;
            *(u8 *)(arg0 + 0x11A8) = 0U;
            *(u8 *)(arg0 + 0x11A9) = 0U;
            *(u8 *)(arg0 + 0x11AA) = 0U;
        } else {
            temp_a1 = *(u8 *)(temp_a2 + 0x1102);
            if (*(u8 *)(arg0 + 0x11A4) != temp_a1) {
                *(u8 *)(arg0 + 0x11A4) = temp_a1;
                *(u8 *)(arg0 + 0x11A5) = 7U;
                *(u8 *)(arg0 + 0x11AA) = (u8) *(u8 *)(arg0 + 0x11A9);
                *(u8 *)(arg0 + 0x11A9) = (u8) *(u8 *)(arg0 + 0x11A8);
                *(u8 *)(arg0 + 0x11A8) = (u8) *(u8 *)(arg0 + 0x11A7);
                *(u8 *)(arg0 + 0x11A7) = (u8) *(u8 *)(arg0 + 0x11A6);
                *(u8 *)(arg0 + 0x11A6) = (u8) *(u8 *)(temp_a2 + 0x1103);
            }
            temp_v1 = *(u8 *)(arg0 + 0x11A5);
            if ((s32) temp_v1 > 0) {
                *(u8 *)(arg0 + 0x11A5) = (u8) (temp_v1 - 1);
            }
        }
    }
}
