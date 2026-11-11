/* unit_088BA2A0: 0x088BA2A0-0x088BA2E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_0880C464(char *, s32, s32);
extern int func_088C0198(char *);

void func_088BA2A0(char *arg0) {
    *(s32 *)(arg0 + 0x97C) = -1;
    func_0880C464(arg0 + 0x980, 0, 8);
    func_088C0198(arg0);
}
