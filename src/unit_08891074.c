/* unit_08891074: 0x08891074-0x088911A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;

extern char D_089AD270[];
extern char D_089AD26C[];

extern s32 func_08890ED4(s32 arg0, char *arg1);
extern char *func_0880F394(char *arg0, char *arg1);
extern char *func_08894B0C(s32 arg0, char *arg1, s16 *arg2, s32 arg3, s32 arg4);

s32 func_08891074(s32 arg0, char *arg1) {
    s32 total;
    char *end;
    char *p;
    s32 flag;
    s16 code;

    p = arg1;
    flag = 0;
    total = func_08890ED4(arg0, arg1);
    while (*p != 0 && *p != 10) {
        end = func_0880F394(p, D_089AD270);
        p = func_0880F394(p, D_089AD26C);
        if (p == 0) {
            goto ret;
        }
        if (p >= end) {
            break;
        }
        func_08894B0C(arg0, p, &code, 0, 1);
        if ((code & 0xFF00) == 0x800) {
            flag ^= 1;
            p = func_08894B0C(arg0, p, &code, 1, 1);
            total += code;
        } else if (flag == 0) {
            p = func_08894B0C(arg0, p, &code, 1, 1);
            total += code;
        } else {
            p++;
        }
    }
ret:
    return total;
}
