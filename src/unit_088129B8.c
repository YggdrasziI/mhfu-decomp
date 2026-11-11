/* unit_088129B8: 0x088129B8-0x088129F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (calls func_0890BFA4 on the object when the flag is positive, returns it), between unrelated code.
 */

typedef short s16;

extern void func_0890BFA4(void *p);

void *func_088129B8(void *p, s16 f) {
    if (p != 0 && f > 0) {
        func_0890BFA4(p);
    }
    return p;
}
