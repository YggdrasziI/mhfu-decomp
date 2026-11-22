/* unit_08885870: 0x08885870-0x088858EC (ULES01213) */

typedef int s32;
typedef short s16;

extern s32 D_08A62D84;

extern void func_088803A4(s32, s32, s32);
extern void func_088803C4(s32, s32, s32, s16);

void func_08885870(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 1; i <= 10; i++) {
        func_088803A4(D_08A62D84, i, arg1);
    }
    if (arg2 == 0) {
        func_088803C4(D_08A62D84, 0x1000, 0, arg1);
    }
}
