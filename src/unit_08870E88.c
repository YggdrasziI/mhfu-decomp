/* unit_08870E88: 0x08870E88-0x088711C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A62C7C;
extern char *D_09A4F0D0;

extern void func_0886D374(char *, u16);
extern s32 func_088564F8(char *);
extern s32 func_088DDFE8(char *, u8);
extern void func_088DDE20(char *, u8);
extern void func_088DE0B8(char *, u8, s32, s32);
extern s32 *func_088697D4(char *, u16, s32, s8);

static inline void play(u8 id) {
    char *t = D_09A4F0D0;

    if (*(u8 *)(t + 0x214)) {
        if (func_088DDFE8(t, id)) {
            func_088DDE20(t, id);
            return;
        }
    }
    func_088DE0B8(t, id, 0, -1);
}

static inline int in_first(char *p, u16 id) {
    if (!(*(u32 *)(p + 0x28) & 0x1000010) && (id == 0x29 || id == 0xC2 || id == 0x36 || id == 0x94 || id == 0x10 || id == 0x97 || id == 0x1 ||
        id == 0x6E || id == 0x5C || id == 0x65 || id == 0xCD || id == 0xE3)) {
        return 1;
    }
    return 0;
}

static inline int in_second(char *p, u16 id) {
    if ((*(u32 *)(p + 0x28) & 0x10) && (id == 0x15 || id == 0x8C || id == 0x97 || id == 0xA1 || id == 0x6E || id == 0x62 || id == 0xF7)) {
        return 1;
    }
    return 0;
}

void func_08870E88(char *arg0) {
    u16 id;
    s32 *p;
    s32 i;

    id = *(u16 *)(D_089CC438 + 0x6AF0E);
    func_0886D374(D_08A62C7C, id);
    if (id == func_088564F8(D_089CC438)) {
        play(0x12);
    }
    if (in_first(arg0, id)) {
        play(0xA);
    }
    if (in_second(arg0, id)) {
        play(0x4A);
    }
    p = func_088697D4(arg0, id, 0, *(s8 *)(arg0 + 0x20));
    *(s8 *)(arg0 + 0x82) = *(s8 *)(arg0 + 0x20);
    if (p != 0) {
        for (i = 0; i < 4; i++, p++) {
            if (*p != -1) {
                play(*p);
            }
        }
    }
}
