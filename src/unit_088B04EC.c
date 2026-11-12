/* unit_088B04EC: 0x088B04EC-0x088B0554 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern char D_09A201F0;
extern int func_0880BFF0(void *, void *, int);
extern int func_0880C084(void *, void *, s32);

s32 func_088B04EC(char *arg0) {
    return func_0880BFF0(arg0, &D_09A201F0, 6) != 0;
}

s32 func_088B0514(char *arg0, char *arg1) {
    return func_0880BFF0(arg0, arg1, 6) != 0;
}

s32 func_088B0534(char *arg0, char *arg1) {
    func_0880C084(arg0, arg1, 6);
    return 0;
}
