/* unit_0885100C: 0x0885100C-0x08851078 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 D_089CBBE4;
extern s32 D_089CBFFC;
extern int func_08812A08(s32, s32);
extern int func_0884B284(s32);

void func_0885100C(char *arg0) {
    s32 temp_a1;

    *(s16 *)(arg0 + 0x1C) = 0;
    *(s8 *)(arg0 + 0x28) = 0;
    *(s8 *)(arg0 + 0xC) = 0;
    *(s8 *)(arg0 + 0xD) = 0;
    *(s16 *)(arg0 + 0x6AF12) = 1;
    temp_a1 = *(s32 *)(arg0 + 0x6AF14);
    *(s32 *)(arg0 + 0x6AF14) = (s32) (temp_a1 & ~1);
    func_08812A08(D_089CBBE4, temp_a1);
    func_0884B284(D_089CBFFC);
}
