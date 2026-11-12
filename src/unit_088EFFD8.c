/* unit_088EFFD8: 0x088EFFD8-0x088F0018 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern int func_0880C464(void *, s32, s32);

void func_088EFFD8(char *arg0) {
    func_0880C464(arg0 + 0x188, 0, 0xA5A0);
    *(s8 *)(arg0 + 0xA728) = 0;
    *(s8 *)arg0 = 0;
}
