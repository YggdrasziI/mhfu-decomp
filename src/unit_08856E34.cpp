/* unit_08856E34: 0x08856E34-0x08856E8C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef int s32;

extern "C" {

extern char *D_089CC438;

s32 func_08856E34(void) {
    s32 temp_v1;

    temp_v1 = *(s32 *)(D_089CC438 + 0x6AF14);
    if (((bool) (temp_v1 & 1) == 0) && ((bool) (temp_v1 & 0x20) == 0) && ((bool) (temp_v1 & 8) == 0)) {
        return 1;
    }
    return 0;
}

}
