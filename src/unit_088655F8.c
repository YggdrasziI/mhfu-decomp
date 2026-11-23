/* unit_088655F8: 0x088655F8-0x08865648 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088655F8: converts three u16 angles (65536 units per turn) to radians. */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned short u16;
typedef float f32;

void func_088655F8(f32 *arg0, u16 *arg1) {
    arg0[0] = 9.58738e-5f * (s32)arg1[0];
    arg0[1] = 9.58738e-5f * (s32)arg1[2];
    arg0[2] = 9.58738e-5f * (s32)arg1[4];
    ((s32 *)arg0)[3] = 0;
}
