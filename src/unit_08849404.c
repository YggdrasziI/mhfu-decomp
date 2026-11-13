/* unit_08849404: 0x08849404-0x08849478 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 func_088567B4(void *);

void func_08849404(char *arg0) {
    u8 temp_v1;
    u8 temp_v1_2;
    u8 var_v1;

    if ((*(u8 *)(arg0 + 0x11AB) != 0) && ((func_088567B4(D_089CC438) & 0xFF) == 1)) {
        temp_v1 = *(u8 *)(arg0 + 0x11AC);
        if ((s32) temp_v1 < 5) {
            var_v1 = temp_v1 + 1;
            *(u8 *)(arg0 + 0x11AC) = var_v1;
        }
    } else {
        temp_v1_2 = *(u8 *)(arg0 + 0x11AC);
        if ((s32) temp_v1_2 > 0) {
            var_v1 = temp_v1_2 - 1;
            *(u8 *)(arg0 + 0x11AC) = var_v1;
        }
    }
}
