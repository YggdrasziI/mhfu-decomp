/* unit_0883AE3C: 0x0883AE3C-0x0883B190 (ULES01213)
 *
 * Bounds (hypothesis): one function, two slot scans then a result message.
 * Speed setting; saved registers set by the declaration order of the locals.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_09A0B544;
extern s32 D_08A62D8C;
extern s32 D_09B22D70;
extern char *D_089CBBEC;
extern u16 D_09B05D0C;
extern u16 D_09B05D08;
extern u16 D_09B05D06;

extern char *func_088DCEBC(s32, u8);
extern char *func_0889D848(s32, char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0884FB38(char *, s32);
extern char *func_09A7B790(s32, u16);
extern void func_088307BC(char *, char *);
extern s32 func_0880BFF0(void *, void *, s32);
extern void memcpy(void *, void *, s32);
extern void func_0889D8A8(s32, char *, s32, s32 *);
extern void func_09AAEE70(char *, s32, s32, s32);

void func_0883AE3C(char *a, char *b) {
    char *key;
    s32 free;
    s32 found;
    char *p;
    s32 i;
    s32 j;
    char *g;

    g = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    if (*(u8 *)(g + 0x62C) > 0) {
        return;
    }
    key = func_0889D848(D_09A0B544, b);
    if (key == 0 || *(u8 *)(b + 0xBF) == 5) {
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        return;
    }
    if (func_0884FB38(D_089CC438, 0x25) == 0) {
        func_088307BC(D_089CBBEC, func_09A7B790(D_09B22D70, D_09B05D0C));
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        *(u8 *)(g + 0x62C) = 0x5A;
        return;
    }
    *(s32 *)(g + 0x5D8) = -1;
    free = 0;
    found = 0;
    p = D_089CC438 + 0x696FC;
    for (i = 0; i < 5; i++, p += 0x70) {
        if (*(s8 *)p != 0) {
            if (func_0880BFF0(key, p + 0x60, 0x10) == 0) {
                found = 1;
            }
        }
    }
    p = D_089CC438 + 0x69BEC;
    for (j = 0; j < 13; j++, p += 0x70) {
        if (*(s8 *)p != 0) {
            if (func_0880BFF0(key, p + 0x60, 0x10) == 0) {
                found = 1;
            }
        } else if (j >= 3) {
            free = 1;
            if (*(s32 *)(g + 0x5D8) < 0) {
                *(s32 *)(g + 0x5D8) = j;
            }
        }
    }
    if (found) {
        func_088307BC(D_089CBBEC, func_09A7B790(D_09B22D70, D_09B05D08));
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        *(u8 *)(g + 0x62C) = 0x5A;
        return;
    }
    if (!free) {
        func_088307BC(D_089CBBEC, func_09A7B790(D_09B22D70, D_09B05D06));
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        *(u8 *)(g + 0x62C) = 0x5A;
        return;
    }
    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
    *(u8 *)(a + 0x580) = 0x96;
    memcpy(g + 0x5DC, key, 0x10);
    func_0889D8A8(D_09A0B544, b, 0x11, 0);
    func_09AAEE70(g, 0, 6, 0);
    *(u8 *)(a + 0x57E) = 1;
}
