/* unit_08814080: 0x08814080-0x088140C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

s8 func_08814080(char *arg0, u8 *arg1, u8 *arg2, f32 *arg3) {
    f32 temp_f1;
    char *temp_t0;
    char *temp_v1;

    temp_t0 = arg0 + 0x590;
    *arg1 = *(u8 *)(arg0 + 0x699);
    *arg2 = *(u8 *)(arg0 + 0x69A);
    temp_v1 = temp_t0 + 0xA0;
    if (*(u8 *)(arg0 + 0x69A) != 0) {
        temp_f1 = *(f32 *)(temp_t0 + 0x88) - *(f32 *)(temp_v1 + 0x50);
        *arg3 = temp_f1;
        *arg3 = temp_f1 * *(f32 *)(temp_v1 + 0x58);
    }
    return *(s8 *)(temp_v1 + 0x68);
}
