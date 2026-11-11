/* unit_08890DE8: 0x08890DE8-0x08890E08 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;

void func_08890DE8(char *arg0, s8 arg1, u8 arg2) {
    *(s8 *)(arg0 + 0x12C) = arg1;
    *(u8 *)(arg0 + 0x12D) = arg2;
    *(u8 *)(arg0 + 0x15F) = (u8) *(u8 *)(arg0 + 0x12D);
}

void func_08890DFC(char *arg0, s16 arg1, s16 arg2) {
    *(s16 *)(arg0 + 0x120) = arg1;
    *(s16 *)(arg0 + 0x122) = arg2;
}
