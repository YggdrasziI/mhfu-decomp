/* unit_0882A864: 0x0882A864-0x0882A8B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 state test, between unrelated code.
 */

typedef signed short s16;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;

s32 func_0882A864(char *a, char *b) {
    if (b != 0 && (s32)(*(u16 *)(b + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) == 0) {
        return 0;
    }
    if (*(u8 *)(a + 0x52F) != 0) {
        return 0;
    }
    return *(s16 *)(a + 0x119E) <= 0;
}
