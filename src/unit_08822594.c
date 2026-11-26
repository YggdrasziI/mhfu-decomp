#pragma optimize_for_size off
typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AC988;
extern char D_08938478;
extern u16 D_0893ACC4[];
extern u16 D_0893ACB8[];
extern u8 D_08930A34[];

extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, u16);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);

void func_08822594(s32 arg0, char *arg1, s32 x, s32 y, s32 mask) {
    s32 i;
    s8 c;

    func_088915B0(D_08A631A8, (s16)x, (s16)y, 5, &D_08938478, func_0885151C(D_089CC438, D_089AC988));
    for (i = 0; i < 6; i++) {
        c = (*(s32 *)(arg1 + 0x18) & D_0893ACC4[i]) ? 0 : 10;
        if (c == 10 && (mask & D_0893ACC4[i])) {
            c = 3;
        }
        func_088915B0(D_08A631A8, (s16)((u16)x + D_08930A34[i * 2]), (s16)((u16)y + D_08930A34[i * 2 + 1]), c,
                      &D_08938478, func_08851528(D_089CC438, D_0893ACB8[i]));
    }
}
