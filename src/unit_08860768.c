/* unit_08860768: 0x08860768-0x088607A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char *D_08A62C58;
extern int func_0880C464(void *, s32, s32);

char *func_08860768(char *arg0) {
    D_08A62C58 = arg0;
    func_0880C464(arg0, 0, 0x150);
    *(u16 *)(arg0 + 0x15C) = 0xFFFF;
    return arg0;
}
