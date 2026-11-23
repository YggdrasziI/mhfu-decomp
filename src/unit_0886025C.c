/* unit_0886025C: 0x0886025C-0x08860328 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern f32 func_0886364C(char *arg0, char *arg1);

f32 func_0886025C(char *arg0, char *arg1) {
    f32 max = 0.0f;
    char *p;
    char *q;
    u32 i;
    u32 j;
    f32 v;
    p = arg1 + 0x14;
    for (i = 0; i < *(u32 *)(arg1 + 4); i++) {
        q = p + 0xC;
        for (j = 0; j < *(u32 *)(p + 4); j++) {
            v = func_0886364C(arg0 + 0x150, q);
            if (v > max) {
                max = v;
            }
            q += *(s32 *)(q + 8);
        }
        p += *(s32 *)(p + 8);
    }
    return max;
}
