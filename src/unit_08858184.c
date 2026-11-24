/* unit_08858184: 0x08858184-0x088581C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08858184: classify the value returned by func_08857E6C. */

typedef int s32;
typedef unsigned int u32;

extern u32 func_08857E6C(s32 arg0, s32 arg1);

s32 func_08858184(s32 arg0, s32 arg1) {
    u32 v = func_08857E6C(arg0, arg1);
    s32 r;

    if (v < 0x97) {
        r = 0;
    } else if (v < 0x12D) {
        r = 1;
    } else {
        r = 2;
    }
    return r;
}
