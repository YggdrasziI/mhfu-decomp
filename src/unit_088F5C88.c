/* unit_088F5C88: 0x088F5C88-0x088F61B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws one page of seven lines of a list box: either the names of the
 * 4-byte entries at +0xBC28 (0x1A2 ends the list; a bit mask in arg1 marks
 * the lines to highlight) or, in mode 1 (+0x10), the first names of
 * D_09B05A18. Then the page number and, outside mode 1, a caption built from
 * the selected entry.
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

/* The list box func_0882F580 draws; its template is at D_089B852C. */
typedef struct Box {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u16 rowX;
    /* 0x0E */ u16 rowY;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 count;
    /* 0x14 */ u16 *names;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u16 unk1E;
    /* 0x20 */ u16 unk20;
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
} Box;

typedef struct {
    /* 0x0 */ u16 id;
    /* 0x2 */ u8 kind;
    /* 0x3 */ u8 count;
} Entry;

extern u16 D_089B852C;
extern u16 D_089B852E;
extern u16 D_089B8530;
extern u16 D_089B8532;
extern u8 D_089B8534;
extern u8 D_089B8535;
extern u8 D_089B8536;
extern u8 D_089B8537;
extern u16 D_089B8538;
extern u16 D_089B853A;
extern u16 D_089B853C;
extern u16 D_089B853E;
extern u16 *D_089B8540;
extern s32 D_089B8544;
extern u16 D_089B8548;
extern u16 D_089B854A;
extern u16 D_089B854C;
extern u16 D_089B854E;
extern u16 D_089B8550;
extern u16 D_089B8552;
extern char D_089B8554;
extern char *D_089CBBEC;
extern char *D_08A631A8;
extern char *D_08A631A0;
extern s32 D_09B22D70;
extern u16 D_09B055A2;
extern u16 D_09B056D0[];
extern u16 D_09B05A18[];
extern u16 D_09B05AD8[];

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern void func_0882B624(char *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_0882E6F0(char *, s32, s32, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern int func_08890E08(char *, s32);
extern void func_08891474(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);


typedef struct {
    char pad0[0xBC28];
    Entry entries[0x1A2];
} Menu;

#define M ((Menu *) arg0)
#define ENTRIES(p) ((Entry *) ((p) + 0xBC28))

void func_088F5C88(char *arg0, u32 *arg1) {
    Box box;
    u32 idx;
    s32 j;
    u16 names[8];
    u8 flags[8];
    char text[0x100];
    u32 count;
    s32 k;
    char *temp;
    u32 i;
    char *fmt;
    u32 id;

    box.x = D_089B852C;
    box.y = D_089B852E;
    box.unk4 = D_089B8530;
    box.unk6 = D_089B8532;
    box.unk8 = D_089B8534;
    box.unk9 = D_089B8535;
    box.unkA = D_089B8536;
    box.unkB = D_089B8537;
    box.rowX = D_089B8538;
    box.rowY = D_089B853A;
    box.unk10 = D_089B853C;
    box.count = D_089B853E;
    box.names = D_089B8540;
    box.unk18 = D_089B8544;
    box.unk1C = D_089B8548;
    box.unk1E = D_089B854A;
    box.unk20 = D_089B854C;
    box.unk22 = D_089B854E;
    box.unk24 = D_089B8550;
    box.unk26 = D_089B8552;
    count = 0;
    idx = *(s8 *)(arg0 + 0x14) * 7;
    if (*(s8 *)(arg0 + 0x10) != 1) {
        for (j = 0; j < 7; j++, idx++, count++) {
            id = *(u16 *)(arg0 + idx * 4 + 0xBC28);
            if (id == 0x1A2) {
                break;
            }
            names[count] = D_09B056D0[id];
            if (!((1 << (id & 0x1F)) & arg1[id >> 5])) {
                flags[count] = 1;
            } else {
                flags[count] = 0;
            }
        }
    } else {
        for (k = 0; k < 7; k++, idx++) {
            if (idx < *(u32 *)(arg0 + 0x18)) {
                names[count] = D_09B05A18[idx];
                count++;
            }
        }
    }
    box.names = names;
    box.count = count;
    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xC;
    func_08890E08(D_08A631A8, 3);
    func_08825DA8(temp);
    func_0882F580(D_089CBBEC, &box, func_09A7B790(D_09B22D70, D_09B055A2), *(s8 *)(arg0 + 0x11), 0xFF, 1);
    func_08891474(D_08A631A8, box.x + 0x3F, box.y + 8, &D_089B8554, *(s8 *)(arg0 + 0x14) + 1, *(s8 *)(arg0 + 0x1C));
    if (*(s8 *)(arg0 + 0x1C) > 1) {
        func_0882E6F0(D_089CBBEC, box.x, (u16) (box.y + 8), 0x6C, 0xF0);
    }
    if (*(s8 *)(arg0 + 0x10) == 1) {
        return;
    }
    if (*(s32 *)(D_08A631A0 + 0xF7A554) & 0x10) {
        for (i = 0; i < count; i++) {
            if (flags[i] != 0) {
                func_0882B624(D_089CBBEC, (u16) (box.rowX - 10), (u16) (box.rowY + i * 16), 0xC0, 0x30, 0, 0x1B9, 0);
            }
        }
    }
    idx = *(s8 *)(arg0 + 0x11) + *(s8 *)(arg0 + 0x14) * 7;
    if (idx >= 0x1A2) {
        return;
    }
    if (ENTRIES(arg0)[idx].id == 0x1A2) {
        return;
    }
    if (M->entries[idx].count != 0) {
        fmt = func_09A7B790(D_09B22D70, D_09B05AD8[M->entries[idx].kind]);
        func_0880E8F0(text, fmt, M->entries[idx].count);
    } else {
        fmt = func_09A7B790(D_09B22D70, D_09B05AD8[M->entries[idx].kind]);
        func_0880E8F0(text, fmt);
    }
    switch (*(s32 *)(D_08A631A0 + 0xF7A574)) {
    case 3:
    case 5:
        box.x = 0x158;
        func_0882DCA0(D_089CBBEC, box.x - 0x58, box.y + 0x98, 0xDE, 0x40, 0xFF);
        break;
    default:
        func_0882DCA0(D_089CBBEC, box.x - 0x58, box.y + 0x98, 0xD4, 0x40, 0xFF);
        break;
    }
    func_08891474(D_08A631A8, box.x - 0x50, box.y + 0xA0, text);
}
