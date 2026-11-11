/* unit_088D6488: 0x088D6488-0x088D64E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;

void func_088D6488(char *arg0) {
    s16 temp_v1_3;
    s8 temp_v1_4;
    u8 temp_v1;
    u8 temp_v1_2;

    temp_v1 = *(u8 *)(arg0 + 0x62C);
    if (temp_v1 != 0) {
        *(u8 *)(arg0 + 0x62C) = (u8) (temp_v1 - 1);
    }
    temp_v1_2 = *(u8 *)(arg0 + 0x46A);
    if (temp_v1_2 != 0) {
        *(u8 *)(arg0 + 0x46A) = (u8) (temp_v1_2 - 1);
    }
    temp_v1_3 = *(s16 *)(arg0 + 0x630);
    if (temp_v1_3 != 0) {
        *(s16 *)(arg0 + 0x630) = (s16) (temp_v1_3 - 1);
    }
    temp_v1_4 = *(s8 *)(arg0 + 0x5F0);
    if (temp_v1_4 != 0) {
        *(s8 *)(arg0 + 0x5F0) = (s8) (temp_v1_4 - 1);
    }
}
