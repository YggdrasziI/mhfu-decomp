/* unit_08891BC8: 0x08891BC8-0x08891D4C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * C++: the unroll guard flag of the copy loop is a one-byte bool
 * (`andi 0xFF`), which C does not give.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern "C" {

extern s32 D_089CBBE8;
extern const u8 D_08931C2C[][3];

extern s32 func_08816930(s32 arg0, s32 arg1);

void func_08891BC8(s32 arg0, s8 *src, s8 *dst) {
    s32 n;
    s32 i;
    s32 c;

    while (*src != 0) {
        n = func_08816930(D_089CBBE8, (u8) *src);
        if (n == 0) {
            break;
        }
        if (n == 1) {
            c = *src;
            if (c >= 0x20 && c < 0x7F) {
                src++;
                dst[0] = D_08931C2C[c][0];
                dst[1] = D_08931C2C[c][1];
                dst[2] = D_08931C2C[c][2];
                dst += 3;
            } else {
                *dst = c;
                src++;
                dst++;
            }
        } else {
            for (i = 0; i < n; i++) {
                *dst++ = *src++;
            }
        }
    }
    *dst = 0;
}

}
