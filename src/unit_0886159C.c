/* unit_0886159C: 0x0886159C-0x088615E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function with the shape of func_0884B010, between unrelated code.
 */

typedef short s16;

extern void func_0890BFA4(void *p);
extern int D_089BAB28;

void *func_0886159C(int *p, s16 f) {
    if (p != 0) {
        *p = (int)&D_089BAB28;
        if (f > 0) {
            func_0890BFA4(p);
        }
    }
    return p;
}
