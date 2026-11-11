/* unit_08886734: 0x08886734-0x08886780 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

s32 func_08886734(s32 arg0, s32 arg1) {
    char *temp_v1;

    temp_v1 = (char *) (arg0 + (arg1 * 0x18));
    if ((*(s32 *)temp_v1 != 0) && (*(s16 *)(temp_v1 + 0x16) > 0) && (*(s32 *)(temp_v1 + 8) == 3)) {
        return 1;
    }
    return 0;
}
