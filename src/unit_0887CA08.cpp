/* unit_0887CA08: 0x0887CA08-0x0887CA4C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned char u8;
typedef int s32;

extern "C" {

extern char *D_08A631A0;
extern char *D_09A0B544;

s32 func_0887CA08(void) {
    if ((bool) (*(s32 *)((char *)D_08A631A0 + 0xF7A57C) & 1) == 0) {
        return 1;
    }
    return *(u8 *)(D_09A0B544 + 0x12D6) == 1;
}

}
