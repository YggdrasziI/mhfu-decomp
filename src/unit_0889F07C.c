/* unit_0889F07C: 0x0889F07C-0x0889F0D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B5BC;
extern s32 D_09A0B5C0;
extern s32 D_09A0B5C4;
extern s32 D_09A0B5C8;
extern char *D_09A0B5CC;
extern char D_09A0B5D0;
extern int func_0880C464(char *, s32, s32);

void func_0889F07C(void) {
    func_0880C464(&D_09A0B5D0, 0, 0x1000);
    D_09A0B5BC = 0;
    D_09A0B5C0 = 0;
    D_09A0B5C4 = 0;
    D_09A0B5C8 = 0x40;
    D_09A0B5CC = &D_09A0B5D0;
}
