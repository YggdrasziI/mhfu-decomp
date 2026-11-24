/* unit_088581C0: 0x088581C0-0x0885821C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088581C0: rank of a 16-bit value against fixed thresholds.
 * An else-if chain into one result local keeps the last compare as a
 * `beql` with the default in its slot (separate returns add a `b`). */

typedef int s32;
typedef unsigned short u16;

s32 func_088581C0(s32 arg0, u16 arg1) {
    s32 r;

    if (arg1 < 1000) r = 0;
    else if (arg1 < 2500) r = 1;
    else if (arg1 < 4500) r = 2;
    else if (arg1 < 6000) r = 3;
    else if (arg1 < 7000) r = 4;
    else r = 5;
    return r;
}
