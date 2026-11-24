/* unit_0885BD0C: 0x0885BD0C-0x0885BDAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885BD0C */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;

extern char *D_089CC438;

extern s16 func_08850EC4(char *arg0);

u16 func_0885BD0C(s32 arg0, u16 arg1) {
    char *p = D_089CC438 + 0x4A0;
    s32 i;

    if (arg1 != 0xFFFF) {
        for (i = 0; i < func_08850EC4(D_089CC438); p += 4, i++) {
            if (*(u16 *)(p + 0x2F88) == arg1 && *(s16 *)(p + 0x2F8A) > 0) {
                return i;
            }
        }
    }
    return 0xFFFF;
}
