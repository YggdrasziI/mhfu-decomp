/* unit_08813498: 0x08813498-0x088134C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++ (bool return).
 */

typedef unsigned char u8;
typedef int s32;

extern "C" {

bool func_08813498(char *arg0) {
    u8 k = *(u8 *)(arg0 + 0x810);
    return k == 1 || k == 2;
}

}
