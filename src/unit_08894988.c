/* unit_08894988: 0x08894988-0x088949EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function after unit_08894874; func_088949EC after it is still in
 * assembly.
 * Its jump table (0x08931DAC-0x08931DC4) is linked from this unit.
 */

typedef int s32;
typedef signed char s8;

s32 func_08894988(s8 *arg0) {
    switch (arg0[0x15D]) {
    case 0:
    default:
        return 9;
    case 1:
        return 10;
    case 2:
        return 11;
    case 3:
        return 12;
    case 4:
        return 13;
    case 5:
        return 14;
    }
}
