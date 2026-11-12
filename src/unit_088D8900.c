/* unit_088D8900: 0x088D8900-0x088D897C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_089CC438;
extern int func_0880C084(s32, s32, s32);
extern s32 func_08856884(s32, s32);

void func_088D8900(s32 arg0) {
    func_0880C084(D_089CC438 + 0x43C8, func_08856884(D_089CC438, 0), 0x60);
}

void func_088D893C(s32 arg0) {
    s32 temp_s0;

    temp_s0 = D_089CC438;
    func_0880C084(func_08856884(temp_s0, 0), temp_s0 + 0x43C8, 0x60);
}
