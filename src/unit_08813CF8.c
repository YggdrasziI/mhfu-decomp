/* unit_08813CF8: 0x08813CF8-0x08813D40 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
typedef signed char s8;
extern void func_08813560(char *, s8, s32, s8);
void func_08813CF8(char *arg0) {
    switch (*(u8 *)(D_089CC438 + 0x6AF10)) {
    case 0xC:
        break;
    default:
        func_08813560(arg0, 1, 0, 0);
    }
}
