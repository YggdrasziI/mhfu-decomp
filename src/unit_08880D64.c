/* unit_08880D64: 0x08880D64-0x08880D94 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

void func_08880D64(char *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s8 arg5, s32 arg6) {
    s32 temp_a7;
    char *temp_a0;

    temp_a7 = (int) (arg0 + 0x56243C);
    temp_a0 = (char *) (temp_a7 + (arg6 * 2));
    *(s16 *)temp_a0 = arg2;
    *(s16 *)(temp_a0 + 8) = arg3;
    *(s16 *)(temp_a0 + 0x10) = arg4;
    *(s16 *)(temp_a0 + 0x18) = arg1;
    *(s8 *)((char *)((arg6 + temp_a7)) + 0x20) = arg5;
}
