/* unit_08856F7C: 0x08856F7C-0x08856FF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
/* func_08856F7C */

typedef int s32;

extern s32 func_08857058(void *, s32, s32);

s32 func_08856F7C(void *arg0) {
    s32 i;
    s32 j;

    for (i = 0x5218; i < 0x5220; i++) {
        for (j = 0; j < 5; j++) {
            if (func_08857058(arg0, i, j) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
