/* unit_088971A0: 0x088971A0-0x088971F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef struct P4 { char pad[0x4]; void (P4::*pmf)(); } P4;

extern "C" {

extern bool func_088971F0(P4 *);

void func_088971A0(P4 *arg0) {
    if (func_088971F0(arg0) == true) {
        if (arg0->pmf) {
            (arg0->*arg0->pmf)();
        }
    }
}

}
