/* unit_088A18B8: 0x088A18B8-0x088A18E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0D250;
extern char D_09A0D260;
extern int func_0880C464(char *, s32, s32);

void func_088A18B8(void) {
    func_0880C464(&D_09A0D260, 0, 0x810);
    D_09A0D250 = 0;
}
