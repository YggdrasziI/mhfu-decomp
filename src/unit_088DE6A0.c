/* unit_088DE6A0: 0x088DE6A0-0x088DE6EC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;

s32 func_088DE6A0(s32 arg0, s32 arg1, char *arg2) {
    if (arg1 != 4) {
        return 0;
    }
    *(u8 *)(D_089CC438 + 0x2A) = (u8) (*(u8 *)(D_089CC438 + 0x2A) & 0xF0);
    *(s8 *)(D_089CC438 + 0x6AF0C) = 1;
    *(s8 *)(arg2 + 0x215) = 1;
    return 0;
}
