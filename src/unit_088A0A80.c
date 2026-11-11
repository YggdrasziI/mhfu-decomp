/* unit_088A0A80: 0x088A0A80-0x088A0A90 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

void func_088A0A80(char *arg0, s16 arg1, s16 arg2) {
    *(s32 *)arg0 = 0;
    *(s16 *)(arg0 + 4) = arg1;
    *(s16 *)(arg0 + 6) = arg2;
}
