/* unit_088570D8: 0x088570D8-0x08857148 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern s32 func_08857058(s32, s32, s32);

s32 func_088570D8(s32 arg0, s32 arg1) {
    s32 i;

    i = 0;
    do {
        if (!(func_08857058(arg0, arg1, i) != 0) == 0) {
            return 1;
        }
        i++;
    } while (i < 5);
    return 0;
}
