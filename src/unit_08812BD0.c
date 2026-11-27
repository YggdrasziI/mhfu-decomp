/* unit_08812BD0: 0x08812BD0-0x08812DB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern s8 func_08815024(char *);
extern void func_088868AC(char *, u8);
extern void func_08814D84(char *);
extern s32 func_08815108(char *, u8 *, s32);
extern void func_08886B2C(char *);
extern void func_08814E18(char *);
extern void func_08815384(char *);

void func_08812BD0(char *p) {
    s32 i;
    char *e;

    *(u8 *)(p + 0xA88) = 0;
    *(u8 *)(p + 0xB14) = 0;
    *(s16 *)(p + 0xB18) = 0;
    *(s16 *)(p + 0xB16) = 0;
    *(u8 *)(p + 0xA8B) = 0;
    if (*(u8 *)(p + 0xB10) == 0) {
        *(u8 *)(p + 0xB10) += 1;
        *(u8 **)(p + 0xA90) = 0;
        *(u8 *)(p + 0xA94) = 0xFF;
        *(u8 *)(p + 0xAAB) = 0xFF;
        func_08815024(p);
        *(u8 *)(p + 0xAAB) = (*(u8 **)(p + 0xA90))[1];
        *(u8 *)(p + 0xA8D) = 0;
        if ((*(u8 **)(p + 0xA90))[2] == 0) {
            *(u8 *)(p + 0xA8D) = 0;
        } else {
            *(u8 *)(p + 0xA8D) = 2;
        }
        *(u8 *)(p + 0xA8C) = *(u8 *)(p + 0xA8D);
        for (i = 0, e = p; i < 6; i++, e += 0x1A0) {
            func_088868AC(e + 0xB0, i);
        }
        *(s16 *)(p + 0xA74) = 0;
        *(s16 *)(p + 0xA72) = 0;
        *(s16 *)(p + 0xA70) = 0;
        *(s16 *)(p + 0xA78) = 0;
        *(s16 *)(p + 0xA76) = 0;
    } else {
        func_08814D84(p);
    }
    if (*(u8 *)(p + 0xAAB) == 0) {
        if (func_08815024(p) > 0) {
            *(u8 *)(p + 0xA94) = *(u8 *)(p + 0xAAB);
            *(u8 *)(p + 0xAAB) = (*(u8 **)(p + 0xA90))[1];
            *(u8 *)(p + 0xA8B) = 1;
        }
    } else if ((u8)func_08815108(p, *(u8 **)(p + 0xA90), 2)) {
        *(u8 *)(p + 0xA94) = *(u8 *)(p + 0xAAB);
        *(u8 *)(p + 0xA8B) = 1;
        if (func_08815024(p) >= 0) {
            *(u8 *)(p + 0xAAB) = (*(u8 **)(p + 0xA90))[1];
        }
    }
    *(u8 *)(p + 0xA8C) = *(u8 *)(p + 0xA8D);
    switch ((*(u8 **)(p + 0xA90))[2]) {
    case 0:
        *(u8 *)(p + 0xA8D) = 0;
        break;
    case 1:
    case 2:
    case 3:
        *(u8 *)(p + 0xA8D) = 2;
        break;
    }
    for (i = 0, e = p; i < 6; i++, e += 0x1A0) {
        func_08886B2C(e + 0xB0);
    }
    func_08814E18(p);
    *(u8 *)(p + 0xA81) = 0;
    func_08815384(p);
}
