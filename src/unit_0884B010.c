/* unit_0884B010: 0x0884B010-0x0884B058 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (stores a table address in the object, then a call when the flag is positive), between unrelated code.
 */

typedef short s16;

extern void func_08897298(void *p);
extern int D_089BAB98;

void *func_0884B010(int *p, s16 f) {
    if (p != 0) {
        *p = (int)&D_089BAB98;
        if (f > 0) {
            func_08897298(p);
        }
    }
    return p;
}
