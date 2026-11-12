/* unit_0889F4BC: 0x0889F4BC-0x0889F4F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_09A0C5D4;
extern s32 D_09A0C5DC;
extern char *D_09A0C5E0;

s32 func_0889F4BC(void) {
    char *temp_v1;

    if (D_09A0C5DC == 0) {
        return 0;
    }
    temp_v1 = *(char **)(D_09A0C5E0 + 0xC);
    D_09A0C5D4 = temp_v1;
    return *(s32 *)(temp_v1 + 4);
}
