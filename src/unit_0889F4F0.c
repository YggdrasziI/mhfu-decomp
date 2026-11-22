/* unit_0889F4F0: 0x0889F4F0-0x0889F544 (ULES01213)
 *
 * Next step of the list walk started by func_0889F4BC.
 */

typedef int s32;

extern char *D_09A0C5D4;
extern s32 D_09A0C5DC;

s32 func_0889F4F0(void) {
    char *temp_v1;

    if (D_09A0C5DC == 0) {
        return 0;
    }
    if (D_09A0C5D4 == 0) {
        return 0;
    }
    temp_v1 = *(char **)(D_09A0C5D4 + 0xC);
    D_09A0C5D4 = temp_v1;
    if (*(char **)(temp_v1 + 0xC) == 0) {
        D_09A0C5D4 = 0;
        return 0;
    }
    return *(s32 *)(temp_v1 + 4);
}
