/* unit_088564F8: 0x088564F8-0x08856550 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;

extern char *D_09A4F060;
extern u16 *D_09CE470C[];

s32 func_088564F8(char *arg0) {
    u16 r;
    u16 v = *(u16 *)(arg0 + 0x6AF0E);

    if (v == 0x7C) {
        r = 0x54;
    } else if (v == 0xC5) {
        r = 0x7F;
    } else {
        r = *D_09CE470C[*(s32 *)(D_09A4F060 + 0x284) * 2];
    }
    return r;
}
