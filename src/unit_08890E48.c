/* unit_08890E48: 0x08890E48-0x08890ED4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;

extern s32 D_089CBBE8;
extern u16 func_08816460(s32, s32 *);
extern s32 func_08894874(s32, u16);

s32 func_08890E48(s32 arg0, s32 arg1) {
    u16 c;
    s32 n = 0;

    while ((c = func_08816460(D_089CBBE8, &arg1)) != 0) {
        n += (!(func_08894874(arg0, c) != 0)) ? 2 : 1;
    }
    return n;
}
