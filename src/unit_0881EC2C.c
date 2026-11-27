/* unit_0881EC2C: 0x0881EC2C-0x0881ECDC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern void func_0881C2E4(char *, u8 *, s32, u8);
extern char *func_0881ED64(char *, char *, u8, s32);
extern u8 func_088303E8(char *, char *, s32, char *);
extern void func_0881C45C(char *, u8 *, s32, u8);

s32 func_0881EC2C(char *arg0, s32 arg1)
{
    s32 s2 = *(s32 *)(arg0 + 0x530);
    char buf[12];

    func_0881C2E4(arg0, (u8 *)(arg0 + 0x57F), arg1, 6);
    if (func_0881ED64(arg0, buf, *(u8 *)(arg0 + 0x57F), s2) != 0) {
        *(u8 *)(arg0 + 0x583) = func_088303E8(arg0, buf, 0x100, 0);
        if (*(u8 *)(arg0 + 0x582) >= *(u8 *)(arg0 + 0x583)) {
            *(u8 *)(arg0 + 0x582) = *(u8 *)(arg0 + 0x583) - 1;
        }
        func_0881C45C(arg0, (u8 *)(arg0 + 0x582), arg1, *(u8 *)(arg0 + 0x583));
    }
    return arg1;
}
