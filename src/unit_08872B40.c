/* unit_08872B40: 0x08872B40-0x08872B7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

s32 func_08872B40(char *arg0) {
    s16 sum;
    s32 i;

    sum = 0;
    for (i = 0; i < 2; i++) {
        if (*(s8 *)(arg0 + 0x786) > 0) {
            sum += *(s8 *)(*(char **)(arg0 + 0x768) + 4);
        }
        arg0 += 0x2C;
    }
    return sum;
}
