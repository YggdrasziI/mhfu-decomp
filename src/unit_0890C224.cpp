/* unit_0890C224: 0x0890C224-0x0890C248 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890C224: calls the function pointer stored in D_089B925C. */

typedef void (*func_t)(void);

extern "C" {

extern func_t D_089B925C;

void func_0890C224(void) {
    D_089B925C();
}

}
