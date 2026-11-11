/* unit_0884F510: 0x0884F510-0x0884F5F4 (ULES01213)
 *
 * Bounds (hypothesis): 3 tests with a fallback call, between unrelated code.
 */

typedef unsigned char u8;

extern int func_088B863C(void *p);
extern int func_088B8688(void *p);
extern int func_088B8624(void *p);

int func_0884F510(char *p) {
    if (*(u8 *)(p + 0x2FBDC) != 0 && *(int *)(p + 0x2FBE0) != 0) {
        return 1;
    }
    return func_088B8624(p);
}

int func_0884F55C(char *p) {
    if (*(u8 *)(p + 0x2FBDC) != 0 && *(int *)(p + 0x2FBE0) != 0) {
        return 1;
    }
    return func_088B863C(p);
}

int func_0884F5A8(char *p) {
    if (*(u8 *)(p + 0x2FBDC) != 0 && *(int *)(p + 0x2FBE0) != 0) {
        return 1;
    }
    return func_088B8688(p);
}
