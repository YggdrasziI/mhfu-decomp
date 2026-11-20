/* unit_088DACF8: 0x088DACF8-0x088DAD58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DACA4 and func_088DAD58,
 * which is still in assembly (text_088DAD58).
 *
 * Tells whether func_08865CB8 holds for 0x36 or 0x7A.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_08865CB8(char *, s32, s32);

s32 func_088DACF8(char *arg0) {
    if ((u8) func_08865CB8(arg0, 0, 0x36) == 1 || (u8) func_08865CB8(arg0, 0, 0x7A) == 1) {
        return 1;
    }
    return 0;
}
