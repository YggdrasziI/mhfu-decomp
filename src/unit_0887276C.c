/* unit_0887276C: 0x0887276C-0x088727CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

extern char *D_08A62C7C;
extern u8 D_089A8184[];

u8 func_0887276C(s32 arg0, u8 arg1) {
    u8 i;

    if (*(s32 *)(D_08A62C7C + 0x28) & 0x80) {
        for (i = 0; i < 8; i++) {
            if (D_089A8184[i] == arg1) {
                return i;
            }
        }
    }
    return 0xFF;
}
