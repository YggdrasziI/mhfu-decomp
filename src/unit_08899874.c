/* unit_08899874: 0x08899874-0x0889990C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char D_089B16C0;
extern char D_089B16CC;
extern char D_089B16D4;
extern int func_0880ED70(void *, char *);
extern char func_0889A09C;
extern int func_088B06C0(char *, char *);
extern int func_088B0A58(void *);

void func_08899874(char *arg0, s32 arg1) {
    func_0880ED70(arg0 + 5, &D_089B16C0);
    if (arg1 == 0) {
        func_0880ED70(arg0 + 0x11, &D_089B16CC);
    } else {
        func_0880ED70(arg0 + 0x11, &D_089B16D4);
    }
    *(s8 *)(arg0 + 0x19) = 0;
    func_088B0A58(arg0 + 5);
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 1);
    func_088B06C0(&func_0889A09C, arg0);
    *(s8 *)(arg0 + 4) = 1;
}
