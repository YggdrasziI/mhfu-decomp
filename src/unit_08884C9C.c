/* unit_08884C9C: 0x08884C9C-0x08884CD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef float f32;

void func_08884C9C(char *arg0, f32 fparg0) {
    if (fparg0 < 0.0f) {
        *(u8 *)((char *)arg0 + 0x562464) = 1;
        return;
    }
    *(u8 *)((char *)arg0 + 0x562464) = 0;
}
