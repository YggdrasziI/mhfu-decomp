/* unit_088A6040: 0x088A6040-0x088A6088 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

extern char D_09A0FD84;

char *func_088A6040(s32 arg0, u32 arg1) {
    char *temp_v1;

    temp_v1 = (char *) (((s32 *)&D_09A0FD84)[arg0]);
    if (temp_v1 == 0) {
        return 0;
    }
    if (arg1 >= (u32) *(u32 *)(temp_v1 + 0xC)) {
        return 0;
    }
    return temp_v1 + (arg1 << 5) + 0x10;
}
