/* unit_088DBE70: 0x088DBE70-0x088DBE80 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A4F0D0;
extern void func_088DDF50(s32, char *);

void func_088DBE70(s32 arg0, char *arg1) {
    func_088DDF50(D_09A4F0D0, arg1 + 0x1);
}
