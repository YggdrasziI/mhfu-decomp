/* unit_0890C2D8: 0x0890C2D8-0x0890C2FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_09A5F110;

s32 func_0890C2D8(s32 arg0, s32 arg1, char *arg2) {
    *(char **)arg2 = (char *) D_09A5F110;
    *(s32 *)(arg2 + 4) = arg1;
    *(s32 *)(arg2 + 8) = arg0;
    D_09A5F110 = arg2;
    return arg0;
}
