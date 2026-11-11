/* unit_0881A8E0: 0x0881A8E0-0x0881A8F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_08938584;
extern s32 D_08A631A8;
extern void func_08891474(s32, s32, s32, char *, s32, s32, s32, s32);

void func_0881A8E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    func_08891474(D_08A631A8, arg1, arg2, &D_08938584, arg3, arg5, arg6, arg7);
}
