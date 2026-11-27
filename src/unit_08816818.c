/* unit_08816818: 0x08816818-0x08816900 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_08816818: find a 16-bit string inside another (wide strstr). */

typedef int s32;
typedef unsigned short u16;

extern s32 D_089CBBE8;
extern s32 func_088167F4(s32, u16 *);
extern s32 func_0880BFF0(void *, void *, s32);

u16 *func_08816818(s32 arg0, volatile u16 *arg1, u16 *arg2) {
    u16 *found;
    s32 n;
    s32 m;

    found = 0;
    n = func_088167F4(D_089CBBE8, (u16 *)arg1);
    m = func_088167F4(D_089CBBE8, arg2);
    if (n >= m) {
        while (*arg1 != 0) {
            if (*arg1 == *arg2) {
                if (n < m) {
                    break;
                }
                if (func_0880BFF0((u16 *)arg1, arg2, m * 2) == 0) {
                    found = (u16 *)arg1;
                    break;
                }
                n--;
                arg1++;
            } else {
                n--;
                arg1++;
            }
        }
    }
    return found;
}
