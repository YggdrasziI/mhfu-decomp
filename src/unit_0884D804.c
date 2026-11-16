/* unit_0884D804: 0x0884D804-0x0884D878 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_089BAA94;
extern char D_089BAB98;
extern s32 D_089CC01C;
extern void func_08897298(s32);

char **func_0884D804(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAA94;
        if (((char *) arg0 + 0x1C) != 0) {
            D_089CC01C = 0;
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
