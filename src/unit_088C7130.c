/* unit_088C7130: 0x088C7130-0x088C7184 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

void func_088C7130(char *arg0, char *arg1) {
    char *temp_v1;

    temp_v1 = *(char **)(arg0 + 0xA2E0);
    if (temp_v1 == 0) {
        *(char **)(arg0 + 0xA2E0) = arg1;
        *(s32 *)(arg1 + 0x10) = 0;
        *(char **)(arg1 + 0x14) = 0;
        return;
    }
    *(char **)(temp_v1 + 0x10) = arg1;
    *(char **)(arg1 + 0x14) = (char *) *(char **)(arg0 + 0xA2E0);
    *(s32 *)(arg1 + 0x10) = 0;
    *(char **)(arg0 + 0xA2E0) = arg1;
}
