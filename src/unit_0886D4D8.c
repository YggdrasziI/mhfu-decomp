/* unit_0886D4D8: 0x0886D4D8-0x0886D524 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_0886DB0C(s32, s32, s32);
extern s32 func_0886DC68(s32, s32, s32);

void func_0886D4D8(char *arg0) {
    s32 sp1C;
    s32 temp_a1;
    s32 temp_a1_2;

    sp1C = 0;
    temp_a1 = *(s32 *)(arg0 + 0x71C);
    if (temp_a1 != 0) {
        func_0886DB0C((s32) arg0, temp_a1, (s32) &sp1C);
    }
    temp_a1_2 = *(s32 *)(arg0 + 0x718);
    if (temp_a1_2 != 0) {
        func_0886DC68((s32) arg0, temp_a1_2, (s32) &sp1C);
    }
}
