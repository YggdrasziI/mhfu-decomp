/* unit_08885494: 0x08885494-0x088854A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D84;
extern void func_08880254(s32, s32, s32, s32);

void func_08885494(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_08880254(D_08A62D84, arg1, arg2, arg3);
}
