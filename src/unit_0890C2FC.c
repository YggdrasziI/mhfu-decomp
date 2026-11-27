/* unit_0890C2FC: 0x0890C2FC-0x0890C370 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Calls each function pointer of [begin, end), then func_0890DB28(arg2, arg3).
 */

#pragma optimize_for_size off

typedef int s32;
typedef void (*Func)(void);

extern void func_0890DB28(s32, s32);

void func_0890C2FC(Func *begin, Func *end, s32 arg2, s32 arg3) {
    Func *p;

    for (p = begin; p < end; p++) {
        (*p)();
    }
    func_0890DB28(arg2, arg3);
}
