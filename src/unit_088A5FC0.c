/* unit_088A5FC0: 0x088A5FC0-0x088A600C (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

extern s32 D_09A0FD80;
extern s32 D_09A0FD84[16];

s32 func_088A5FC0(void) {
    u32 i;

    for (i = 0; i < 16; i++) {
        D_09A0FD84[i] = 0;
    }
    D_09A0FD80 = 0;
    return 0;
}
