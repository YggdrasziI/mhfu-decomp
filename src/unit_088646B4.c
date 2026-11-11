/* unit_088646B4: 0x088646B4-0x088646F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088641C0(s32);
extern int func_088646F0(s32, s32, s32, s32);

void func_088646B4(s32 arg0) {
    func_088641C0(arg0 + 0x80);
    func_088646F0(arg0 + 0x50, arg0 + 0x80, arg0 + 0x70, arg0 + 0x10);
}
