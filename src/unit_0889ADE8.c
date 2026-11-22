/* unit_0889ADE8: 0x0889ADE8-0x0889AEB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;

static inline s32 cmp6(u8 *a, u8 *b) {
    s32 k;

    for (k = 0; k < 6; k++) {
        if (a[k] < b[k]) {
            return -1;
        }
        if (b[k] < a[k]) {
            return 1;
        }
    }
    return 0;
}

s32 func_0889ADE8(u8 *arg0) {
    u8 count;
    u8 *entry;
    s32 found;
    u32 i;
    s32 j;
    u8 *table;

    count = arg0[0xBBD];
    entry = arg0 + 0xBC0;
    found = 0;
    for (i = 0; i < count; i++, entry += 0xC8) {
        for (j = 0; j < *(s8 *)(arg0 + 0xEE3); j++) {
            table = arg0 + 0x57C + (u8)j * 0xC8;
            if (cmp6(entry, table) == 0) {
                found++;
                break;
            }
        }
    }
    return count == found;
}
