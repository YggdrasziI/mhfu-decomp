/* unit_088C3460: 0x088C3460-0x088C349C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef struct P1C { char pad[0x1C]; void (P1C::*pmf)(); } P1C;

extern "C" {

void func_088C3460(P1C *arg0) {
    if (arg0->pmf) {
        (arg0->*arg0->pmf)();
    }
}

}
