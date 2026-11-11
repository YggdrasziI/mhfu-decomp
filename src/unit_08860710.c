/* unit_08860710: 0x08860710-0x08860758 (ULES01213)
 *
 * Bounds (hypothesis): 1 function with the shape of func_0884B010, between unrelated code.
 */

typedef short s16;

extern void func_08860760(void *p);
extern int D_089BAB08;

void *func_08860710(int *p, s16 f) {
    if (p != 0) {
        *p = (int)&D_089BAB08;
        if (f > 0) {
            func_08860760(p);
        }
    }
    return p;
}
