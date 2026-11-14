/* unit_08813320: 0x08813320-0x08813388 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

void func_08813320(char *arg0, f32 fparg0, f32 fparg1) {
    char *temp_a3;

    *(s8 *)(arg0 + 0x7E0) = 0;
    *(s8 *)(arg0 + 0x810) = 1;
    temp_a3 = arg0 + 0x7E0;
    ((s32 *)((char *)temp_a3 + 4))[*(s32 *)(arg0 + 0x834)] = 0;
    *(s32 *)(arg0 + 0x830) = 0x3F060A92;
    ((s8 *)((char *)temp_a3 + 0x31))[*(s32 *)(arg0 + 0x834)] = 3;
    ((f32 *)((char *)temp_a3 + 0x38))[*(s32 *)(arg0 + 0x834)] = fparg0;
    ((f32 *)((char *)temp_a3 + 0x44))[*(s32 *)(arg0 + 0x834)] = fparg1;
    *(s16 *)(arg0 + 0x814) = 0xF;
}
