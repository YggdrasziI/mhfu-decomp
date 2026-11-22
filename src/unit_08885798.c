/* unit_08885798: 0x08885798-0x08885870 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern s32 D_09A4F0C4;
extern s32 D_08A62D84;

extern char *func_088DCEBC(s32, s32);
extern void func_088803A4(s32, s32, s32);
extern void func_088803C4(s32, s32, s32, s16);

void func_08885798(s32 arg0, s32 arg1, s32 arg2) {
    char *p;
    s32 i;

    p = func_088DCEBC(D_09A4F0C4, 1);
    for (i = 1; i <= 10; i++) {
        if (p != 0 && *(u8 *)(p + 0x1E8) == 12) {
            func_088803A4(D_08A62D84, i, arg1);
        } else if (i != 3) {
            func_088803A4(D_08A62D84, i, arg1);
        }
    }
    if (arg2 == 0) {
        func_088803C4(D_08A62D84, 0x1000, 0, arg1);
    }
}
