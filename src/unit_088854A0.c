/* unit_088854A0: 0x088854A0-0x088854C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D84;
extern int func_08880294(s32, s32, s32);

void func_088854A0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        func_08880294(D_08A62D84, arg1, arg2);
    }
}
