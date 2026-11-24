/* unit_088526B4: 0x088526B4-0x088526F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;

extern char *D_08A631A0;
extern u16 func_088900C4(char *, s32);

float func_088526B4(void) {
    return 0.001f * (float)(func_088900C4(D_08A631A0, 1) & 0x3FF);
}
