/* unit_088DD3A8: 0x088DD3A8-0x088DD3E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef struct P3FC { char pad[0x3FC]; void (P3FC::*pmf)(); } P3FC;

extern "C" {

void func_088DD3A8(P3FC *arg0) {
    if (arg0->pmf) {
        (arg0->*arg0->pmf)();
    }
}

}
