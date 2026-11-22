/* unit_0888571C: 0x0888571C-0x08885798 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef short s16;

extern s32 D_08A62D84;

extern void func_08880384(s32, s32, s32);
extern void func_088803C4(s32, s32, s32, s16);

void func_0888571C(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 1; i <= 10; i++) {
        func_08880384(D_08A62D84, i, arg1);
    }
    if (arg2 == 0) {
        func_088803C4(D_08A62D84, 0, 0x1000, arg1);
    }
}
