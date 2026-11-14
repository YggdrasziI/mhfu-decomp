/* unit_088606D0: 0x088606D0-0x08860710 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef float f32;

void func_088606D0(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    *(f32 *)(arg0 + 0x190) = fparg0;
    *(f32 *)(arg0 + 0x194) = fparg1;
    *(f32 *)(arg0 + 0x198) = fparg2;
}

void func_088606E0(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    *(f32 *)(arg0 + 0x190) = (f32) (*(f32 *)(arg0 + 0x190) + fparg0);
    *(f32 *)(arg0 + 0x194) = (f32) (*(f32 *)(arg0 + 0x194) + fparg1);
    *(f32 *)(arg0 + 0x198) = (f32) (*(f32 *)(arg0 + 0x198) + fparg2);
}

void func_08860708(char *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x198) = fparg0;
}
