/* unit_088298E4: 0x088298E4-0x08829928 (ULES01213)
 *
 * Bounds (hypothesis): 1 pointer chosen by a bool flag, between unrelated code.
 *
 * C++: the code only matches when compiled as C++ (notes/COMPILER.md).
 */

typedef unsigned int u32;

extern "C" {

extern char *D_089CC438;
extern char *D_08A62C7C;
extern char D_09B03F40[];

char *func_088298E4(void) {
    if ((bool)(*(u32 *)(D_089CC438 + 0x6AF14) & 1) == true) {
        return D_09B03F40;
    }
    return *(char **)(D_08A62C7C + 0x68);
}

}
