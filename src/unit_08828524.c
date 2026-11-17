/* unit_08828524: 0x08828524-0x08828658 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_08828658. Its jump table (0x08930ABC-0x08930AF8) is linked from this
 * unit.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern s8 D_08978E38[][4];
extern s32 func_088D6A1C(s32, s32);

s32 func_08828524(s32 arg0, s32 arg1, u8 *arg2, u8 arg3) {
    s32 n;
    s32 i;
    s8 *p;

    n = 3;
    if (arg2[0xB] == 4) {
        n++;
    } else if (arg2[0xB] == 2) {
        if ((u8) func_088D6A1C(arg1, 0xAA) == 0) {
            n--;
        }
    } else {
        if ((u8) func_088D6A1C(arg1, 0xAA) == 1) {
            n++;
        }
    }
    i = 0;
    if (n > 0) {
        p = D_08978E38[arg2[0x10]];
        do {
            switch (*p) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                if (arg3 == 0x16) {
                    return 1;
                }
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                if (arg3 == 0x18) {
                    return 1;
                }
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                if (arg3 == 0x17) {
                    return 1;
                }
                break;
            }
            i++;
            p++;
        } while (i < n);
    }
    return 0;
}
