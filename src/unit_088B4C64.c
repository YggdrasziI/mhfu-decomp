/* unit_088B4C64: 0x088B4C64-0x088B4CA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A29CD8;
extern int func_088AFE84(void);
extern int func_088B6458(char *, s32);
extern int func_088B65FC(char *);
extern int func_088B6B14(s32);

void func_088B4C64(void) {
    func_088B6458(&D_09A29CD8, func_088AFE84());
    func_088B65FC(&D_09A29CD8);
    func_088B6B14(0xC);
}
