/* unit_0888D708: 0x0888D708-0x0888D734 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_089CBBE4;
extern s32 func_08865C88(s32, s32);

s32 func_0888D708(void) {
    return func_08865C88(*(s32 *)(D_089CBBE4 + 0xA84), 0x80000) != 0;
}
