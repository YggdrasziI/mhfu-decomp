/* unit_08828658: 0x08828658-0x088286E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, func_08828534 before it and func_088286E4 after it are
 * still in assembly.
 * Its jump table (0x08930AF8-0x08930B10) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

extern u8 func_088D6AC8(int a, int b);

s32 func_08828658(s32 arg0, s32 arg1) {
    u8 v = func_088D6AC8(arg1, 9);

    if (v != 0) {
        switch (v) {
        case 17:
            return 20;
        case 18:
            return 30;
        case 19:
            return 50;
        case 20:
            return -10;
        case 21:
            return -20;
        case 22:
            return -30;
        }
    }
    return 0;
}
