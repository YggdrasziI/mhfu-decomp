/* unit_08886638: 0x08886638-0x0888664C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

void func_08886638(s32 arg0, s32 arg1, s16 arg2, s32 arg3) {
    char *temp_v1;

    temp_v1 = (char *) (arg0 + (arg1 * 0x10));
    *(s16 *)(temp_v1 + 0x3C) = arg2;
    *(s32 *)(temp_v1 + 0x38) = arg3;
}
