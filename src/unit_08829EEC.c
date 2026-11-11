/* unit_08829EEC: 0x08829EEC-0x08829F04 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern void func_08829F04(s32, s32, s32, s32);

void func_08829EEC(s32 arg0, s32 arg1) {
    func_08829F04(arg0, arg1, 0x30, 0x30);
}

void func_08829EF8(s32 arg0, s32 arg1) {
    func_08829F04(arg0, arg1, 0xf6, 0x68);
}
