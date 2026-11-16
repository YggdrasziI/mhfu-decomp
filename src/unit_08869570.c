/* unit_08869570: 0x08869570-0x088695F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A4F060;
extern s32 func_088C722C(s32, s32, s32);

s32 func_08869570(char *arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_s0 = *(s32 *)(arg0 + 0x60);
    temp_v1_2 = func_088C722C(D_09A4F060, (s32) *(u8 *)(D_089CC438 + 0x6AF10), arg1) & 0xFFFF;
    if (temp_v1_2 == 0xFFFF) {
        return 0;
    }
    temp_v1 = *(s32 *)((temp_s0 + (temp_v1_2 * 4)));
    if (temp_v1 == 0) {
        return 0;
    }
    return temp_v1 + *(s32 *)(arg0 + 0x50);
}
