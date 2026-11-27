/* unit_0890BFA4: 0x0890BFA4-0x0890BFE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++ with an empty exception specification: the compiler emits the
 * unreachable call to __unexpected and the endless loop after it.
 */

#pragma exceptions on

typedef int s32;
extern "C" {
extern void func_0880B6E0(s32);
void func_0890BFA4(s32 arg0) throw() {
    func_0880B6E0(arg0);
}
}
