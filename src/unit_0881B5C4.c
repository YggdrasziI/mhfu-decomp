/* unit_0881B5C4: 0x0881B5C4-0x0881B5F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881B5C4: calls func_0881B5F8 with a zeroed 6-byte buffer. */

typedef int s32;
typedef unsigned char u8;

extern void func_0881B5F8(char *, char *, s32, s32, u8 *);

void func_0881B5C4(char *arg0, char *arg1, s32 arg2, s32 arg3)
{
    u8 buf[6];

    buf[5] = 0;
    buf[4] = 0;
    buf[3] = 0;
    buf[2] = 0;
    buf[1] = 0;
    buf[0] = 0;
    func_0881B5F8(arg0, arg1, arg2, arg3, buf);
}
