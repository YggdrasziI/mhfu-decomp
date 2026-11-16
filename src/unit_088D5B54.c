/* unit_088D5B54: 0x088D5B54-0x088D5BD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x08932418-0x08932444) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

s32 func_088D286C(char *arg0);

void func_088D5B54(u8 *arg0) {
    arg0[0x7F0] = arg0[0x612];
    arg0[0x612] = 0;
    switch (arg0[0x1E8]) {
    case 1:
    case 5:
        if (arg0[0x1E8] == 1 && (u8) func_088D286C((char *) arg0) == 1) {
            arg0[0x612] = 4;
        }
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    }
}
