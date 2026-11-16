/* unit_0884FA5C: 0x0884FA5C-0x0884FAC4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function after unit_0884FA0C; func_0884FAC4 after it is still in
 * assembly.
 * Its jump table (0x08931374-0x0893138C) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

s32 func_0884FA5C(u8 *arg0, s32 arg1) {
    switch (arg0[0x2E]) {
    case 4:
    case 6:
    case 7:
    case 8:
        return 1;
    case 3:
        if (arg1 != 0) {
            break;
        }
        return 1;
    case 5:
        if (arg1 == 2) {
            break;
        }
        return 1;
    }
    return 0;
}
