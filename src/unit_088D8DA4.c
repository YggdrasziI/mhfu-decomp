/* unit_088D8DA4: 0x088D8DA4-0x088D8DF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

void func_088D8DA4(s32 arg0, s32 arg1, u8 *arg2, s8 arg3, s8 arg4) {
    u8 temp_v1;

    temp_v1 = *arg2;
    if ((s32) temp_v1 < 6) {
        *(s8 *)((char *)((temp_v1 + arg0)) + 0x676) = arg1;
        if (arg1 & 0xFF) {
            *(s8 *)((char *)((*arg2 + arg0)) + 0x634) = arg3;
        }
        *(s8 *)((char *)((*arg2 + arg0)) + 0x63A) = arg4;
        *arg2 += 1;
    }
}
