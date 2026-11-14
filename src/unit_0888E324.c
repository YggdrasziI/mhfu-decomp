/* unit_0888E324: 0x0888E324-0x0888E350 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

void func_0888E324(char *arg0, s32 arg1) {
    *(s8 *)(arg0 + 0x9C) = 1;
    *(s16 *)(arg0 + 0x94) = (s16) (arg1 - 1);
    *(f32 *)(arg0 + 0x190) = (f32) (1.0f / (f32) arg1);
}
