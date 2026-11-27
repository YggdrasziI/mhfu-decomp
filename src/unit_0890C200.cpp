/* unit_0890C200: 0x0890C200-0x0890C224 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890C200: calls the function pointer stored in D_089B9260.
 *
 * C++: as C the call becomes a tail jump (`jr v0`); compiled as C++ the
 * frame and `jalr` are kept, as in the original.
 */

typedef void (*func_ptr)(void);

extern "C" {

extern func_ptr D_089B9260;

void func_0890C200(void) {
    D_089B9260();
}

}
