/* unit_0885A8F0: 0x0885A8F0-0x0885A934 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern s32 D_089CBBEC;
extern int func_08859C40(s32, s32);

void func_0885A8F0(char *arg0) {
    *(s8 *)arg0 = 0;
    *(s8 *)(arg0 + 3) = 0;
    *(s8 *)(arg0 + 2) = 0;
    if (*(u8 *)(arg0 + 1) == 6) {
        func_08859C40(D_089CBBEC + 0x500, *(s32 *)(arg0 + 0x20));
    }
}
