/* unit_088345B8: 0x088345B8-0x088345FC (ULES01213)
 *
 * Bounds (hypothesis): 1 call guarded by another call, between unrelated code.
 */

typedef int s32;

extern int func_0883E928(void *p, s32);
extern void func_088D8900(int a);

int func_088345B8(char *p, s32 arg1) {
    int r = func_0883E928(p, arg1);

    if (r != 0) {
        func_088D8900(*(int *)(p + 0x530));
    }
    return r;
}
