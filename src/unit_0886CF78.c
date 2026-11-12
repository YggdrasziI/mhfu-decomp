/* unit_0886CF78: 0x0886CF78-0x0886CFA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 func_0886CEA8(s32, s32);

u16 func_0886CF78(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_0886CEA8(arg0, arg1);
    if (temp_v0 != 0) {
        return *(u16 *)(temp_v0 + 0x14);
    }
    return 0xFFFFU;
}
