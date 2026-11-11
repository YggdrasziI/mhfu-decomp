/* unit_088CB32C: 0x088CB32C-0x088CB364 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09C121B0;
extern s32 func_09AB3B88(s32, s32, s32, s32);

s32 func_088CB32C(void) {
    return (func_09AB3B88(D_09C121B0, 0x36, 0, 0) & 0xFF) == 1;
}
