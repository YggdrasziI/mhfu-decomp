/* unit_088A412C: 0x088A412C-0x088A4178 (ULES01213) */

#pragma optimize_for_size off

typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_09A0E3A0[];
extern u8 D_09A0E3A1;

void func_088A412C(void) {
    u32 i;

    for (i = 0; i < 16; i++) {
        D_09A0E3A0[i] = 0;
    }
    D_09A0E3A1 = 5;
}
