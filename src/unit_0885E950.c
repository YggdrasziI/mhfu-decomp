/* unit_0885E950: 0x0885E950-0x0885E988 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_0885E950: stores arg2 into the first zero u16 of the three at
 * arg1 + 6.
 */

typedef unsigned short u16;
typedef int s32;

typedef struct {
    char pad[6];
    u16 slot[3];
} S6;

void func_0885E950(s32 arg0, S6 *arg1, u16 arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg1->slot[i] == 0) {
            arg1->slot[i] = arg2;
            return;
        }
    }
}
