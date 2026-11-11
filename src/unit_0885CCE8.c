/* unit_0885CCE8: 0x0885CCE8-0x0885CD18 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_08978488;
extern int func_0885DF38(s32, s32);

u8 func_0885CCE8(s32 arg0, s32 arg1) {
    return *(&D_08978488 + (func_0885DF38(arg0, arg1) & 0xFFFF));
}
