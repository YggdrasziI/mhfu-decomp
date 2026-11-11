/* unit_088AE508: 0x088AE508-0x088AE514 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088B7078(s32, s32, s32);

void func_088AE508(s32 arg0) {
    func_088B7078(arg0, 0xffff, 0x8003);
}
