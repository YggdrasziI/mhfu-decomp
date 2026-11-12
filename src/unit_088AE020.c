/* unit_088AE020: 0x088AE020-0x088AE074 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 sceNetAdhocctlScan(void);
extern s8 D_09A1FDE8;

void func_088AE020(char *arg0) {
    *(u8 *)(arg0 + 0x22) = (u8) (*(u8 *)(arg0 + 0x22) + 1);
    D_09A1FDE8 = 0;
    if (sceNetAdhocctlScan() < 0) {
        *(u8 *)(arg0 + 0x21) = 2;
        *(u8 *)(arg0 + 0x22) = 0U;
        *(u16 *)(arg0 + 0x26) = 0x8003;
    }
}
