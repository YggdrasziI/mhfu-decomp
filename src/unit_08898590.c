/* unit_08898590: 0x08898590-0x08898694 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;

extern void func_08859AE4(void *, void *, s32);

void func_08898590(char *arg0, s32 arg1) {
    s32 i;

    func_08859AE4(arg0, arg0 + 0x30, arg1);
    for (i = 0; i < 0x200; i++) {
        *(s32 *) (arg0 + 0x83C030) = -1;
        *(s32 *) (arg0 + 0x83C034) = 0;
        arg0 += 0xC;
    }
}
