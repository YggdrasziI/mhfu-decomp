/* unit_088520D0: 0x088520D0-0x08852114 (ULES01213)
 *
 * Bounds (hypothesis): 1 non-zero 16-bit counter, between unrelated code.
 */

typedef unsigned short u16;

typedef struct S {
    char pad[0x2C];
    volatile u16 c;
} S;

u16 func_088520D0(S *s) {
    u16 t;
    s->c++;
    t = s->c;
    if (t == 0xFFFF) {
        s->c = t + 1;
    }
    if (s->c == 0) {
        s->c = 1;
    }
    return s->c;
}
