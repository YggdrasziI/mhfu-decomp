/* unit_088131B8: 0x088131B8-0x088131FC (ULES01213)
 *
 * Bounds (hypothesis): 1 field update guarded by a bool comparison, between unrelated code.
 *
 * C++: the code only matches when compiled as C++ (notes/COMPILER.md).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern "C" {

extern char *D_089CC438;

void func_088131B8(char *a, char *b) {
    if ((*(u16 *)(b + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) == true) {
        *(u8 *)(a + 0x1D9) = 0;
        *(s16 *)(a + 0x1D0) = *(int *)(b + 0x1F4) + 0x2000;
        *(u8 *)(a + 0x14) = 2;
    }
}

}
