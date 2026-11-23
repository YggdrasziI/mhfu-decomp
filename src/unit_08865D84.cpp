/* unit_08865D84: 0x08865D84-0x08865DBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* unit_08865D84: 0x08865D84-0x08865DBC (ULES01213)
 *
 * C++: the member at 0x3FC is a pointer to member function cleared with 0
 * (copied from __ptmf_null).
 */

extern "C" {
typedef int s32;
}
struct C { void m(); };
typedef void (C::*PMF)();
extern "C" {

void func_08865D84(char *arg0) {
    *(s32 *)(arg0 + 4) &= ~1;
    *(PMF *)(arg0 + 0x3FC) = 0;
}

}
