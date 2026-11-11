/* unit_08892F88: 0x08892F88-0x08892FB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_08A631B8;
extern s32 D_08A8B1E0;
extern int func_08859C40(char *);

void func_08892F88(s32 arg0, char *arg1) {
    D_08A8B1E0 -= *(s32 *)(arg1 + -0x10) * 0x10;
    func_08859C40(&D_08A631B8);
}
