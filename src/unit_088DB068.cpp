/* unit_088DB068: 0x088DB068-0x088DB0A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef struct P0 { void (P0::*pmf)(); } P0;

extern "C" {

void func_088DB068(P0 *arg0) {
    if (arg0->pmf) {
        (arg0->*arg0->pmf)();
    }
}

}
