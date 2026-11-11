/* unit_088A7368: 0x088A7368-0x088A7378 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern void func_088AA054(s32, s32, s32, s32);
extern void func_088AA0BC(s32, s32, s32);

void func_088A7368(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_088AA054(arg0, arg1, arg2, arg3);
}

void func_088A7370(s32 arg0, s32 arg1, s32 arg2) {
    func_088AA0BC(arg0, arg1, arg2);
}
