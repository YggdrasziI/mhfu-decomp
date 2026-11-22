/* unit_08890F70: 0x08890F70-0x08891074 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;

extern char D_089AD26C;

extern s32 func_08890E48(char *, char *);
extern char *func_0880F394(char *, char *);
extern char *func_08894B0C(char *, char *, s16 *, s32, s32);

s32 func_08890F70(char *arg0, void *arg1) {
    s32 total;
    char *str = (char *) arg1;
    s32 flag;
    s16 w;

    flag = 0;
    total = func_08890E48(arg0, (char *) arg1);
    if (*str != 0) {
        do {
            str = func_0880F394(str, &D_089AD26C);
            if (str == 0) {
                break;
            }
            func_08894B0C(arg0, str, &w, 0, 1);
            if ((w & 0xFF00) == 0x800) {
                flag ^= 1;
                str = func_08894B0C(arg0, str, &w, 1, 1);
                total += w;
            } else if (flag == 0) {
                str = func_08894B0C(arg0, str, &w, 1, 1);
                total += w;
            } else {
                str++;
            }
        } while (*str != 0);
    }
    return total;
}
