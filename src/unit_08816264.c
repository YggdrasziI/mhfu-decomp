/* unit_08816264: 0x08816264-0x0881629C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;

void func_08816264(char *arg0) {
    f32 temp_f0;

    temp_f0 = 0.5f * *(f32 *)(arg0 + 4);
    *(s32 *)(arg0 + 0xDA0) = 0x43700000;
    *(s32 *)(arg0 + 0xDA4) = 0xC3080000;
    *(f32 *)(arg0 + 0xDA8) = temp_f0;
    *(s32 *)(arg0 + 0xDAC) = 0x45000000;
    *(s32 *)(arg0 + 0xDB0) = 0x45000000;
    *(f32 *)(arg0 + 0xDB4) = temp_f0;
}
