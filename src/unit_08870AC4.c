/* unit_08870AC4: 0x08870AC4-0x08870AEC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_08869750(s32, s32);
extern void func_0887265C(void *, int);

void func_08870AC4(s32 arg0, s32 arg1) {
    func_0887265C((void *) (func_08869750(arg0, arg1 & 0xFFFF)), 0);
}
