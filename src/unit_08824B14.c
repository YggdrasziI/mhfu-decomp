/* unit_08824B14: 0x08824B14-0x08825104 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. Speed
 * setting. It owns two jump tables (0x08930A5C-0x08930A94, 7 + 7 words, in
 * .data) and an initialised local array (0x08938650-0x08938654, in .data),
 * opened in a nested block where the original copies it.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *D_08A631A8;
extern char *D_089CC438;
extern s32 D_09A44C5C;
extern u16 D_08938654;
extern u16 D_08938656;
extern u16 D_08938658;
extern u16 D_0893865A;
extern u16 D_089AC59A;
extern u16 D_089AC59C;
extern u16 D_089AC59E;
extern u16 D_089AC590[];
extern u16 D_089B53E4;
extern char D_08938628;
extern s16 D_08938630;
extern char *D_08938634;
extern u32 D_08938638;
extern char D_0893863C;
extern char D_089B556C;
extern char D_089AD0FC;
extern char D_089B5564;

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08825148(char *);
extern void func_08825ADC(char *, s32, u16, s32);
extern u16 *func_08856884(char *, s32);
extern char *func_0885151C(char *, u16);
extern void func_0882FC50(char *, char *, char *, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_08823CBC(char *, u8, s32);
extern void func_0882545C(char *, s32, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_08890E38(char *, s8);
extern void func_0887D02C(s32, s32, char *, s32);
extern void func_0882F9A8(char *, char *, char *, s32, s32, s32);
extern char *func_09A63198(s32, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_088197A0(char *, s32, s32, s32, s32);

void func_08824B14(char *p, s32 flag) {
    u8 v;

    *(u8 *)(p + 0x534) = 10;
    func_08890E08(D_08A631A8, 1);
    func_08825DA8(p);
    if (flag == 0) {
        *(u8 *)(p + 0x534) = 9;
        func_08890E08(D_08A631A8, 0);
        func_08825DA8(p);
        func_08825148(p);
    }
    *(u8 *)(p + 0x534) = 10;
    func_08890E08(D_08A631A8, 1);
    func_08825DA8(p);
    {
        s16 pos[2] = {0x192, 0xF3};
        char buf[0x40];
        if (*(u32 *)(p + 0x5E8) & 4) {
            if (*(u8 *)(p + 0x120E) & 1) {
                v = *(u8 *)(p + 0x120A);
                if (v == 1 || v == 2) {
                    func_08825ADC(p, 1, *(u16 *)((char *)(*(u8 *)(p + 0x120C) * 4) + (s32)D_089CC438 + 0x390) + 0x18, -1);
                } else if (v != 6 && v != 5) {
                    func_08825ADC(p, 1, *func_08856884(D_089CC438, *(u8 *)(p + 0x586)) + 0x18, -1);
                }
            } else {
                switch (*(u8 *)(p + 0x120A)) {
                case 1:
                case 3:
                    func_0882FC50(p, (char *)&D_08938654, func_0885151C(D_089CC438, D_089AC59A), 0xFF);
                    break;
                case 2:
                    func_0882FC50(p, (char *)&D_08938654, func_0885151C(D_089CC438, D_089AC59C), 0xFF);
                    break;
                case 4:
                    func_0882DCA0(p, D_08938654, D_08938656, D_08938658, D_0893865A, 0xFF);
                    func_08890DE8(D_08A631A8, 0xE, 0xE);
                    func_088920A8(D_08A631A8, 0xE0, 0xD5, func_0885151C(D_089CC438, D_089AC590[*(u8 *)(p + 0x120D)]));
                    break;
                case 5:
                case 6:
                    break;
                case 0:
                    if (flag != 0) {
                        func_08825ADC(p, *(u8 *)(p + 0x5FE), *(u16 *)(p + 0x5FC), -1);
                    }
                    break;
                }
            }
        }
        switch (*(u8 *)(p + 0x120A)) {
        case 0:
            D_08938638 = 0x8000C040;
            break;
        case 1:
            D_08938638 = 0x80808080;
            func_08823CBC(p, 0, *(u8 *)(p + 0x1218));
            func_0882545C(p, *(u8 *)(p + 0x120C), 0, *(s8 *)(p + 0x1210));
            if (!(*(u8 *)(p + 0x120E) & 1)) {
                func_0882A9DC(p, pos[0], pos[1], 0x35);
            }
            break;
        case 2:
            D_08938638 = 0x80808080;
            func_08823CBC(p, 0, *(u8 *)(p + 0x1218));
            func_0882545C(p, *(u8 *)(p + 0x120C), 0, -1);
            if (*(s8 *)(p + 0x1210) >= 0) {
                func_08890E38(D_08A631A8, 2);
                func_0887D02C(0x1C8, 0xB4, func_0885151C(D_089CC438, D_089AC59E), 0xE);
            }
            if (!(*(u8 *)(p + 0x120E) & 1)) {
                func_0882A9DC(p, pos[0], pos[1], 0x35);
            }
            break;
        case 3:
            D_08938638 = 0x80808080;
            func_08823CBC(p, 0, *(u8 *)(p + 0x1218));
            func_0882545C(p, *(u8 *)(p + 0x120C), 1, *(s8 *)(p + 0x1210));
            if (!(*(u8 *)(p + 0x120E) & 1)) {
                func_0882A9DC(p, pos[0], pos[1], 0x35);
            }
            break;
        case 4:
            D_08938638 = 0x80808080;
            func_08823CBC(p, 0, *(u8 *)(p + 0x1218));
            func_0882545C(p, -1, 0, 0);
            break;
        case 5:
        case 6:
            break;
        }
        if (*(u8 *)(p + 0x1218) != 0) {
            D_08938634 = &D_089B556C;
            D_08938630 = 0x18;
            func_0882F9A8(p, &D_08938628, 0, *(u8 *)(p + 0x120B), 0xFF, 4);
        } else if (flag != 0) {
            D_08938634 = &D_089AD0FC;
            D_08938630 = 0x16;
            func_0882F9A8(p, &D_08938628, 0, *(u8 *)(p + 0x120B), 0xFF, 0);
        } else {
            D_08938634 = &D_089B5564;
            D_08938630 = 0x16;
            func_0882F9A8(p, &D_08938628, 0, *(u8 *)(p + 0x120B), 0xFF, 4);
        }
        if (flag == 0) {
            func_0880E8F0(buf, func_09A63198(D_09A44C5C, D_089B53E4), *(s32 *)(p + 0x1214) / 30);
            func_0882FC50(p, &D_0893863C, buf, 0xFF);
        }
        if (*(u8 *)(p + 0x120A) == 3) {
            *(u8 *)(p + 0x534) = 11;
            func_08890E08(D_08A631A8, 2);
            func_08825DA8(p);
            func_088197A0(p, *(u8 *)(p + 0x586), 0x8000C040, 0x10, 2);
        }
    }
}
