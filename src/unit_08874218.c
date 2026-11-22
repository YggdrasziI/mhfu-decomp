/* unit_08874218: 0x08874218-0x08874278 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;

extern s32 func_08874278(char *arg0, s32 arg1);

s32 func_08874218(char *arg0) {
    s32 i;

    for (i = 0; i < 0x3D; i++) {
        if (!(func_08874278(arg0, i) != 0) == 0) {
            return 1;
        }
    }
    return 0;
}
