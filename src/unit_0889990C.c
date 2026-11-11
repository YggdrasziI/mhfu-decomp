/* unit_0889990C: 0x0889990C-0x08899954 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char func_0889A138;
extern char func_0889A1E4;
extern int func_088B089C(char *, char *, char *);
extern int func_088B0938(char *, char *);

void func_0889990C(char *arg0, s8 arg1) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 2);
    func_088B089C(arg0 + (arg1 * 0x10) + 0xDC, &func_0889A138, arg0);
}

void func_08899938(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 4);
    func_088B0938(&func_0889A1E4, arg0);
}
