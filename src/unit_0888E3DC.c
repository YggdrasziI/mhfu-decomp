/* unit_0888E3DC: 0x0888E3DC-0x0888E494 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern float func_08897D4C(float, float);

float func_0888E3DC(char *arg0) {
    float r;
    float t = (float)*(s16 *)(arg0 + 0x94) * *(float *)(arg0 + 0x190);

    if (t < 0.5f) {
        r = 0.5f * func_08897D4C(2.0f * t, 2.0f);
    } else {
        r = 1.0f - 0.5f * func_08897D4C(2.0f * (1.0f - t), 2.0f);
    }
    if (--*(s16 *)(arg0 + 0x94) == 0) {
        *(u8 *)(arg0 + 0x9C) = 0;
    }
    return r;
}
