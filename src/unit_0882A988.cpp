/* unit_0882A988: 0x0882A988-0x0882A9DC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned char u8;
typedef int s32;

extern "C" {

extern s32 func_0883BA38(s32, s32);
extern s32 func_08848D30(s32);

void func_0882A988(char *arg0, s32 arg1) {
    if ((*(u8 *)((*(char **)(arg0 + 0x530)) + 0x1E0) != 0) == 1) {
        func_08848D30((s32) arg0);
    }
    func_0883BA38((s32) arg0, arg1);
}

}
