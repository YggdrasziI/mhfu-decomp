/* unit_088C31D0: 0x088C31D0-0x088C3290 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_089CBBE0;
extern int func_08812144(s32, s32, s32, s32);
extern s32 func_08812610(s32, s32);
extern void func_08859AE4(void *, void *, s32);

void func_088C31D0(char *arg0) {
    func_08859AE4(arg0 + 0x2294 + 0x7FF8, arg0 + 0x28C, 0xA000);
    *(s32 *)(arg0 + 0xA2B8) = 0;
    func_08812144(D_089CBBE0, 6, 0x4E200, -1);
    *(s32 *)(arg0 + 0xA2BC) = func_08812610(D_089CBBE0, 6);
    *(s32 *)(arg0 + 0xA2C0) = 0;
    *(u16 *)(arg0 + 0x28A) = 0xFFFF;
    *(u8 *)(arg0 + 0xA2C8) = 0;
    *(s32 *)(arg0 + 0xA2E0) = 0;
    *(u8 *)(arg0 + 0xA3E8) = 0;
    *(u8 *)(arg0 + 0xA3E9) = 1;
}
