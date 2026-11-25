/* unit_0885FB54: 0x0885FB54-0x0885FBB4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885FB54: looks up an entry with func_0885F928(arg0, arg0, arg1) and,
 * when found, passes it, the float, arg1 and arg2 to func_0885FA0C.
 * The float must come right after the entry in the callee prototype: as the
 * last parameter, the mov.s to $f12 moves after the a1/a2 copies.
 */

typedef int s32;
typedef float f32;

extern int func_0885F928(int a, int b, int c);
extern void func_0885FA0C(s32 a, f32 f, s32 b, s32 c);

void func_0885FB54(s32 arg0, s32 arg1, s32 arg2, f32 f) {
    s32 e = func_0885F928(arg0, arg0, arg1);
    if (e != 0) {
        func_0885FA0C(e, f, arg1, arg2);
    }
}
