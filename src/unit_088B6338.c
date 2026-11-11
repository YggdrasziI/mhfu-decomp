/* unit_088B6338: 0x088B6338-0x088B63A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A28BEE;
extern char D_09A29174;
extern u8 D_09A2917E;
extern int func_088AFE84(void);
extern s32 func_088B0318(char *, s32);
extern int func_088B03BC(u8 *, s32);
extern int func_088B6B14(s32);
extern s32 func_088B7A10(char *);

void func_088B6338(void) {
    func_088B03BC(&D_09A2917E, func_088B0318(&D_09A29174, func_088AFE84()));
    if (func_088B7A10(&D_09A29174) == 0) {
        D_09A28BEE = D_09A2917E;
    }
    func_088B6B14(0x11);
}
