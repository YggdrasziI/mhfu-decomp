/* unit_08813CC8: 0x08813CC8-0x08813CF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern void func_08813560(void *, s8, s32, s8);

void func_08813CC8(char *arg0) {
    if (*(u8 *)(arg0 + 0xA8D) != 2) {
        func_08813560(arg0, 2, 0, 0);
    }
}
