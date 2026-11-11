/* unit_08859174: 0x08859174-0x08859188 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_08804678(s32, char *, s32);
extern char func_08859188;

void func_08859174(void) {
    func_08804678(0, &func_08859188, 0);
}
