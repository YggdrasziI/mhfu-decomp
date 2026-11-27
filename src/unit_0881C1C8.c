/* unit_0881C1C8: 0x0881C1C8-0x0881C240 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881C1C8 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;

extern void func_0881C098(char *, u8 *, u16, s32);
extern u16 *func_08856884(char *, s32);
extern void func_0881C240(char *, u16, u16);

u16 func_0881C1C8(char *p, u8 *id, u16 flags)
{
    u16 w;

    func_0881C098(p, id, flags, 0x18);
    w = *func_08856884(D_089CC438, *id);
    *(u16 *)(p + 0x5FC) = w + 0x18;
    func_0881C240(p, w, flags & 0x8000);
    return w;
}
