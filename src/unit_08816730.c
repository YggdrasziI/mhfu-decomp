/* unit_08816730: 0x08816730-0x088167D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08816730: decode up to n - 1 characters of a string into a u16
 * buffer, terminated by 0; returns the number of characters stored. */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u16 func_08816460(s32, u8 **);

s32 func_08816730(s32 arg0, u16 *out, s32 n, u8 *src) {
    s32 count;
    u16 c;

    count = 0;
    if (n <= 0) {
        return 0;
    }
    n--;
    c = func_08816460(arg0, &src);
    if (c != 0) {
        do {
            if (n <= 0) {
                break;
            }
            *out = c;
            n--;
            out++;
            count++;
            c = func_08816460(arg0, &src);
        } while (c != 0);
    }
    *out = 0;
    return count;
}
