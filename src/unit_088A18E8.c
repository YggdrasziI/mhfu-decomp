/* unit_088A18E8: 0x088A18E8-0x088A1914 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0DA70;

s32 func_088A18E8(s32 arg0) {
    s32 old = D_09A0DA70;

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 0x7F) {
        arg0 = 0x7F;
    }
    D_09A0DA70 = arg0;
    return old;
}
