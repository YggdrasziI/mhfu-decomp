/* unit_088DDFE8: 0x088DDFE8-0x088DE014 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_088DE014(s32, s32);

s32 func_088DDFE8(s32 arg0, u8 arg1) {
    return ~func_088DE014(arg0, (arg1 + 0x17DF) & 0xFFFF) != 0;
}
