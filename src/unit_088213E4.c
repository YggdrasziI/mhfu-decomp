/* unit_088213E4: 0x088213E4-0x0882148C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Moves a level (0...6) up or down by one from the func_088D6A1C states.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_088D6A1C(char *, u8);

s32 func_088213E4(s32 arg0, char *arg1, s32 arg2) {
    if ((u8) func_088D6A1C(arg1, 0x1D) == 1 || (u8) func_088D6A1C(arg1, 0xD1) == 1) {
        arg2++;
        if (arg2 >= 7) {
            arg2 = 6;
        }
    } else if ((u8) func_088D6A1C(arg1, 0x1E) == 1) {
        arg2--;
        if (arg2 < 0) {
            arg2 = 0;
        }
    }
    return arg2;
}
