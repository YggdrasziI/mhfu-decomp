/* unit_0884FC94: 0x0884FC94-0x0884FCB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_0899BF40;

s32 func_0884FC94(s32 arg0, s32 arg1) {
    return ((s32 *)&D_0899BF40)[(arg1 & 0xFF)];
}
