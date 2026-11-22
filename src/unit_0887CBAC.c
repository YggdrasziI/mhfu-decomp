/* unit_0887CBAC: 0x0887CBAC-0x0887CC28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_0887CC28. Its initialised array (0x089A8968-0x089A898A, in .data) is
 * linked from this unit.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;

extern u16 func_0884FF4C(char *, u8);

s32 func_0887CBAC(char *unused) {
    s16 ids[17] = {0x25, 0x26, 0x27, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x31, 0x32, 0x54, 0x55, 0x56, 0x57, -1};
    s16 *p = ids;

    while (1) {
        if (*p == -1) {
            return 1;
        }
        if (func_0884FF4C(D_089CC438, *p) == 0) {
            return 0;
        }
        p++;
    }
}