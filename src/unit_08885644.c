/* unit_08885644: 0x08885644-0x0888571C (ULES01213) */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern s32 D_09A4F0C4;
extern s32 D_08A62D84;

extern char *func_088DCEBC(s32, s32);
extern void func_08880384(s32, s32, s32);
extern void func_088803C4(s32, s32, s32, s16);

void func_08885644(s32 arg0, s32 arg1, s32 arg2) {
    char *p;
    s32 i;

    p = func_088DCEBC(D_09A4F0C4, 1);
    for (i = 1; i <= 10; i++) {
        if (p != 0 && *(u8 *)(p + 0x1E8) == 12) {
            func_08880384(D_08A62D84, i, arg1);
        } else if (i != 3) {
            func_08880384(D_08A62D84, i, arg1);
        }
    }
    if (arg2 == 0) {
        func_088803C4(D_08A62D84, 0, 0x1000, arg1);
    }
}
