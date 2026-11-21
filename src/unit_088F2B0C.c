/* unit_088F2B0C: 0x088F2B0C-0x088F368C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * A page over ten slots of 0x1090 bytes at +0x188 (current one: +0xA729).
 * State (+0xD): 0 looks for the first slot whose low six bits of +0x10 are
 * all set, 1 shows it (delete / open the list / ask to erase), 2 is the list
 * of nine entries of func_088F368C, 3 a yes/no question (+0x25), 4 the
 * confirmation. The second half draws the state.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define SLOT_SIZE 0x1090
#define CUR(a) (*(s8 *)((a) + 0xA729))
#define SLOT(a, i) ((a) + 0x188 + (i) * SLOT_SIZE)
#define SLOT_FULL(a, i) ((*(u16 *)(SLOT(a, i) + 0x10) & 0x3F) == 0x3F)

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 *D_09B22D70;
extern u16 D_09B05592;
extern u16 D_09B0559C;
extern u16 D_09B0559E;
extern u16 D_09B055A0;
extern u16 D_09B055AE;
extern u16 D_09B055B0;
extern u16 D_09B055B6;
extern u16 D_09B055B8;

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern int func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern s32 func_088542EC(char *, char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_088BA2E0(s32, s32, u8, s32);
extern void func_088BA664(s32, s32);
extern void func_088F383C(char *, u16, char *);
extern void func_088F6450(char *, char *, s8);
extern char *func_09A7B790(s32 *, u16);
extern void memset(void *, s32, s32);

static inline s32 count_full(char *arg0) {
    char *slot = arg0 + 0x188;
    s32 n = 0;
    s32 i;

    for (i = 0; i < 10; i++, slot += SLOT_SIZE) {
        if ((*(u16 *)(slot + 0x10) & 0x3F) == 0x3F) {
            n++;
        }
    }
    return n;
}

static inline s32 count_used(void) {
    char *p = D_089CC438 + 0x4A58;
    s32 n = 0;
    s32 i;

    for (i = 0; i < 0x60; i++, p += 0x1078) {
        if (*(u16 *)p != 0) {
            n++;
        }
    }
    return n;
}

s32 func_088F2B0C(char *arg0, u16 arg1) {
    char *temp;
    char *str;

    switch (*(s8 *)(arg0 + 0xD)) {
    case 0:
        CUR(arg0) = 0;
        while (!SLOT_FULL(arg0, CUR(arg0))) {
            CUR(arg0)++;
        }
        func_08883988(D_08A62D8C, 3, 0x1B, 0, 0, 0, 0, 0, 0);
        *(s8 *)(arg0 + 0xD) = 1;
        *(s8 *)arg0 = 1;
    case 1:
        if (arg1 & 0x4000) {
            if (func_088542EC(D_089CC438, SLOT(arg0, CUR(arg0)) + 0x18) != 0) {
                memset(SLOT(arg0, CUR(arg0)), 0, SLOT_SIZE);
                if (count_full(arg0) > 0) {
                    while (!SLOT_FULL(arg0, CUR(arg0))) {
                        CUR(arg0)++;
                    }
                } else {
                    *D_09B22D70 = 0;
                    *(s8 *)(arg0 + 0xA728) = 0;
                    *(s8 *)arg0 = 0;
                }
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        } else if (arg1 & 0x8000) {
            *(s8 *)(arg0 + 0xD) = 2;
            *(s8 *)(arg0 + 0xE) = 0;
            *(s8 *)(arg0 + 0xA72C) = 0;
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if (arg1 & 0x2000) {
            *(s8 *)(arg0 + 0xD) = 3;
            *(u8 *)(arg0 + 0x25) = 0;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 2:
        if (arg1 & 0x100) {
            *(s8 *)(arg0 + 0xE) = *(s8 *)(arg0 + 0xE) - 1;
            if (*(s8 *)(arg0 + 0xE) < 0) {
                *(s8 *)(arg0 + 0xE) = 8;
            }
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
        } else if (arg1 & 0x200) {
            *(s8 *)(arg0 + 0xE) = *(s8 *)(arg0 + 0xE) + 1;
            if (*(s8 *)(arg0 + 0xE) > 8) {
                *(s8 *)(arg0 + 0xE) = 0;
            }
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            *(s8 *)(arg0 + 0x10) = 0;
            *(s8 *)(arg0 + 0x1E) = 0;
            *(s8 *)(arg0 + 0xF) = 0;
        } else if (arg1 & 0x2000) {
            *(s8 *)(arg0 + 0xD) = 1;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else {
            func_088F383C(arg0, arg1, SLOT(arg0, CUR(arg0)) + 0x18);
        }
        break;
    case 3:
        if (arg1 & 0x80) {
            if (*(u8 *)(arg0 + 0x25) == 0) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 0x25) = 1;
        } else if (arg1 & 0x20) {
            if (*(u8 *)(arg0 + 0x25) == 1) {
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
            *(u8 *)(arg0 + 0x25) = 0;
        } else if ((arg1 & 0x4000) && *(u8 *)(arg0 + 0x25) != 0) {
            *(s8 *)(arg0 + 0xD) = 4;
            memset(SLOT(arg0, CUR(arg0)), 0, SLOT_SIZE);
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        } else if (((arg1 & 0x4000) && *(u8 *)(arg0 + 0x25) == 0) || (arg1 & 0x2000)) {
            *(s8 *)(arg0 + 0xD) = 1;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 4:
        if (arg1 & 0x4000) {
            *(s8 *)(arg0 + 0xD) = 1;
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            if (count_full(arg0) > 0) {
                while (!SLOT_FULL(arg0, CUR(arg0))) {
                    CUR(arg0)++;
                }
            } else {
                *D_09B22D70 = 0;
                *(s8 *)(arg0 + 0xA728) = 0;
                *(s8 *)arg0 = 0;
                return arg1 & 8;
            }
        }
        break;
    }
    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    switch (*(s8 *)(arg0 + 0xD)) {
    case 1:
        func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
        func_08890DE8(D_08A631A8, 0x10, 0xE);
        func_088912BC(D_08A631A8, 0xD4, 0x68, SLOT(arg0, CUR(arg0)) + 0x18);
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        func_08827918(D_089CBBEC, 0xF0, 0x58, func_09A7B790(D_09B22D70, D_09B055AE), 0xE, 0x10);
        str = func_09A7B790(D_09B22D70, D_09B055B6);
        func_0880E8F0(arg0 + 0x88, str, count_full(arg0));
        func_08827918(D_089CBBEC, 0xF0, 0x88, arg0 + 0x88, 0xE, 0x10);
        str = func_09A7B790(D_09B22D70, D_09B055B8);
        func_0880E8F0(arg0 + 0x88, str, 0x60 - count_used());
        func_08827918(D_089CBBEC, 0xF0, 0x98, arg0 + 0x88, 0xE, 0x10);
        func_0882A9DC(D_089CBBEC, 0x95, 0xA8, 0x33);
        func_0882A9DC(D_089CBBEC, 0xDB, 0xA8, 0x35);
        func_0882A9DC(D_089CBBEC, 0x121, 0xA8, 0x32);
        func_08891474(D_08A631A8, 0xA3, 0xAA, func_09A7B790(D_09B22D70, D_09B055B0));
        func_08891474(D_08A631A8, 0xE9, 0xAA, func_09A7B790(D_09B22D70, D_09B05592));
        func_08891474(D_08A631A8, 0x12F, 0xAA, func_09A7B790(D_09B22D70, D_09B0559C));
        break;
    case 2:
        func_088F6450(arg0, SLOT(arg0, CUR(arg0)) + 0x18, *(s8 *)(arg0 + 0xE));
        break;
    case 3:
        func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
        func_08827918(D_089CBBEC, 0xF0, 0x68, func_09A7B790(D_09B22D70, D_09B0559E), 0xE, 0x10);
        func_088BA2E0(0xB8, 0xA8, *(u8 *)(arg0 + 0x25), 1);
        break;
    case 4:
        func_0882DCA0(D_089CBBEC, 0x78, 0x4C, 0xF0, 0x80, 0xFF);
        func_08827918(D_089CBBEC, 0xF0, 0x68, func_09A7B790(D_09B22D70, D_09B055A0), 0xE, 0x10);
        func_088BA664(0x9C, 0xA8);
        break;
    }
    return arg1 & 8;
}
