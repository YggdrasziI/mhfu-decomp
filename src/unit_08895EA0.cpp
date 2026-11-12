/* unit_08895EA0: 0x08895EA0-0x08895F3C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern int func_088966C0(void *, s32);
extern u8 func_08896C10(s32, s32);

void func_08895EA0(char *arg0) {
    *(s8 *)(arg0 + 0x10FF) = 0;
    *(s8 *)(arg0 + 0x10FE) = 0;
    *(s8 *)(arg0 + 0x10FD) = 0;
    *(s8 *)(arg0 + 0x10FC) = 0;
    *(s8 *)(arg0 + 0x110D) = 0;
    *(s8 *)(arg0 + 0x110C) = 0;
    *(s8 *)(arg0 + 0x1115) = 0;
    *(s8 *)(arg0 + 0x1117) = 0;
    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 0x100) == 1) {
        *(u8 *)(arg0 + 0x1111) = (u8) (*(u16 *)(D_089CC438 + 0x6AF12) - 0x4E20);
        func_088966C0(arg0, 0);
    } else {
        *(u8 *)(arg0 + 0x1111) = 1U;
    }
    *(u8 *)(arg0 + 0x1114) = func_08896C10((s32) arg0, (s32) *(u8 *)(arg0 + 0x1111));
}

}
