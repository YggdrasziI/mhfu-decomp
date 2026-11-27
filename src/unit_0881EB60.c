/* unit_0881EB60: 0x0881EB60-0x0881EC2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62D8C;

extern u8 func_08826F80(u8 *, int);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

u16 func_0881EB60(u8 *arg0, u16 pad)
{
    u8 n = func_08826F80(arg0, 9) + 1;

    if (pad & 0xA0) {
        if (pad & 0x20) {
            arg0[0x57F]++;
            if (arg0[0x57F] > n) {
                arg0[0x57F] = 0;
            }
        } else {
            if (arg0[0x57F] == 0) {
                arg0[0x57F] = n;
            } else {
                arg0[0x57F]--;
            }
        }
        func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
    }
    return pad & 0x2008;
}
