/* unit_0885CCD0: 0x0885CCD0-0x0885CCE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_08978488;

u8 func_0885CCD0(s32 arg0, s32 arg1) {
    return *(&D_08978488 + (arg1 & 0xFFFF));
}
