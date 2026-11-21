/* unit_088F6450: 0x088F6450-0x088F69B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws the frame common to the nine status pages (background, a tab bar of
 * eight pieces, two icons, the page number), counts once the entries of four
 * lists of arg1 to get the page counts at +0x1F..+0x23, then draws the page
 * arg2 through a jump table and records it at +0xA72B.
 *
 * Optimized for speed: the loops step pointers and are tested at the bottom.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_089B81DC[];
extern s32 D_089B81F8[];
extern char D_089B8588[];

extern void func_08825DA8(char *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern void func_0882B94C(char *, u16, u16, s32, s32, s32, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern void func_0882E6F0(char *, s32, s32, s32, s32);
extern void func_08832B98(char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_088F69B4(char *, char *, s32);
extern void func_088F7108(char *, char *, s32);
extern void func_088F7620(char *, char *, s32);
extern void func_088F9058(char *, char *, s32);
extern void func_088F9EF4(char *, char *, s32);
extern void func_088FA6D8(char *, char *, s32);
extern void func_088FAB0C(char *, char *, s32);
extern void func_088FAE30(char *, char *, s32);
extern void func_088FB2B0(char *, char *, s32);
extern s32 func_088FD168(char *, char *);

void func_088F6450(char *arg0, char *arg1, u32 arg2) {
    s32 kind;
    char *temp;
    s32 i;

    kind = func_088FD168(arg0, arg1);
    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_08832B98(D_089CBBEC, 1);
    func_0882AF70(D_089CBBEC, 0, 0, 0x1E0, 0x110, D_089B81DC[kind]);
    func_08832B98(D_089CBBEC, 0);
    i = 0;
    func_0882B94C(D_089CBBEC, 0x156, 0xF, 0xFF, 0xFF, 0xFF, 0x80, 0x159);
    for (i++; i <= 6; i++) {
        func_0882B94C(D_089CBBEC, 0x156 + i * 16, 0xF, 0xFF, 0xFF, 0xFF, 0x80, 0x15A);
    }
    func_0882B94C(D_089CBBEC, 0x156 + i * 16, 0xF, 0xFF, 0xFF, 0xFF, 0x80, 0x15B);
    func_0882A9DC(D_089CBBEC, 0x172, 0x10, 0x36);
    func_0882A9DC(D_089CBBEC, 0x1A6, 0x10, 0x37);
    func_0882E6F0(D_089CBBEC, 0x160, 0x10, 0x60, 0xF0);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08891474(D_08A631A8, 0x18A, 0x12, D_089B8588, arg2 + 1, 9);
    func_0882DCB0(D_089CBBEC, 0x10, 0xC, 0x10C, 0x18, 0xFF, D_089B81F8[kind]);
    if (*(u8 *)(arg0 + 0xA72C) == 0) {
        *(s8 *)(arg0 + 0x1F) = 0;
        for (i = 0; i < 0x1F; i++) {
            if ((*(u8 *)(arg1 + 0x150 + i * 8) & 1) || (*(u16 *)(arg1 + 0x152 + i * 8) & 0x3FFF) > 0) {
                (*(s8 *)(arg0 + 0x1F))++;
            }
        }
        *(s8 *)(arg0 + 0x1F) = (*(s8 *)(arg0 + 0x1F) + 8) / 9;
        if (arg2 == 6 && *(s8 *)(arg0 + 0x10) >= *(s8 *)(arg0 + 0x1F)) {
            *(s8 *)(arg0 + 0x10) = 0;
        }
        *(s8 *)(arg0 + 0x20) = 0;
        for (i = 0; i < 0x17; i++) {
            if (*(u32 *)(arg1 + 0x250 + i * 4) >> 15) {
                (*(s8 *)(arg0 + 0x20))++;
            }
        }
        *(s8 *)(arg0 + 0x20) = (*(s8 *)(arg0 + 0x20) + 8) / 9;
        if (arg2 == 7 && *(s8 *)(arg0 + 0x10) >= *(s8 *)(arg0 + 0x20)) {
            *(s8 *)(arg0 + 0x10) = 0;
        }
        *(s8 *)(arg0 + 0x21) = 0;
        *(u8 *)(arg0 + 0xA72A) = 0;
        for (i = 0; i < 0x14; i++) {
            if (*(u32 *)(arg1 + 0x2AC + i * 0x14) >> 15) {
                if (*(s8 *)(arg0 + 0x21) == 0) {
                    *(u8 *)(arg0 + 0xA72A) = i;
                }
                (*(s8 *)(arg0 + 0x21))++;
            }
        }
        *(s8 *)(arg0 + 0x22) = 0;
        for (i = 0; i < 0xD; i++) {
            if (*(s8 *)(arg1 + 0xB90 + i * 0x40) != 0) {
                (*(s8 *)(arg0 + 0x22))++;
            }
        }
        *(s8 *)(arg0 + 0x23) = 0;
        *(u8 *)(arg0 + 0xA72C) = 1;
    }
    if (arg2 == 8 && *(u8 *)(arg0 + 0xA72B) != arg2) {
        *(u8 *)(arg0 + 0xA72A) = 0;
        for (i = 0; i < 0x14; i++) {
            if ((*(u32 *)(arg1 + 0x2AC + i * 0x14) >> 15) != 0) {
                *(u8 *)(arg0 + 0xA72A) = i;
                break;
            }
        }
    }
    switch (arg2) {
    case 0:
        func_088F69B4(arg0, arg1, kind);
        break;
    case 1:
        func_088F7108(arg0, arg1, kind);
        break;
    case 2:
        func_088F7620(arg0, arg1, kind);
        break;
    case 3:
        func_088F9058(arg0, arg1, kind);
        break;
    case 4:
        func_088F9EF4(arg0, arg1, kind);
        break;
    case 5:
        func_088FA6D8(arg0, arg1, kind);
        break;
    case 6:
        func_088FAB0C(arg0, arg1, kind);
        break;
    case 7:
        func_088FAE30(arg0, arg1, kind);
        break;
    case 8:
        func_088FB2B0(arg0, arg1, kind);
        break;
    }
    *(u8 *)(arg0 + 0xA72B) = arg2;
}
