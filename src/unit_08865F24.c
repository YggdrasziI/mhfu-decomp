/* unit_08865F24: 0x08865F24-0x08865F68 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef float f32;

extern void *func_0886421C(void *, int);

void func_08865F24(s32 arg0, char *arg1, s16 arg2) {
    char *temp_v0;

    temp_v0 = func_0886421C((void *) (arg0 + 0x80), (s32) arg2);
    *(f32 *)arg1 = *(f32 *)(temp_v0 + 0x100);
    *(f32 *)(arg1 + 4) = *(f32 *)(temp_v0 + 0x104);
    *(f32 *)(arg1 + 8) = *(f32 *)(temp_v0 + 0x108);
}
