/* unit_08812F18: 0x08812F18-0x08812F64 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

extern char D_08933A98;

void func_08812F18(char *arg0, s32 arg1, char *arg2) {
    *(s8 *)(arg0 + 0xAC0) = 1;
    *(s8 *)(arg0 + 0xAC1) = arg1;
    *(s16 *)(arg0 + 0xAC2) = (s16) ((s16 *)&D_08933A98)[arg1];
    *(f32 *)(arg0 + 0xAB0) = *(f32 *)arg2;
    *(f32 *)(arg0 + 0xAB4) = *(f32 *)(arg2 + 4);
    *(f32 *)(arg0 + 0xAB8) = *(f32 *)(arg2 + 8);
    *(f32 *)(arg0 + 0xABC) = *(f32 *)(arg2 + 0xC);
    *(s8 *)(arg0 + 0xAC4) = 0;
}
