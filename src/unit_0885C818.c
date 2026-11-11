/* unit_0885C818: 0x0885C818-0x0885C83C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_089A47D8;

u8 func_0885C818(s32 arg0, s32 arg1) {
    return *(&D_089A47D8 + ((arg1 & 0xFFFF) * 0xA));
}
