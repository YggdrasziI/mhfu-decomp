/* unit_088134C0: 0x088134C0-0x088134E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * Needs opt_common_subs off: otherwise the result 1 and the compared
 * constant 1 share one register.
 */

#pragma opt_common_subs off

typedef unsigned char u8;
typedef int s32;

s32 func_088134C0(char *arg0) {
    s32 r = 1;
    s32 m = *(u8 *)(arg0 + 0x810);

    if (m != 1 && m != 3) {
        r = 0;
    }
    return r;
}
