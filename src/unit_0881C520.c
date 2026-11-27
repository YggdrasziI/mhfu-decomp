/* unit_0881C520: 0x0881C520-0x0881C5D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881C520: toggle the byte at 0x537 on pad bits 0x60 (on) / 0x90 (off). */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62D8C;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0881C520(char *arg0, u16 a, u16 b)
{
    u16 m = a & b;

    if (*(u8 *)(arg0 + 0x537) == 0) {
        if (m & 0x60) {
            *(u8 *)(arg0 + 0x537) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (m & 0x90) {
        *(u8 *)(arg0 + 0x537) = 0;
        func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
    }
}
