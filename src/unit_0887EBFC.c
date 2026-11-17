/* unit_0887EBFC: 0x0887EBFC-0x0887F464 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0887EB80 and unit_0887F464.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A62C7C;
extern s32 D_09A4F0C4;
extern char *D_09A0B544;

extern void func_088585E8(char *, char *, s32, s32, s32);
extern s32 func_0887EB80(char *);
extern s32 func_0886A35C(char *, s32);
extern char *func_088DCEBC(s32, s32);
extern u8 func_0884FB38(char *, u32);
extern u8 func_08854BEC(char *, u32);
extern u8 func_08854C5C(char *, u32);
extern void func_0884FAC4(char *, u32);
extern void func_0880C084(void *, void *, s32);
extern char *func_0886BEA4(char *, s32);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08858904(char *, char *);

void func_0887EBFC(char *arg0) {
    char *r;
    s32 v;
    u32 c;
    char *g;
    u32 sum;
    u32 s0;
    u8 k;
    u8 *p;
    s32 i;
    char *g7c;
    u32 s1;

    g7c = D_08A62C7C;
    if (*(s16 *) (g7c + 0x688) != 0) {
        if (*(s8 *) (g7c + 0x67D) >= 4) {
            func_088585E8(D_089CC438, g7c + 0x684, 0xB, 0, 0);
        } else if (*(s8 *) (g7c + 0x680) >= 0xD) {
            func_088585E8(D_089CC438, g7c + 0x684, 0xC, 0, 0);
        } else if (*(s8 *) (g7c + 0x681) >= 8) {
            func_088585E8(D_089CC438, g7c + 0x684, 0xD, 0, 0);
        } else if (*(s8 *) (g7c + 0x67E) >= 5) {
            func_088585E8(D_089CC438, g7c + 0x684, 0xE, 0, 0);
        } else if (*(s8 *) (g7c + 0x67F) >= 0xA) {
            func_088585E8(D_089CC438, g7c + 0x684, 0xF, 0, 0);
        }
        if (*(u16 *) (D_08A62C7C + 0x682) != 0) {
            func_088585E8(D_089CC438, D_08A62C7C + 0x684, 7, *(u16 *) (D_08A62C7C + 0x682), 0);
        }
    }
    g = D_089CC438;
    p = (u8 *) (g + 0x6ADD0);
    c = *p;
    if (*(u32 *) (g + 0x4468) / 60 / 60 >= (c + 1) * 100 && c != 0xFF) {
        *p = c + 1;
        func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x14, *(u8 *) (D_089CC438 + 0x6ADD0), 0);
    }
    g7c = D_08A62C7C;
    switch (*(s16 *) (g7c + 0x688)) {
    case 4:
        if (func_0887EB80(arg0) / 60 < 5) {
            func_088585E8(D_089CC438, D_08A62C7C + 0x684, 5, 0, 0);
        }
        if (func_0886A35C(D_08A62C7C, 0) / 30 / 60 == 0) {
            func_088585E8(D_089CC438, D_08A62C7C + 0x684, 6, 0, 0);
        }
        g = D_089CC438;
        sum = 0;
        sum += *(u16 *) (g + 0x67778);
        sum += *(u16 *) (g + 0x6777A);
        sum += *(u16 *) (g + 0x6777C);
        sum += *(u16 *) (g + 0x6777E);
        sum += *(u16 *) (g + 0x67780);
        sum += *(u16 *) (g + 0x67782);
        sum += *(u16 *) (g + 0x67784);
        if (sum != 0 && sum % 100 == 0) {
            func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x16, sum / 100, 0);
        }
        r = func_088DCEBC(D_09A4F0C4, *(u8 *) (D_089CC438 + 0x28));
        if ((*(u16 *) (r + 0x4F6) | (*(u16 *) (r + 0x526) | (*(u16 *) (r + 0x51A) |
             (*(u16 *) (r + 0x502) | *(u16 *) (r + 0x50E))))) == 0) {
            func_088585E8(D_089CC438, D_08A62C7C + 0x684, 4, 0, 0);
        }
        for (s1 = 0x1D6, s0 = 0; s1 < 0x1DF; s1++, s0++) {
            if (func_0884FB38(D_089CC438, s1) == 0 && func_08854BEC(D_089CC438, s0) == 1) {
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x1A, s0, 0);
                func_0884FAC4(D_089CC438, s1);
            }
        }
        for (s0 = 0; s1 <= 0x1E9; s1++, s0++) {
            if (func_0884FB38(D_089CC438, s1) == 0 && func_08854C5C(D_089CC438, s0) == 1) {
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x1D, s0, 0);
                func_0884FAC4(D_089CC438, s1);
            }
        }
        break;
    case 0:
        v = *(u8 *) (D_089CC438 + 0x6A5EA);
        if (v % 10 == 0) {
            func_088585E8(D_089CC438, g7c + 0x684, 0x1C, v, 0);
        }
        break;
    case 1:
        break;
    }
    if (*(s16 *) (D_08A62C7C + 0x688) != 0) {
        c = *(u8 *) (func_088DCEBC(D_09A4F0C4, *(u8 *) (D_089CC438 + 0x28)) + 0x113E);
        if (c != 0) {
            switch (c) {
            case 1:
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 1, 0, c);
                break;
            case 2:
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 3, 0, c);
                break;
            default:
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x12, 0, c);
                break;
            }
            *(u32 *) (D_089CC438 + 0x6AD78) += c;
            p = (u8 *) (D_089CC438 + 0x6AD78);
            if (*(u32 *) p > 999999999) {
                *(u32 *) p = 999999999;
            }
            sum = *(u32 *) (D_089CC438 + 0x6AD78);
            if (c + (sum - c) % 100 >= 100) {
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x17, sum / 100, 0);
            }
        }
        k = 0;
        for (i = 0; i < 4; i++) {
            r = func_088DCEBC(D_09A4F0C4, i);
            if (r == 0) {
                continue;
            }
            if (*(u16 *) (r + 0x1E6) == *(u8 *) (D_089CC438 + 0x28)) {
                continue;
            }
            if (*(u8 *) (r + 0x1E8) == 0xC) {
                continue;
            }
            func_0880C084(D_08A62C7C + k * 18 + 0x6A8, D_09A0B544 + (u8) *(u16 *) (r + 0x1E6) * 200 + 0xBC8, 0x12);
            k++;
            c = *(u8 *) (r + 0x113E);
            if (c != 0) {
                switch (c) {
                case 1:
                    func_088585E8(D_089CC438, D_08A62C7C + 0x684, 1, k, c);
                    break;
                case 2:
                    func_088585E8(D_089CC438, D_08A62C7C + 0x684, 3, k, c);
                    break;
                default:
                    func_088585E8(D_089CC438, D_08A62C7C + 0x684, 0x12, k, c);
                    break;
                }
            }
        }
    }
    func_0880E8F0(D_08A62C7C + 0x6DE, func_0886BEA4(D_08A62C7C, 0));
    func_08858904(D_089CC438, D_08A62C7C + 0x684);
}
