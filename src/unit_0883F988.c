/* unit_0883F988: 0x0883F988-0x0883F9F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;

extern u8 func_088DACF8(char *);
extern s32 func_088568AC(char *, s32);

s32 func_0883F988(s32 arg0, char *arg1) {
    if ((s32)((*(s32 *)(arg1 + 0x614) & 0x10) != 0) == 1) {
        return 1;
    }
    if (func_088DACF8(arg1) == 1 && func_088568AC(D_089CC438, 0x369) != 0) {
        return 1;
    }
    return 0;
}
