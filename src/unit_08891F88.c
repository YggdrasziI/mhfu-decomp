/* unit_08891F88: 0x08891F88-0x08892004 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Counts the characters of a string: lead bytes 0x81-0x9F and 0xE0-0xFF
 * start a two-byte character counted once, '\n' is skipped.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

s32 func_08891F88(s32 arg0, s8 *arg1) {
    s32 count;
    s32 c;

    count = 0;
    while ((c = *arg1) != 0) {
        if (((u8)c >= 0x81 && (u8)c <= 0x9F) || ((u8)c >= 0xE0 && (u8)c <= 0xFF)) {
            arg1++;
        } else if (c == '\n') {
            arg1++;
            continue;
        }
        arg1++;
        count++;
    }
    return count;
}
