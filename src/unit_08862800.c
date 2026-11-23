/* unit_08862800: 0x08862800-0x088629DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 func_08862748(s32, s32);
extern u8 *func_08862768(s32, s32, s32);

void func_08862800(s32 *arg0, u16 arg1, u8 arg2, u8 arg3, u8 arg4) {
    u8 *ids;
    s32 n;
    s32 i;
    u8 *m;

    ids = func_08862768(arg0[0], arg1, 0);
    n = (u8) func_08862748(arg0[0], arg1);
    for (i = 0; i < n; i++) {
        m = (u8 *) arg0[2] + ids[i] * 16;
        m[0] = arg2;
        m[1] = arg3;
        m[2] = arg4;
    }
}
