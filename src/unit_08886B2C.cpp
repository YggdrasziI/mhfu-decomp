/* unit_08886B2C: 0x08886B2C-0x08886B68 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef struct P180 { char pad[0x180]; void (P180::*pmf)(); } P180;

extern "C" {

void func_08886B2C(P180 *arg0) {
    if (arg0->pmf) {
        (arg0->*arg0->pmf)();
    }
}

}
