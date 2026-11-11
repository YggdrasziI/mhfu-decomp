/* unit_0885683C: 0x0885683C-0x08856884 (ULES01213)
 *
 * Bounds (hypothesis): 1 state set with two calls, between unrelated code.
 */

typedef unsigned char u8;

extern void func_08882F10(int a, int b);
extern void func_08885644(int a, int b, int c);
extern int D_08A62D8C;

void func_0885683C(char *p) {
    *(u8 *)(p + 0x6AF1A) = 4;
    func_08882F10(D_08A62D8C, 0);
    func_08885644(D_08A62D8C, 4, 0);
}
