/* unit_088B4858: 0x088B4858-0x088B48A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A28B98;
extern int func_0880C464(char *, s32, s32);
extern int func_088B7078(s32, s32, s32);
extern int func_088B7A50(s32);

void func_088B4858(s32 arg0) {
    func_088B7A50(0);
    func_0880C464(&D_09A28B98, 0, 0x64);
    func_088B7078(arg0, 0, 0);
}
