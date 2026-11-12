/* unit_088AE16C: 0x088AE16C-0x088AE1D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern void func_088AE1D4(void *, s32, s32);
extern s32 func_088AE1EC(s32);
extern void func_088AE25C(void *);

void func_088AE16C(char *arg0, s32 arg1, s32 arg2) {
    u8 temp_a1;

    temp_a1 = *(u8 *)(arg0 + 0x22);
    switch (temp_a1) {                              /* irregular */
    case 0:
        func_088AE1D4(arg0, (s32) temp_a1, arg2);
        return;
    case 1:
        func_088AE1EC((s32) arg0);
        return;
    case 2:
        func_088AE25C(arg0);
        return;
    }
}
