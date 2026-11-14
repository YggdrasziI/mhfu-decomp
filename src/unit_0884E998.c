/* unit_0884E998: 0x0884E998-0x0884EA1C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern int func_0884EA1C(char *, s32, s32, u32);
extern void func_0884EC3C(void *, u32);

void func_0884E998(char *arg0, char *arg1) {
    s32 temp_a3;
    s32 temp_s0;
    u32 temp_s3;

    temp_a3 = *(s32 *)(arg1 + 0xC);
    temp_s0 = *(s32 *)(arg1 + 4) + temp_a3;
    temp_s3 = temp_a3 + (((s32 *)(arg0 + 0x2AC0))[*(u16 *)(arg1 + 2)] << 0xB);
    if (*(u8 *)(arg1 + 0x19) != 0) {
        func_0884EC3C(arg0, temp_s3 >> 0xB);
    }
    func_0884EA1C(arg0, temp_s0, *(s32 *)(arg1 + 8), temp_s3);
}
