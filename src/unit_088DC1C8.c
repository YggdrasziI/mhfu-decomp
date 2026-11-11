/* unit_088DC1C8: 0x088DC1C8-0x088DC1F0 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_09A4F0D0;
extern void func_088DDBD8(s32, s32, s32, s32);
extern void func_088DDF50(s32, s32);

void func_088DC1C8(void) {
    func_088DDBD8(D_09A4F0D0, 8, 0x1517, 0);
}

void func_088DC1E0(void) {
    func_088DDF50(D_09A4F0D0, 8);
}
