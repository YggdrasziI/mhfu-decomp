/* unit_0886DFAC: 0x0886DFAC-0x0886E000 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;

void func_0886DFAC(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;

    if (*(u8 *)(D_089CC438 + 0x422) == 0) {
        temp_v1 = *(s32 *)(arg0 + 0x10);
        if (temp_v1 > 0) {
            temp_v1_2 = temp_v1 - arg1;
            *(s32 *)(arg0 + 0x10) = temp_v1_2;
            if (temp_v1_2 < 0) {
                *(s32 *)(arg0 + 0x10) = 0;
            }
        }
        temp_v1_3 = *(s32 *)(arg0 + 0x678);
        if (temp_v1_3 > 0) {
            temp_v1_4 = temp_v1_3 - arg1;
            *(s32 *)(arg0 + 0x678) = temp_v1_4;
            if (temp_v1_4 < 0) {
                *(s32 *)(arg0 + 0x678) = 0;
            }
        }
    }
}
