/* unit_08815348: 0x08815348-0x08815384 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef float f32;

extern int func_088145C4(char *, f32, f32, f32, f32);

void func_08815348(char *arg0) {
    func_088145C4(arg0, *(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 8), *(f32 *)arg0, *(f32 *)(arg0 + 4));
    *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 0xC);
}
