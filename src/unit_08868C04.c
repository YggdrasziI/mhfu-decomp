/* unit_08868C04: 0x08868C04-0x08868CE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern char *D_089CC01C;
extern char *D_08A62C64;
extern void func_0884D790(void *, s16, s32);
extern void func_088689FC(void *);
extern s32 func_08868CE8(s32, s32, s32, s32, s32, s32, s32);
extern s32 sceUtilityOskInitStart(char *);

void func_08868C04(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    *(u8 *)(D_08A62C64 + 0x17) = 1;
    *(u8 *)(arg0 + 0x74) = 1;
    func_088689FC(arg0);
    func_08868CE8((s32) arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    if (sceUtilityOskInitStart(arg0) != 0) {
        *(u8 *)(D_08A62C64 + 0x17) = 0;
        *(u8 *)(arg0 + 0x74) = 0;
        return;
    }
    func_0884D790(D_089CC01C, 4, 1);
    *(u8 *)(D_089CC01C + 0x29) = 0xC0;
}
