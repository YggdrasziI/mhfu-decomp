/* unit_08814048: 0x08814048-0x08814080 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned char u8;
typedef int s32;

extern "C" {

s32 func_08814048(char *arg0, char *arg1) {
    if (*(u8 *)(arg0 + 0x961) != 0) {
        return 0;
    }
    if ((*(u8 *)(arg1 + 0x564) != 0) == 1) {
        return 1;
    }
    return *(u8 *)(arg0 + 0x621) != 0;
}

}
