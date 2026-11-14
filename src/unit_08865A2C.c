/* unit_08865A2C: 0x08865A2C-0x08865A64 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

void func_08865A2C(char *arg0) {
    u8 temp_a1;
    u8 temp_v1;

    temp_a1 = *(u8 *)(arg0 + 0x396);
    if (temp_a1 != 0) {
        *(u8 *)(arg0 + 0x33C) = (u8) (*(u8 *)(arg0 + 0x33C) + temp_a1);
        *(u8 *)(arg0 + 0x396) = 0U;
        return;
    }
    temp_v1 = *(u8 *)(arg0 + 0x33C);
    if ((s32) temp_v1 > 0) {
        *(u8 *)(arg0 + 0x33C) = (u8) (temp_v1 - 1);
    }
}
