/* unit_0890C490: 0x0890C490-0x0890C52C (ULES01213)
 *
 * Decodes a variable-length signed number (1 to 4 bytes, low bits of the
 * first byte give the length) and returns the pointer past it.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

char *func_0890C490(char *p, s32 *out) {
    s32 v = *(s8 *)p;
    u32 b1;
    u32 b2;

    if ((v & 1) == 0) {
        *out = v >> 1;
        return p + 1;
    }
    b1 = (u8)p[1];
    if ((v & 2) == 0) {
        *out = ((v >> 2) << 8) | b1;
        return p + 2;
    }
    b2 = (u8)p[2];
    if ((v & 4) == 0) {
        *out = b2 | (((v >> 3) << 16) | (b1 << 8));
        return p + 3;
    }
    *out = (u8)p[3] | ((b2 << 8) | (((v >> 3) << 24) | (b1 << 16)));
    return p + 4;
}
