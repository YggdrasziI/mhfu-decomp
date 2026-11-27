/* unit_0890DA3C: 0x0890DA3C-0x0890DA8C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890DA3C: reads a signed flag byte at arg0, then skips two (three
 * when bit 0x40 of that byte is set) encoded values after it with
 * func_0890C3F4 and returns the position after the last one.
 */

typedef int s32;
typedef signed char s8;

extern s32 func_0890C3F4(s32, s32 *);

s32 func_0890DA3C(s8 *arg0) {
    s32 tmp;
    s32 f = *arg0 & 0x40;
    s32 p;

    p = func_0890C3F4((s32)(arg0 + 1), &tmp);
    p = func_0890C3F4(p, &tmp);
    if (f != 0) {
        p = func_0890C3F4(p, &tmp);
    }
    return p;
}
