/* unit_088B48A4: 0x088B48A4-0x088B48DC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern int func_088B7078(char *, s32, u16);
extern int func_088B7A50(s32);

void func_088B48A4(char *arg0) {
    func_088B7A50(2);
    func_088B7078(arg0, 0xFFFF, *(u16 *)(arg0 + 0x26));
}
