/* unit_088B2024: 0x088B2024-0x088B2058 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A299A8;
extern int func_088AFE84(void);
extern int func_088B03BC(char *, s32);
extern int func_088B6B14(s32);

void func_088B2024(void) {
    func_088B03BC(&D_09A299A8, func_088AFE84());
    func_088B6B14(0);
}
