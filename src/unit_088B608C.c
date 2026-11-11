/* unit_088B608C: 0x088B608C-0x088B60E8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A29174;
extern char D_09A2917E;
extern int func_088AEF64(char *);
extern s32 func_088AEFE4(s32);
extern int func_088AFE84(void);
extern int func_088B03BC(char *, s32);
extern int func_088B6B14(s32);

void func_088B608C(void) {
    s32 temp_s0;

    temp_s0 = func_088AFE84();
    if (func_088AEFE4(0) == 0) {
        func_088AEF64(&D_09A29174);
        func_088B03BC(&D_09A2917E, temp_s0);
    }
    func_088B6B14(0);
}
