/* unit_0885FBB4: 0x0885FBB4-0x0885FBF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 lookup then call, between unrelated code.
 */



extern int func_0885F928(int a, int b, int c);
extern void func_0885FBF4(int a, int b);

void func_0885FBB4(int a, int b) {
    int r = func_0885F928(a, a, b);

    if (r != 0) {
        func_0885FBF4(r, b);
    }
}
