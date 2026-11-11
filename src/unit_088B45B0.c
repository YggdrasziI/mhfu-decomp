/* unit_088B45B0: 0x088B45B0-0x088B45FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char D_09A28B98;
extern int func_0880C464(char *, s32, s32);
extern int func_088B7078(char *, s32, u16);
extern int func_088B7A50(s32);

void func_088B45B0(char *arg0) {
    func_088B7A50(0);
    func_0880C464(&D_09A28B98, 0, 0x64);
    func_088B7078(arg0, 0xFFFF, *(u16 *)(arg0 + 0x26));
}
