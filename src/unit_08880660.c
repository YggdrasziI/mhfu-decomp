/* unit_08880660: 0x08880660-0x08880708 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_08A62D84;
extern s32 D_08A62D94;
extern void func_0887F848(s32, char *, s32);
extern void func_0888640C(s32);
extern void func_088832B4(char *, s32, s32);
extern void func_08882A74(char *, s32, s32);

void func_08880660(char *arg0) {
    if (*(u8 *)(arg0 + 0x562421) != 0 && *(u8 *)(arg0 + 0x562420) != 1) {
        func_0887F848(D_08A62D84, arg0 + 0x308BD0, *(s32 *)(arg0 + 0x308BC4));
        func_0888640C(D_08A62D94);
        func_088832B4(arg0, 0, 1);
        func_08882A74(arg0, 0, 0);
        *(u8 *)(arg0 + 0x562420) = 1;
    }
}
