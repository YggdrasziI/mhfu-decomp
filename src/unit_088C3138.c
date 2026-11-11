/* unit_088C3138: 0x088C3138-0x088C3180 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern char *D_09A4F060;

char *func_088C3138(char *arg0) {
    D_09A4F060 = arg0;
    *(s32 *)(arg0 + 0xA2BC) = 0;
    *(s32 *)(arg0 + 0xA2C0) = 0;
    *(s32 *)(arg0 + 0xA2B4) = 0;
    *(s32 *)(arg0 + 0xA2B8) = 0;
    *(u16 *)(arg0 + 0x28A) = 0xFFFF;
    return arg0;
}
