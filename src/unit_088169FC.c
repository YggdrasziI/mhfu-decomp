/* unit_088169FC: 0x088169FC-0x08816A60 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088169FC: sum of func_08816930 over a string, stepping by its result.
 *
 * Speed setting; common subexpressions off so that the byte is loaded once
 * for the loop test and again for the call argument.
 */
#pragma optimize_for_size off
#pragma opt_common_subs off

typedef unsigned char u8;
typedef int s32;

extern s32 func_08816930(s32, s32);

s32 func_088169FC(s32 arg0, u8 *str) {
    s32 len = 0;
    s32 n;

    while (*str != 0) {
        n = func_08816930(arg0, *str);
        len += n;
        str += n;
    }
    return len;
}
