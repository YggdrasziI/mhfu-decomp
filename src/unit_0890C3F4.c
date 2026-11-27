/* unit_0890C3F4: 0x0890C3F4-0x0890C490 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Reads a variable-length (1 to 4 bytes) encoded unsigned value; the low
 * bits of the first byte give the length.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 *func_0890C3F4(u8 *p, u32 *out) {
    u32 b0 = p[0];
    u32 b1;
    u32 b2;

    if ((b0 & 1) == 0) {
        *out = b0 >> 1;
        return p + 1;
    }
    b1 = p[1];
    if ((b0 & 2) == 0) {
        *out = ((b0 >> 2) << 8) | b1;
        return p + 2;
    }
    b2 = p[2];
    if ((b0 & 4) == 0) {
        *out = b2 | (((b0 >> 3) << 16) | (b1 << 8));
        return p + 3;
    }
    *out = p[3] | ((b2 << 8) | (((b0 >> 3) << 24) | (b1 << 16)));
    return p + 4;
}
