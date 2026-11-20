/* unit_088D5BD4: 0x088D5BD4-0x088D5C2C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between unit_088D5B54 and
 * unit_088D5C2C.
 */

typedef short s16;
typedef int s32;

void func_088D5BD4(char *arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4) {
    ((s16 *)(arg0 + 0x324))[arg4] = arg1;
    ((s16 *)(arg0 + 0x334))[arg4] = arg2 / 2;
    ((s16 *)(arg0 + 0x32C))[arg4] = arg3;
    if (arg4 == 0) {
        *(s32 *)(arg0 + 0x614) &= ~0x80;
    } else {
        *(s32 *)(arg0 + 0x614) &= ~0x100;
    }
}
