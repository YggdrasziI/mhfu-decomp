/* unit_0885FF5C: 0x0885FF5C-0x0885FFBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885FF5C: looks up an entry with func_0885F928(arg0, arg0, arg1) and,
 * when found, passes it with the two float arguments and arg1 to
 * func_0885FC9C. The callee takes the floats BEFORE the integer: with
 * (e, arg1, f, f) the call loads a1 first and the `jal` slot stays empty.
 */

typedef int s32;
typedef float f32;

extern int func_0885F928(int, int, int);
extern void func_0885FC9C(s32 arg0, f32 arg2, f32 arg3, s32 arg1);

void func_0885FF5C(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 e;

    e = func_0885F928(arg0, arg0, arg1);
    if (e != 0) {
        func_0885FC9C(e, arg2, arg3, arg1);
    }
}
