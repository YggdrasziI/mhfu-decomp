/* unit_0886CE90: 0x0886CE90-0x0886CEA8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_09A4F060;

void func_0886CE90(s32 arg0, s32 arg1, s16 arg2) {
    *(s16 *)((char *)(((arg1 << 5) + D_09A4F060)) + 0x1C) = arg2;
}
