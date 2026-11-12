/* unit_0881C884: 0x0881C884-0x0881C944 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern s16 func_08826734(s32, s32);

s32 func_0881C884(char *arg0) {
    s8 temp_v1;

    *(s8 *)(arg0 + 0x585) = 0;
    *(u8 *)(arg0 + 0x586) = 0U;
    *(s8 *)(arg0 + 0x589) = 0;
    *(s8 *)(arg0 + 0x588) = 0;
    *(s8 *)(arg0 + 0x587) = 0;
    if (((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0)) {
        temp_v1 = *(s8 *)(arg0 + 0x587);
        if (temp_v1 == *(u8 *)(D_089CC438 + 0x28)) {
            *(s8 *)(arg0 + 0x587) = (s8) (temp_v1 + 1);
        }
    }
    *(s32 *)(arg0 + 0x528) = (s32) (*(s32 *)(arg0 + 0x528) & ~0x10);
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) | 4);
    *(s32 *)(arg0 + 0x528) = (s32) (*(s32 *)(arg0 + 0x528) | 0x100);
    *(s8 *)(arg0 + 0x5FE) = 1;
    *(s16 *)(arg0 + 0x5FC) = (s16) (func_08826734((s32) arg0, (s32) *(u8 *)(arg0 + 0x586)) + 0x18);
    *(s8 *)(arg0 + 0x5FF) = 0;
    *(s8 *)(arg0 + 0x1207) = 0;
    return 0;
}

}
