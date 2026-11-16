/* unit_088A7090: 0x088A7090-0x088A713C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_089BAB98;
extern char D_089BABF8;
extern s32 D_089CBBE0;
extern s32 D_09A0B540;
extern s32 D_09A0FDC4;
extern int func_08812264(s32, s32);
extern void func_08897298(s32);
extern int func_08898748(s32, s32);

char **func_088A7090(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BABF8;
        func_08812264(D_089CBBE0, 6);
        func_08898748(D_09A0B540, 4);
        func_08898748(D_09A0B540, 5);
        if (((char *) arg0 + 0x1C) != 0) {
            D_09A0FDC4 = 0;
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
