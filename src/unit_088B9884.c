/* unit_088B9884: 0x088B9884-0x088B9910 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (destructor shape: vtable, member at +0x1C,
 * delete when the flag is positive) after func_088B97BC (NonMatching).
 */

typedef short s16;
typedef int s32;

extern char D_089BAB98;
extern char D_089BAC6C;
extern s32 D_089CBBE0;
extern s32 D_09A44C5C;
extern int func_08812264(s32, s32);
extern void func_08897298(s32);

char **func_088B9884(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAC6C;
        func_08812264(D_089CBBE0, 6);
        if (((char *) arg0 + 0x1C) != 0) {
            D_09A44C5C = 0;
        }
        if (arg0 != 0) {
            *arg0 = &D_089BAB98;
        }
        if (arg1 > 0) {
            func_08897298((s32) arg0);
        }
    }
    return arg0;
}
