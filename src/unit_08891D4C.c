/* unit_08891D4C: 0x08891D4C-0x08891E0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef int s32;
typedef unsigned char u8;

extern u8 *D_089AD37C;

void func_08891D4C(s32 arg0, char *src, char *dst) {
    u8 *tbl;
    u8 *p;
    s32 c;
    s32 v;

    c = *src;
    if (c != 0) {
        tbl = D_089AD37C;
        do {
            v = (char)c;
            if ((v >= 0x81 && v <= 0x9F) || (v >= 0xE0 && v < 0x100)) {
                dst[0] = c;
                dst[1] = src[1];
                src += 2;
                dst += 2;
            } else if (v >= 0x20 && v < 0x7F) {
                p = tbl + v * 2;
                src++;
                dst[0] = p[0];
                dst[1] = p[1];
                dst += 2;
            } else {
                *dst = c;
                src++;
                dst++;
            }
            c = *src;
        } while (c != 0);
    }
    *dst = 0;
}
