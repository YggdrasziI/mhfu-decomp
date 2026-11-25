/* unit_088487B8: 0x088487B8-0x08848D30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088487B8 (ULES01213)
 *
 * Optimized for speed: loops are rotated behind a guard.
 */
#pragma optimize_for_size off

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 pad[0x10];
    s32 price;
    u8 pad2[4];
} Item18;

typedef struct {
    u16 id;
    s16 qty;
} Entry;

typedef struct {
    u8 pad[0x10];
    s32 page;
    s32 count;
    Entry e[1];
} List;

extern char *D_08A62CB4;
extern char *D_089CBBEC;
extern char *D_08A631A8;
extern char *D_089CC438;
extern s32 D_09A44C5C;
extern Item18 D_0899D198[];
extern u16 D_0893B710, D_0893B712, D_0893B714;
extern u16 D_0893B718, D_0893B71A, D_0893B71C, D_0893B71E;
extern s16 D_0893B728, D_0893B72A, D_0893B72C, D_0893B72E, D_0893B730, D_0893B732;
extern u16 D_0893B734, D_0893B736;
extern u16 D_0893B738, D_0893B73A, D_0893B73C, D_0893B73E;
extern s16 D_0893B740, D_0893B742, D_0893B744, D_0893B746, D_0893B748, D_0893B74A;
extern s16 D_0893B74C, D_0893B74E, D_0893B750, D_0893B752, D_0893B754;
extern u16 D_089B53CA, D_089B5410, D_089B5412, D_089B5414, D_089B5416, D_089B5418;
extern u16 D_089B541A, D_089B541C;

extern void func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern void func_0882DCA0(char *, s32, s32, s32, s32, s32);
extern char *func_09A63198(s32, u16);
extern s32 func_08890E48(char *, char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern void func_0882E6F0(char *, s32, s32, s32, s32);
extern void func_0882E2C0(char *, u16, u16, u16, s32, s32, s32, s32);
extern char *func_08851528(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_0887D02C(s32, s32, char *, s32);
extern s32 func_0887E9AC(s32, s32, s32);

void func_088487B8(char *arg0) {
    List *m;
    char *s;
    Entry *p;
    s32 i;
    s32 j;
    s32 sum;
    s32 id;
    s32 total;
    char *str;

    if ((s32)((*(s32 *)(*(char **)(arg0 + 0x530) + 0x614) & 0x200) != 0) == 0) {
        *(s32 *)(arg0 + 0x1194) &= ~0x33;
        return;
    }
    m = (List *)(D_08A62CB4 + 0x10);
    s = D_089CBBEC;
    *(u8 *)(s + 0x534) = 10;
    func_08890E08(D_08A631A8, 1);
    func_08825DA8(s);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_0882DCA0(D_089CBBEC, D_0893B718, D_0893B71A, D_0893B71C, D_0893B71E, 0xFF);
    func_0882DCA0(D_089CBBEC, D_0893B738, D_0893B73A, D_0893B73C, D_0893B73E, 0xFF);
    str = func_09A63198(D_09A44C5C, D_089B5410);
    func_08890E48(D_08A631A8, str);
    func_08827918(D_089CBBEC, D_0893B750 + (D_0893B754 >> 1), D_0893B752, str, 0xE, 0x10);
    if (m->count > 10) {
        func_0882E6F0(D_089CBBEC, D_0893B710, D_0893B712, D_0893B714, 0xF0);
    }
    p = &m->e[m->page * 10];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++, p++) {
            if (p->id == 0) {
                break;
            }
            func_0882E2C0(D_089CBBEC, p->id, D_0893B728 + D_0893B730 * i, D_0893B72A + D_0893B732 * j,
                          D_0893B734, D_0893B736, 1, 0xFF);
            func_08891474(D_08A631A8, D_0893B72C + D_0893B730 * i, D_0893B72E + D_0893B732 * j,
                          func_08851528(D_089CC438, p->id));
            func_08891474(D_08A631A8, D_0893B740 + D_0893B730 * i, D_0893B742 + D_0893B732 * j,
                          func_09A63198(D_09A44C5C, D_089B5412), D_0899D198[p->id].price, p->qty);
        }
    }
    func_0887D02C(D_0893B74C, D_0893B74E, func_09A63198(D_09A44C5C, D_089B5414), 0xE);
    m = (List *)(D_08A62CB4 + 0x10);
    sum = 0;
    p = m->e;
    for (i = 0; i < m->count; i++, p++) {
        id = p->id;
        if (id == 0) {
            break;
        }
        sum += p->qty * D_0899D198[id].price;
    }
    total = func_0887E9AC((s32)D_08A62CB4, sum, 1);
    m = (List *)(D_08A62CB4 + 0x10);
    sum = 0;
    p = m->e;
    for (i = 0; i < m->count; i++, p++) {
        id = p->id;
        if (id == 0) {
            break;
        }
        sum += p->qty * D_0899D198[id].price;
    }
    func_08891474(D_08A631A8, D_0893B74C, D_0893B74E, func_09A63198(D_09A44C5C, D_089B5416), sum, total);
    func_0887D02C(D_0893B744, D_0893B746, func_09A63198(D_09A44C5C, D_089B53CA), 0xE);
    func_08891474(D_08A631A8, D_0893B744, D_0893B746, func_09A63198(D_09A44C5C, D_089B541A),
                  *(s32 *)(D_089CC438 + 0x696F0));
    func_0887D02C(D_0893B748, D_0893B74A, func_09A63198(D_09A44C5C, D_089B5418), 0xE);
    func_08891474(D_08A631A8, D_0893B748, D_0893B74A, func_09A63198(D_09A44C5C, D_089B541C),
                  *(s32 *)(D_089CC438 + 0x696E8));
}
