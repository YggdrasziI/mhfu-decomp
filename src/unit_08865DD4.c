/* unit_08865DD4: 0x08865DD4-0x08865E40 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef int s32;

s32 func_08865DD4(char *arg0, s16 arg1) {
    float v;
    float f;
    s16 n;

    f = *(float *)(arg0 + 0x244);
    v = -1.0f * f;
    n = arg1 / 2;
    if (n <= 1 || f < 0.0f) {
        *(float *)(arg0 + 0x254) = v;
        return 0;
    }
    *(float *)(arg0 + 0x254) = v / (float)n;
    return 1;
}
