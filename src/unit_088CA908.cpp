/* unit_088CA908: 0x088CA908-0x088CA944 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef struct P3D8 { char pad[0x3D8]; void (P3D8::*pmf)(); } P3D8;

extern "C" {

void func_088CA908(P3D8 *arg0) {
    if (arg0->pmf) {
        (arg0->*arg0->pmf)();
    }
}

}
