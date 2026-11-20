/* unit_088DE7C8: 0x088DE7C8-0x088DE804 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088DE6EC, still in assembly
 * (text_088DE6EC), and unit_088DE804.
 *
 * Tells whether the byte at +0x6ADDD of D_089CC438 is set and the one at
 * +0x480 clear.
 *
 * C++: bool conversion.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern "C" {

extern char *D_089CC438;

s32 func_088DE7C8(void) {
    s32 r = 0;

    if (*(s8 *)(D_089CC438 + 0x6ADDD)) {
        if ((bool) *(u8 *)(D_089CC438 + 0x480) ^ 1) {
            r = 1;
        }
    }
    return r;
}

}
