/* unit_088B1C28: 0x088B1C28-0x088B1C34 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern void func_088B7078(char *, s32, s32);

void func_088B1C28(char *arg0) {
    func_088B7078(arg0, 0xffff, *(u16 *)(arg0 + 0x26));
}
