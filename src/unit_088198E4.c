/* unit_088198E4: 0x088198E4-0x08819CF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08818F74 and text_08819CF8).
 *
 * Optimized for speed: the 8-row loop counts down. Same family as
 * func_08818C94 (a Box, then one coloured line per row).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[0xC];
    u16 x;
    s16 y;
    s16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

typedef struct {
    u16 id;
    s16 count;
} Entry;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C50;
extern u16 D_089AC870[];
extern u16 D_089AC876;
extern u16 D_089AC878;
extern s16 D_08938554[];
extern u8 D_0899D198[][24];
extern char D_0893854C;
extern char D_08938478;
extern char D_0893855C;
extern char D_0893B0E0;

extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern s32 func_08828EEC(char *);
extern s32 func_08828F14(char *, u16);
extern s16 func_08828F3C(char *, Entry *);
extern s32 func_0885B3A0(char *, s16, s32, s32);
extern s32 func_0885B5B8(char *, s32, s32, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DFC(char *, s16, s16);
extern int func_0889134C(char *, char *, ...);
extern void func_08819CF8(char *, s32);

/* y is read before the row pointer is set, and the pointer is set in the
 * for header after the counter: this gives the parameters the saved
 * registers of y, flags & 0xC, colour and alt.
 */
void func_088198E4(char *arg0, Entry *list, s32 pos, s32 sel, s32 flags, s32 title) {
    Box box;
    char text[0x20];
    s32 first;
    s16 r;
    s16 y;
    s32 cur;
    s32 page;
    s32 i;
    s8 colour;
    s8 alt;
    Entry *e;

    page = pos / 8;
    first = page * 8;
    func_0880E8F0(text, &D_0893854C, func_0885151C(D_089CC438, D_089AC870[flags & 1]));
    func_0882FA24(&box, &D_0893B0E0, text, 0, D_08938554[title]);
    if (sel != 0) {
        box.color = sel;
        cur = pos - first;
    } else {
        cur = -1;
    }
    func_0882F580(arg0, &box, text, cur, 0xFF, 0);
    if (flags & 0x10) {
        func_0882FB38(arg0, &box, page, 3, 0, 0);
    }
    y = box.y;
    for (i = 8, e = list + first; i > 0; i--) {
        colour = 0;
        alt = 2;
        if (flags & 0xC) {
            if ((u8) func_08828EEC(arg0) == 0) {
                if (flags & 8) {
                    if ((u8) func_08828F14(arg0, first) == 1) {
                        colour = 5;
                    } else if (func_0885B5B8(D_08A62C50, *(s16 *)(arg0 + 0x5AC), (s16) e->id, 0, 0, 0) == 0) {
                        colour = 10;
                        alt = 13;
                    }
                } else if ((u8) func_0885B3A0(D_08A62C50, e->id, 0, 0) == 0) {
                    colour = 10;
                    alt = 13;
                } else if ((u8) func_08828F14(arg0, first) == 1) {
                    colour = 5;
                }
            } else {
                r = func_08828F3C(arg0, e);
                if (r >= 0) {
                    switch (r) {
                    case 0:
                        colour = alt;
                        break;
                    case 1:
                        colour = 6;
                        break;
                    }
                } else if ((u8) func_08828F14(arg0, first) == 1) {
                    colour = 5;
                } else {
                    colour = 10;
                    alt = 13;
                }
            }
        }
        func_08890E38(D_08A631A8, colour);
        func_08890DFC(D_08A631A8, box.x, y);
        if (e->id == 0) {
            func_0889134C(D_08A631A8, &D_08938478, func_0885151C(D_089CC438, D_089AC876));
        } else {
            func_0889134C(D_08A631A8, &D_08938478, func_08851528(D_089CC438, e->id));
            if (D_0899D198[e->id][3] > 1) {
                func_08890DFC(D_08A631A8, box.x + 0x72, y);
                if (D_0899D198[e->id][3] == 0xFF) {
                    func_0889134C(D_08A631A8, &D_08938478, func_0885151C(D_089CC438, D_089AC878));
                } else {
                    if (e->count >= D_0899D198[e->id][3]) {
                        func_08890E38(D_08A631A8, alt);
                    }
                    func_0889134C(D_08A631A8, &D_0893855C, e->count);
                }
            }
        }
        y += box.h;
        e++;
        first++;
    }
    if (flags & 0x40) {
        func_08819CF8(arg0, 1);
    }
}
