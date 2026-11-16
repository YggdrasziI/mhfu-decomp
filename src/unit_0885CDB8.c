/* unit_0885CDB8: 0x0885CDB8-0x0885CE00 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char D_08959FDF;

u8 func_0885CDB8(s32 arg0, char *arg1) {
    u16 temp_a0;

    temp_a0 = *(u16 *)(arg1 + 2);
    if (temp_a0 == 0) {
        return 0U;
    }
    if (*(u8 *)(arg1 + 1) == 5) {
        return *(&D_08959FDF + (temp_a0 * 0x18));
    }
    return 0U;
}
