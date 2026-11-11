/* unit_088B455C: 0x088B455C-0x088B45B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_09A28870;
extern s8 D_09A28877;
extern char D_09A2887C;
extern int func_088B7078(s32, s32, s32);
extern int func_088B7860(char *);
extern int func_088B7A50(s32);

void func_088B455C(s32 arg0) {
    func_088B7A50(2);
    func_088B7860(&D_09A2887C);
    D_09A28870 = 0;
    D_09A28877 = 0;
    func_088B7078(arg0, 0, 0);
}
