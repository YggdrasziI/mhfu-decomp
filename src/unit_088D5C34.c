/* unit_088D5C34: 0x088D5C34-0x088D5C74 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

void func_088D5C34(char *arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 var_t0;

    var_t0 = arg2 >> 1;
    if (arg2 < 0) {
        var_t0 = (s32) (arg2 + 1) >> 1;
    }
    *(s16 *)(arg0 + 0x324) = arg1;
    *(s16 *)(arg0 + 0x334) = (s16) var_t0;
    *(s16 *)(arg0 + 0x32C) = arg3;
    *(s16 *)(arg0 + 0x326) = (s16) (arg1 + 0x64);
    *(s16 *)(arg0 + 0x336) = (s16) var_t0;
    *(s16 *)(arg0 + 0x32E) = arg3;
    *(s32 *)(arg0 + 0x614) = (s32) (*(s32 *)(arg0 + 0x614) & ~0x180);
}
