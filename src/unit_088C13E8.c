/* unit_088C13E8: 0x088C13E8-0x088C1430 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_09A4F0D0;
extern int func_08852A50(s32);
extern int func_088DB4D4(s32);
extern int func_088DBB5C(s32);
extern int func_088DDF50(s32, s32);

void func_088C13E8(void) {
    func_088DB4D4(D_09A4F0C4);
    func_088DBB5C(D_09A4F0C4);
    func_088DDF50(D_09A4F0D0, 7);
    func_08852A50(D_089CC438);
}
