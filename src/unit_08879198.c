/* unit_08879198: 0x08879198-0x0887941C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08879158 and unit_0887941C. Its initialised array (0x089A88B0-0x089A88C8, in .data) is
 * linked from this unit.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern s32 D_08A62C50;
extern char *D_08A62C7C;
extern s32 D_08A631A0;
extern s32 D_09A4F0C4;

extern s32 func_0884FCB0(char *);
extern void func_0884FEEC(char *, u8, s32);
extern void func_0884FF80(char *, u8, s32);
extern u16 func_08850520(char *, u8);
extern u16 *func_08856884(char *, s32);
extern void func_088585E8(char *, char *, s32, s32, s32);
extern char *func_0885C580(s32, s32);
extern void func_08874454(char *);
extern s32 func_08890114(s32 arg0);
extern s32 func_088D72A4(s32, s32, s32, s32);
extern s32 func_088DCEBC(s32, u8);

void func_08879198(char *arg0) {
    s32 obj = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    s32 i;
    s32 j;

    func_08890114(D_08A631A0);
    *(s32 *)(D_089CC438 + 0x47C) = 0;
    for (i = 0; i < 0x18; i++) {
        if (*(u8 *)(func_0885C580(D_08A62C50, i) + 4) & 4) {
            u16 *slot = func_08856884(D_089CC438, i);

            func_088D72A4(obj, slot[0], (s16) -((s16 *) func_08856884(D_089CC438, i))[1], 0);
        }
    }
    for (j = 0; j <= 0x59; j++) {
        i = *(u16 *)(D_08A62C7C + j * 2 + 0x29C) + *(u16 *)(D_08A62C7C + j * 2 + 0x350);

        if (i != 0 && j != 0x1D) {
            u8 ids[24] = {3, 4, 5, 9, 0xC, 0xD, 0x10, 0x13, 0x17, 0x18, 0x19, 0x1E, 0x22, 0x23, 0x38, 0x39, 0x3D, 0x3E, 0x3F, 0x42, 0x45, 0x46, 0x49, 0};
            u8 unit = 0xA;
            u32 have;
            u32 total;

            if (ids[0] != 0) {
                u8 *p = ids;

                do {
                    if (*p == j) {
                        unit = 0x32;
                        break;
                    }
                    p++;
                } while (*p != 0);
            }
            have = func_08850520(D_089CC438, j);
            total = have + i;
            if (total <= 0x270E) {
                if (i + have % unit >= unit) {
                    func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x15, j, unit / 10 * (total / unit));
                }
            }
        }
        if (*(u16 *)(D_08A62C7C + j * 2 + 0x29C) > 0) {
            func_0884FEEC(D_089CC438, j, *(u16 *)(D_08A62C7C + j * 2 + 0x29C));
        }
        if (*(u16 *)(D_08A62C7C + j * 2 + 0x350) > 0) {
            func_0884FF80(D_089CC438, j, *(u16 *)(D_08A62C7C + j * 2 + 0x350));
        }
    }
    func_08874454(arg0);
    *(s8 *)(arg0 + 0xC0) = func_0884FCB0(D_089CC438);
    *(s8 *)(arg0 + 0xC1) = 0;
}