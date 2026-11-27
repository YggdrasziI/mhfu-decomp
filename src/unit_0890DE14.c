/* unit_0890DE14: 0x0890DE14-0x0890DE38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890DE14: tail call to func_0890C2FC with the addresses of
 * D_089BAA50, D_089BAA6C and D_089CBA70 (twice).
 *
 * `opt_common_subs off` keeps the two D_089CBA70 addresses as separate
 * lui/addiu pairs (otherwise a3 is a copy of a2). Derived from the assembly only.
 */

typedef int s32;
typedef void (*Func)(void);

extern Func D_089BAA50[];
extern Func D_089BAA6C[];
extern s32 D_089CBA70[];

extern void func_0890C2FC(Func *begin, Func *end, s32 *arg2, s32 *arg3);

#pragma opt_common_subs off
void func_0890DE14(void) {
    func_0890C2FC(D_089BAA50, D_089BAA6C, D_089CBA70, D_089CBA70);
}
