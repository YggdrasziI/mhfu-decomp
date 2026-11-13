/* unit_0881EAF8: 0x0881EAF8-0x0881EB60 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_0881C45C(s32, void *, s32, s32);
extern s32 func_0881ECDC(s32);

s32 func_0881EAF8(char *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~4);
    if ((func_0881ECDC((s32) arg0) & 0xFF) == 1) {
        func_0881C45C((s32) arg0, (arg0 + 0x57F), arg1, (s32) *(u8 *)(arg0 + 0x581));
    }
    return arg1;
}
