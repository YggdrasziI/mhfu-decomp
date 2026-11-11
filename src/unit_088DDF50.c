/* unit_088DDF50: 0x088DDF50-0x088DDF94 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B540;
extern int func_088987D4(s32, s32);
extern int func_088DD7C4(char *);

void func_088DDF50(s32 arg0, s32 arg1) {
    char *temp_s0;

    temp_s0 = (char *) (arg0 + (arg1 * 0xC));
    func_088987D4(D_09A0B540, *(s32 *)(temp_s0 + 4));
    func_088DD7C4(temp_s0);
}
