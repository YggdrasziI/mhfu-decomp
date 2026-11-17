/* unit_0883F8B4: 0x0883F8B4-0x0883F988 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;

extern s32 D_08A62D8C;

extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0883F8B4(char *arg0) {
    s32 i = 0;
    char *p = arg0;

    do {
        s16 v = *(s16 *)(p + 0x56C);

        if (v >= 0) {
            if (v < 100 && v % 20 == 0) {
                func_08883988(D_08A62D8C, 1, v / 20 + 0x7B, 0, 0, 0, 0, 0, 0);
            }
            if (++*(s16 *)(p + 0x56C) > 0x69) {
                *(s16 *)(p + 0x56C) = -1;
            }
        }
        i++;
        p += 2;
    } while (i < 4);
}