/* unit_088123C8: 0x088123C8-0x0881246C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_08812610(char *, s32);

s32 func_088123C8(char *arg0) {
    s32 base;
    s32 i;
    s32 bit;
    s32 *p;

    base = func_08812610(arg0, 0x2D);
    if (base != -1) {
        i = 0;
        do {
            bit = 1 << (i % 32);
            p = (s32 *)(arg0 + (i / 32) * 4 + 0xC58);
            if ((*p & bit) == 0) {
                *p |= bit;
                return base + (i << 10);
            }
            i++;
        } while (i < 32);
    }
    return -1;
}
