/* unit_08857294: 0x08857294-0x088572B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_0899CC08;

s32 func_08857294(s32 arg0, s8 arg1) {
    return ((s32 *)&D_0899CC08)[arg1];
}
