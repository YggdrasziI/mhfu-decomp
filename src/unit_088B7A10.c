/* unit_088B7A10: 0x088B7A10-0x088B7A38 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A28B98;
extern int func_0880BFF0(void *, void *, int);

s32 func_088B7A10(char *arg0) {
    return func_0880BFF0(arg0, &D_09A28B98, 6) != 0;
}
