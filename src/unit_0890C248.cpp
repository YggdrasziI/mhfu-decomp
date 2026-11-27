/* unit_0890C248: 0x0890C248-0x0890C26C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Calls the function pointer held in D_089B925C.
 *
 * C++: the code only matches when compiled as C++ (no tail call).
 */

typedef void (*func_ptr)(void);

extern "C" {

extern func_ptr D_089B925C;

void func_0890C248(void) {
    D_089B925C();
}

}
