/* unit_0884F5F4: 0x0884F5F4-0x0884F670 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_0899A1B8;
extern int func_0880E8F0(char *, char *);
extern s32 func_0884F670(s32, s32);
extern int sceIoDclose(s32);
extern s32 sceIoDopen(char *);

void func_0884F5F4(s32 arg0, s32 arg1) {
    char sp10[0x40];
    s32 temp_v0;

    if (arg1 == 0x80010002) {
        func_0880E8F0(sp10, &D_0899A1B8);
        temp_v0 = sceIoDopen(sp10);
        if (temp_v0 >= 0) {
            sceIoDclose(temp_v0);
        }
        func_0884F670(arg0, temp_v0);
        return;
    }
    func_0884F670(arg0, arg1);
}
