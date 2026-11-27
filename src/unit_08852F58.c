/* unit_08852F58: 0x08852F58-0x08852FA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08852F58: counts the set bits among the first 62 flags at +0x44AC. */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

s32 func_08852F58(char *arg0) {
    s32 n;
    u32 i;
    u32 b;

    n = 0;
    for (i = 0; i < 62; i++) {
        b = ((u8 *)arg0)[(i >> 3) + 0x44AC];
        if (b & (1 << (i & 7))) {
            n++;
        }
    }
    return n;
}
