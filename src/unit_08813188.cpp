/* unit_08813188: 0x08813188-0x088131B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++ (notes/COMPILER.md).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_089CC438;

void func_08813188(char *arg0, char *arg1) {
    if ((*(u16 *)(arg1 + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) == 1) {
        *(s8 *)(arg0 + 0xA81) = 1;
    }
}

}
