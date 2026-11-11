/* unit_08865CB8: 0x08865CB8-0x08865CEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_08865CB8(char *arg0, s32 arg1, s32 arg2) {
    if ((*(u8 *)(arg0 + 0x298) == (arg1 & 0xFF)) && (*(u8 *)(arg0 + 0x299) == (arg2 & 0xFF))) {
        return 1;
    }
    return 0;
}
