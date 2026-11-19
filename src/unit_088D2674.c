/* unit_088D2674: 0x088D2674-0x088D27BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088D27BC. Its jump table (0x089323C8-0x089323EC) is linked from this
 * unit.
 */

typedef int s32;
typedef short s16;

extern s32 func_08864348(float, char *, s32);
extern void func_09C6EF18(char *, s32, s32);

void func_088D2674(char *arg0, float frame, s32 arg1, s32 arg2) {
    if (func_08864348(frame, arg0 + 0x80, 0) == 0) {
        return;
    }
    switch ((s16) arg2) {
    case 0:
        func_09C6EF18(arg0, arg1, 0);
        break;
    case 1:
        func_09C6EF18(arg0, arg1, 3);
        break;
    case 2:
        func_09C6EF18(arg0, 5, 4);
        break;
    case 3:
        func_09C6EF18(arg0, arg1, 4);
        break;
    case 4:
        func_09C6EF18(arg0, arg1, 5);
        break;
    case 5:
        func_09C6EF18(arg0, arg1, 6);
        break;
    case 6:
        func_09C6EF18(arg0, arg1, 7);
        break;
    case 7:
        func_09C6EF18(arg0, arg1, 8);
        break;
    case 8:
        func_09C6EF18(arg0, arg1, 20);
        break;
    }
}
