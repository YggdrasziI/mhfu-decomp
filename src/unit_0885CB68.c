/* unit_0885CB68: 0x0885CB68-0x0885CB98 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_08978474;

s32 func_0885CB68(s32 arg0, s32 arg1, s16 arg2) {
    return ((s32 *)&D_08978474)[(arg1 & 0xFF)] + (arg2 * 0x28);
}
