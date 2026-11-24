/* unit_088530C4: 0x088530C4-0x0885320C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
/* func_088530C4 */

typedef int s32;
typedef unsigned short u16;

extern s32 D_089CBBE8;
extern s32 func_088167F4(s32, char *);
extern void func_088538B4(char *, char *, char *, s32);
extern s32 func_0885168C(char *, s32);
extern s32 func_08851698(char *, s32);
extern void func_08816730(s32, char *, s32, s32);
extern s32 func_0885320C(char *, char *, char *, char *, s32, s32);

s32 func_088530C4(char *arg0, char *arg1, s32 arg2) {
    char bufA0[0x200];
    char buf20[0x80];
    s32 sum;
    u16 i;
    s32 e;

    sum = 0;
    func_088538B4(arg0, bufA0, arg1, func_088167F4(D_089CBBE8, arg1));
    for (i = 0; (e = func_0885168C(arg0, i)) != 0; i++) {
        func_08816730(D_089CBBE8, buf20, 0x40, e);
        sum += func_0885320C(arg0, bufA0, arg1, buf20, arg2, 2);
    }
    for (i = 0; (e = func_08851698(arg0, i)) != 0; i++) {
        func_08816730(D_089CBBE8, buf20, 0x40, e);
        sum += func_0885320C(arg0, bufA0, arg1, buf20, arg2, 2);
    }
    return sum != 0;
}
