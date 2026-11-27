/* unit_0881C5D8: 0x0881C5D8-0x0881C68C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881C5D8: toggle a flag on with pad bits 0x60, off with 0x90. */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62D8C;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

u8 func_0881C5D8(u8 flag, s32 pad)
{
    if (flag == 0) {
        if ((u16)pad & 0x60) {
            flag = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if ((u16)pad & 0x90) {
        flag = 0;
        func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
    }
    return flag;
}
