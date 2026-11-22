/* unit_0888AF68: 0x0888AF68-0x0888AFEC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern float func_08897D4C(float, float);

float func_0888AF68(s32 arg0, s32 arg1, s32 arg2, u8 arg3) {
    float t = 1.0f / (float)arg2 * (float)arg1;

    switch (arg3) {
    case 1:
        t = 1.0f - func_08897D4C(1.0f - t, 2.25f);
        break;
    case 2:
        t = func_08897D4C(t, 2.25f);
        break;
    }
    return t;
}
