/* unit_0885981C: 0x0885981C-0x08859848 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885981C: counts how many doublings of 1 stay below arg1 (at most 11).
 * arg0 is unused. */

typedef int s32;
typedef unsigned int u32;

s32 func_0885981C(s32 arg0, u32 arg1) {
    u32 v;
    s32 i;

    v = 1;
    i = 0;
    while (1) {
        if (!(v < arg1)) {
            break;
        }
        i++;
        v <<= 1;
        if (i > 10) {
            break;
        }
    }
    return i;
}
