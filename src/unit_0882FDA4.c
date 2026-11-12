/* unit_0882FDA4: 0x0882FDA4-0x0882FE34 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_0882AF70(s32, s32, s32, s32, s32, s32);
extern s32 func_0882FD68(s32, s32);
extern s32 func_0882FE34(s32, s32, s32, s32, s32);

void func_0882FDA4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    func_0882AF70(arg0, arg1, arg2, 0x58, 0x40, 0xAF);
    temp_v0 = func_0882FD68(arg0, arg3);
    if (temp_v0 != 0) {
        func_0882FE34(arg0, ((arg1 & 0xFFFF) + 0x14) & 0xFFFF, ((arg2 & 0xFFFF) + 7) & 0xFFFF, (s32) *(u8 *)(temp_v0 + 1), (s32) *(u8 *)(temp_v0 + 2));
    }
}
