/* unit_088664F8: 0x088664F8-0x088665A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;

typedef struct Big {
    char buf[0x80000];
    char unk80000[0x28];
    s32 unk80028[15];
    s32 unk80064[15];
    s32 unk800A0;
} Big;

extern void func_08859AE4(void *, void *, s32);

void func_088664F8(Big *arg0) {
    s32 i;

    for (i = 0; i < 15; i++) {
        arg0->unk80028[i] = 0;
        arg0->unk80064[i] = 0;
    }
    arg0->unk800A0 = 0;
    func_08859AE4(arg0->unk80000, arg0, 0x80000);
}
