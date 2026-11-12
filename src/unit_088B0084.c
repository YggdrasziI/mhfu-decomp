/* unit_088B0084: 0x088B0084-0x088B00DC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern int func_0880C084(void *, void *, s32);

void func_088B0084(char *arg0, char *arg1, s32 arg2) {
    func_0880C084(arg0 + *(u16 *)(arg0 + 2) + 0x18, arg1, arg2 & 0xFFFF);
    *(u16 *)arg0 = (u16) (*(u16 *)arg0 + arg2);
    *(u16 *)(arg0 + 2) = (u16) (*(u16 *)(arg0 + 2) + arg2);
}
