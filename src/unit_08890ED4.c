/* unit_08890ED4: 0x08890ED4-0x08890F68 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;

extern s32 D_089CBBE8;
extern s32 func_08816460(s32, s32 *);
extern s32 func_08894874(s32, s32);

s32 func_08890ED4(s32 arg0, s32 arg1) {
    s32 count;
    s32 c;

    count = 0;
    while ((c = (u16) func_08816460(D_089CBBE8, &arg1)) != 10) {
        count += !(func_08894874(arg0, c) != 0) ? 2 : 1;
    }
    return count;
}
