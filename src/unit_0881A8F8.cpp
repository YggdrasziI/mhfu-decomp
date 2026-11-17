/* unit_0881A8F8: 0x0881A8F8-0x0881A9D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0881A8E0 and code still in
 * assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 *
 * C++: bool test.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

extern "C" {

extern char D_08938588;
extern char *D_089CC438;
extern s32 D_08A62C7C;
extern s32 D_08A631A8;

extern char *func_088298E4(s32);
extern s32 func_0886A35C(s32, s32);
extern void func_08891474(s32, s32, s32, char *, ...);

void func_0881A8F8(s32 arg0, s32 arg1, s32 arg2, u8 arg3) {
    s32 t;
    s32 m;
    s32 h;

    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 1 && arg3 == 1) {
        t = *(s32 *)(func_088298E4(arg0) + 0x10);
    } else {
        t = func_0886A35C(D_08A62C7C, arg3);
    }
    m = t / 30;
    h = m / 60;
    func_08891474(D_08A631A8, arg1, arg2, &D_08938588, h, m - h * 60);
}

}