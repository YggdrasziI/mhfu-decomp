/* unit_088A7DC0: 0x088A7DC0-0x088A7E44 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A0FDC8;
extern char D_09A0FDD8;
extern char D_09A0FED8;
extern char D_09A11ED8;
extern s32 D_09A11EDC;
extern char *D_09A11EE0;
extern char D_09A11EE4;
extern s32 D_09A11EE8;
extern char *D_09A11EEC;
extern int func_0880C464(char *, s32, s32);

void func_088A7DC0(void) {
    func_0880C464(&D_09A11EE4, 0, 0xC);
    func_0880C464(&D_09A11ED8, 0, 0xC);
    D_09A11EE8 = 0x2000;
    D_09A11EEC = &D_09A0FED8;
    D_09A11EDC = 0xFF;
    D_09A11EE0 = &D_09A0FDD8;
    func_0880C464(&D_09A0FDC8, 0xFF, 0x10);
}
