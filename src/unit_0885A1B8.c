/* unit_0885A1B8: 0x0885A1B8-0x0885A23C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_08859D14(s32);
extern s32 func_0885A23C(s32);
extern void func_0885A8E0(void *);
extern void func_0885A8F0(void *);

void func_0885A1B8(char *arg0) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 2);
    switch (temp_a1) {                              /* irregular */
    case 0:
        func_08859D14((s32) arg0);
        return;
    case 1:
        func_0885A23C((s32) arg0);
        return;
    case 2:
        func_0885A8E0(arg0);
        return;
    case 3:
        func_0885A8F0(arg0);
        return;
    }
}
