/* unit_0889198C: 0x0889198C-0x08891A28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function calling the variadic func_088915B0 twice
 * with the format D_089AD274: first at (arg1 + arg6, arg2 + arg7) with arg3,
 * then at (arg1, arg2) with arg4.
 */

typedef int s32;
typedef short s16;

extern char D_089AD274[];

extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_0889198C(char *arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7) {
    func_088915B0(arg0, (s16) (arg1 + arg6), (s16) (arg2 + arg7), arg3, D_089AD274, arg5);
    func_088915B0(arg0, arg1, arg2, arg4, D_089AD274, arg5);
}
