/* unit_08896C10: 0x08896C10-0x08896C2C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_089B152E;

u8 func_08896C10(s32 arg0, s32 arg1) {
    return *(&D_089B152E + ((arg1 & 0xFF) * 4));
}
