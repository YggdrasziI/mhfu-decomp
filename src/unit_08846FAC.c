/* unit_08846FAC: 0x08846FAC-0x0884706C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u16 D_0893B6E4;
extern u16 D_0893B6E6;
extern u16 D_0893B6E8;
extern u16 D_0893B6EA;
extern u16 D_0893B6EC;
extern u16 D_0893B6EE;
extern u16 D_0893B6F0;

extern void func_08847418(char *, u16, u16, u16, u16);
extern s32 func_0882A9DC(char *, u16, u16, s32);

void func_08846FAC(char *arg0)
{
    u16 y;

    if (*(s32 *)(arg0 + 0x528) & 2) {
        func_08847418(arg0, D_0893B6E4, D_0893B6E6, D_0893B6E8, D_0893B6EA);
        y = D_0893B6EE;
        if (*(u8 *)(*(char **)(arg0 + 0x530) + 0x674) & 0x10) {
            y += 2;
        }
        func_0882A9DC(arg0, D_0893B6EC, y, 0x34);
        y = D_0893B6F0;
        if (*(u8 *)(*(char **)(arg0 + 0x530) + 0x674) & 8) {
            y += 2;
        }
        func_0882A9DC(arg0, D_0893B6EC, y, 0x33);
    }
}
