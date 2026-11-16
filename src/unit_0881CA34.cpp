/* unit_0881CA34: 0x0881CA34-0x0881CAC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern s32 func_0881ECDC(s32);
extern s32 func_08829674(s32);

s32 func_0881CA34(s32 arg0) {
    s8 var_v0;

    if (((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0)) {
        func_08829674(arg0);
    }
    func_0881ECDC(arg0);
    *(s8 *)(arg0 + 0x57F) = 0;
    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0) {
        var_v0 = 4;
    } else {
        var_v0 = 3;
    }
    *(s8 *)(arg0 + 0x581) = var_v0;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~4);
    return 0;
}

}
