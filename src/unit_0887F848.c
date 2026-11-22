/* unit_0887F848: 0x0887F848-0x0887F8D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern void func_0887F934(char *, char *);
extern void func_0889E848(s32, s32, s32, s32);
extern void func_0889E984(void);
extern void func_0889EA4C(s32);
extern int func_0887FE5C(s32, s32, s32);
extern void func_0887FB28(s32 *, s32);
extern void func_0889EAD4(void (*)(char *, char *));

void func_0887F848(s32 *arg0, s32 arg1, s32 arg2) {
    func_0889E848(arg1, 0x12, 0x11, 0);
    func_0889E984();
    func_0889EA4C(arg2);
    arg0[0] = arg1;
    arg0[1] = arg2;
    func_0887FE5C((s32)arg0, 0, 1);
    func_0887FB28(arg0, 1);
    func_0889EAD4(func_0887F934);
}
