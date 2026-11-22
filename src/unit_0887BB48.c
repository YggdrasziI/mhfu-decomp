/* unit_0887BB48: 0x0887BB48-0x0887C708 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

extern char *D_089CC438;
extern char *D_08A62C7C;

extern u8 func_08854CCC(char *);
extern u8 func_08854D18(char *);
extern u8 func_08854D64(char *);
extern u8 func_08854D88(char *);
extern u8 func_08854E44(char *);
extern u8 func_08854E68(char *);
extern u8 func_08854E8C(char *);
extern u8 func_08854EB0(char *);
extern u8 func_08854EFC(char *);
extern u8 func_08854F64(char *);
extern u8 func_08854FCC(char *);
extern u8 func_08854FF0(char *);
extern u8 func_08855014(char *);
extern u8 func_08855038(char *);
extern u8 func_08855160(char *);
extern void func_088551F0(char *, s32);
extern u8 func_08855278(char *, s32);
extern s32 func_08856E8C(char *);
extern s32 func_08856F04(char *);
extern u8 func_08856F7C(char *);
extern s32 func_08856FF4(char *);
extern u16 func_0884FF4C(char *, u8);
extern s32 func_0886A30C(char *, s32);
extern u8 func_0887CA4C(char *);
extern u8 func_0887CAFC(char *);
extern u8 func_0887CBAC(char *);
extern u8 func_0887CC28(char *);

#define BIT(n) ((u64)1 << (n))

u64 func_0887BB48(char *arg0) {
    u64 mask = 0;
    u8 n;
    u8 i;

    if (func_08855278(D_089CC438, 0) == 0 && func_08854CCC(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0);
        mask |= BIT(0);
    }
    if (func_08855278(D_089CC438, 1) == 0 && func_08854D18(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 1);
        mask |= BIT(1);
    }
    if (func_08855278(D_089CC438, 2) == 0 && func_08854D64(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 2);
        mask |= BIT(2);
    }
    if (func_08855278(D_089CC438, 3) == 0 && func_08854D88(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 3);
        mask |= BIT(3);
    }
    if (func_08855278(D_089CC438, 4) == 0 && func_0884FF4C(D_089CC438, 0x21) > 0) {
        func_088551F0(D_089CC438, 4);
        mask |= BIT(4);
    }
    if (func_08855278(D_089CC438, 5) == 0 && func_0884FF4C(D_089CC438, 0x4C) > 0) {
        func_088551F0(D_089CC438, 5);
        mask |= BIT(5);
    }
    if (func_08855278(D_089CC438, 6) == 0 && func_0887CA4C(arg0) == 1) {
        func_088551F0(D_089CC438, 6);
        mask |= BIT(6);
    }
    if (func_08855278(D_089CC438, 7) == 0 && func_0887CAFC(arg0) == 1) {
        func_088551F0(D_089CC438, 7);
        mask |= BIT(7);
    }
    if (func_08855278(D_089CC438, 8) == 0 && func_08854EB0(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 8);
        mask |= BIT(8);
    }
    if (func_08855278(D_089CC438, 9) == 0 && func_08854EFC(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 9);
        mask |= BIT(9);
    }
    if (func_08855278(D_089CC438, 0xA) == 0 && func_08854F64(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0xA);
        mask |= BIT(0xA);
    }
    if (func_08855278(D_089CC438, 0xB) == 0 && func_08856E8C(D_089CC438)) {
        func_088551F0(D_089CC438, 0xB);
        mask |= BIT(0xB);
    }
    if (func_08855278(D_089CC438, 0xC) == 0 && func_08856F04(D_089CC438)) {
        func_088551F0(D_089CC438, 0xC);
        mask |= BIT(0xC);
    }
    if (func_08855278(D_089CC438, 0xD) == 0 && func_08856FF4(D_089CC438)) {
        func_088551F0(D_089CC438, 0xD);
        mask |= BIT(0xD);
    }
    if (func_08855278(D_089CC438, 0xE) == 0 && func_0887CBAC(arg0) == 1) {
        func_088551F0(D_089CC438, 0xE);
        mask |= BIT(0xE);
    }
    if (func_08855278(D_089CC438, 0xF) == 0 && func_0887CC28(arg0) == 1) {
        func_088551F0(D_089CC438, 0xF);
        mask |= BIT(0xF);
    }
    if (func_08855278(D_089CC438, 0x18) == 0 && func_08854E44(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x18);
        mask |= BIT(0x18);
    }
    if (func_08855278(D_089CC438, 0x19) == 0 && func_08854E68(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x19);
        mask |= BIT(0x19);
    }
    if (func_08855278(D_089CC438, 0x1A) == 0 && func_08854E8C(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x1A);
        mask |= BIT(0x1A);
    }
    if (func_08855278(D_089CC438, 0x1B) == 0 && func_0886A30C(D_08A62C7C, 1) == 1
        && *(u16 *)(D_089CC438 + 0x6AF12) == 0x2BD9) {
        func_088551F0(D_089CC438, 0x1B);
        mask |= BIT(0x1B);
    }
    if (func_08855278(D_089CC438, 0x1C) == 0 && func_08854FCC(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x1C);
        mask |= BIT(0x1C);
    }
    if (func_08855278(D_089CC438, 0x1D) == 0 && func_08854FF0(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x1D);
        mask |= BIT(0x1D);
    }
    if (func_08855278(D_089CC438, 0x1E) == 0 && func_08855014(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x1E);
        mask |= BIT(0x1E);
    }
    if (func_08855278(D_089CC438, 0x1F) == 0 && func_08855038(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x1F);
        mask |= BIT(0x1F);
    }
    if (func_08855278(D_089CC438, 0x20) == 0 && func_0886A30C(D_08A62C7C, 1) == 1
        && *(u16 *)(D_089CC438 + 0x6AF12) == 0xC9E
        && ((u16 *)(D_08A62C7C + 0x29C))[*(u8 *)(*(char **)(D_08A62C7C + 0x720) + 0x1E8)] > 0) {
        func_088551F0(D_089CC438, 0x20);
        mask |= BIT(0x20);
    }
    if (func_08855278(D_089CC438, 0x21) == 0 && func_0886A30C(D_08A62C7C, 1) == 1
        && *(u16 *)(D_089CC438 + 0x6AF12) == 0xC9F
        && ((u16 *)(D_08A62C7C + 0x29C))[*(u8 *)(*(char **)(D_08A62C7C + 0x720) + 0x1E8)] > 0) {
        func_088551F0(D_089CC438, 0x21);
        mask |= BIT(0x21);
    }
    if (func_08855278(D_089CC438, 0x22) == 0 && func_0886A30C(D_08A62C7C, 1) == 1
        && *(u16 *)(D_089CC438 + 0x6AF12) == 0xCA0
        && ((u16 *)(D_08A62C7C + 0x29C))[*(u8 *)(*(char **)(D_08A62C7C + 0x720) + 0x1E8)] > 0) {
        func_088551F0(D_089CC438, 0x22);
        mask |= BIT(0x22);
    }
    if (func_08855278(D_089CC438, 0x23) == 0 && func_0886A30C(D_08A62C7C, 1) == 1
        && *(u16 *)(D_089CC438 + 0x6AF12) == 0xC8C) {
        func_088551F0(D_089CC438, 0x23);
        mask |= BIT(0x23);
    }
    if (func_08855278(D_089CC438, 0x24) == 0 && func_0884FF4C(D_089CC438, 0x58) > 0) {
        func_088551F0(D_089CC438, 0x24);
        mask |= BIT(0x24);
    }
    if (func_08855278(D_089CC438, 0x25) == 0 && func_08855160(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x25);
        mask |= BIT(0x25);
    }
    if (func_08855278(D_089CC438, 0x26) == 0 && func_08856F7C(D_089CC438) == 1) {
        func_088551F0(D_089CC438, 0x26);
        mask |= BIT(0x26);
    }
    if (func_08855278(D_089CC438, 0x27) == 0 && *(u8 *)(D_089CC438 + 0x6A548) >= 0x14
        && *(u8 *)(D_089CC438 + 0x6A549) >= 0x14) {
        func_088551F0(D_089CC438, 0x27);
        mask |= BIT(0x27);
    }
    if (func_08855278(D_089CC438, 0x29) == 0) {
        s32 b = *(s32 *)(D_089CC438 + 0x677F8);
        s32 a = *(s32 *)(D_089CC438 + 0x677FC);
        if (a == 7 && b == -1) {
            u32 tbl[7] = { 30000, 35000, 35000, 40000, 40000, 45000, 50000 };
            n = 0;
            for (i = 0; i < 7; i++) {
                if (*(u32 *)(D_089CC438 + i * 4 + 0x67800) >= tbl[i]) {
                    n++;
                }
            }
            if (n == 7) {
                func_088551F0(D_089CC438, 0x29);
                mask |= BIT(0x29);
            }
        }
    }
    return mask;
}
