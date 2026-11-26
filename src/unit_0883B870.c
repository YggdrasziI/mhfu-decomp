/* unit_0883B870: 0x0883B870-0x0883BA38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function, a 4 x 3 grid of table texts with a cursor box.
 *
 * The four box globals are `const`: it schedules their loads among the
 * prologue saves. The inner loop keeps its own table index `k` (step 4).
 */


typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern const u16 D_0893B3E8;
extern const u16 D_0893B3EA;
extern const u16 D_0893B3EC;
extern const u16 D_0893B3EE;
extern s16 D_0893B3F0;
extern s16 D_0893B3F2;
extern s16 D_0893B3F4;
extern s16 D_0893B3F6;
extern s16 D_0893B3F8;
extern s16 D_0893B3FA;
extern u16 D_0893B3FC;
extern u16 D_0893B3FE;
extern u16 D_089AD030[];

extern void func_0882DCA8(char *, s32, s32, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern void func_0882F4A4(char *, u16, u16, u16, u16, s32);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);

void func_0883B870(char *p) {
    s32 i;
    s32 j;
    s32 k;
    u16 *tbl;
    s16 row;
    s16 col;
    s32 color;
    u8 sel;

    func_0882DCA8(p, D_0893B3E8, D_0893B3EA, D_0893B3EC, D_0893B3EE, 0xFF);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    sel = *(u8 *)(p + 0x57F);
    row = sel / 4;
    col = sel % 4;
    color = 0x8000C040;
    if (*(u8 *)(p + 0x580) > 0) {
        color = 0x80808080;
    }
    func_0882F4A4(p, D_0893B3F8 + D_0893B3F4 * col, D_0893B3FA + D_0893B3F6 * row,
                  D_0893B3FC, D_0893B3FE, color);
    for (i = 0; i < 4; i++) {
        j = 0;
        k = 0;
        tbl = D_089AD030 + i;
        for (; j < 3; j++, k += 4) {
            func_08891474(D_08A631A8, D_0893B3F0 + D_0893B3F4 * i, D_0893B3F2 + D_0893B3F6 * j,
                          func_0885151C(D_089CC438, tbl[k]));
        }
    }
}
