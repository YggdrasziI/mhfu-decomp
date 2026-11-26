/* unit_08838F58: 0x08838F58-0x088392F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * Optimized for speed: the 3-row loop steps its table and colour pointers.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[0xC];
    s16 x;
    s16 y;
    s16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

typedef struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_089CBBEC;
extern s32 D_09B22D70;
extern char D_0893B354;
extern char D_0893B220;
extern Rect D_0893B368;
extern u16 D_09B051C0[];
extern u16 D_0893B36A;
extern u16 D_0893B36C;
extern u16 D_0893B36E;
extern u16 D_09B05D10[];
extern u16 D_09B05560;
extern u16 D_089AC588[];

extern void func_0883488C(char *, s32);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern char *func_09A7B790(s32, u16);
extern void func_08892148(char *, s32, s16, s8, char *, ...);
extern void func_09C240A0(u8, u8, u8, s32, s32, s32);
extern void func_08833290(char *, s32, s32, s32, s32);
extern void func_0882FC50(char *, Rect *, char *, s32);
extern char *func_0885151C(char *, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_08829B58(char *, s32);
extern void func_0882DCA8(char *, s32, s32, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);

void func_08838F58(char *arg0) {
    Box box;
    s8 col[3];
    char *q;
    s32 i;
    s16 y;
    s32 n;
    u32 j;
    u8 k;
    u16 id;

    if (*(u8 *)(arg0 + 0x57E) == 0) {
        func_0883488C(arg0, 1);
        q = *(char **)(arg0 + 0x530);
        func_0882FA24(&box, &D_0893B354, 0, 0, 0);
        func_0882F580(arg0, &box, 0, *(u8 *)(arg0 + 0x57F), 0xFF, 1);
        if ((s32)((*(s32 *)(q + 0x614) & 4) != 0) == 1) {
            n = 0;
            j = 0;
            for (; j < 13; j++) {
                if (*(s8 *)(D_089CC438 + j * 0x70 + 0x69BEC) != 0) {
                    n++;
                }
            }
            if ((u8)n != 0) {
                col[2] = 0;
                col[1] = 0;
                col[0] = 0;
                goto draw;
            }
        }
        col[2] = 9;
        col[1] = 9;
        col[0] = 9;
    draw:
        y = box.y;
        for (i = 0; i < 3; i++, y += box.h) {
            func_08892148(D_08A631A8, box.x, y, col[i], &D_0893B220, func_09A7B790(D_09B22D70, D_09B051C0[i]));
        }
        return;
    }
    k = 3;
    if (*(u8 *)(arg0 + 0x57E) > 2) {
        k++;
    }
    func_09C240A0(*(u8 *)(arg0 + 0x117D), *(u8 *)(arg0 + 0x117A), k, *(s8 *)(arg0 + 0x117B), *(s8 *)(arg0 + 0x117C), 0);
    func_08833290(arg0, 0x10, 2, *(s32 *)(arg0 + 0x118C), 0);
    id = *(u16 *)(arg0 + 0x5FC);
    if (id != 0) {
        if (*(u8 *)(arg0 + 0x57E) == 1 || *(u8 *)(arg0 + 0x57E) == 2 || *(u8 *)(arg0 + 0x57E) == 4 || *(u8 *)(arg0 + 0x57E) == 10) {
            func_0882FC50(D_089CBBEC, &D_0893B368, func_09A7B790(D_09B22D70, D_09B05D10[id]), 0xFF);
        }
        if (*(u8 *)(arg0 + 0x57E) == 3) {
            func_0882FC50(D_089CBBEC, &D_0893B368, func_09A7B790(D_09B22D70, D_09B05D10[*(u16 *)(arg0 + 0x5FC)]), 0xFF);
            func_088920A8(D_08A631A8, (s16)(u16)(D_0893B368.x + D_0893B36C - 0x94), (s16)(u16)(D_0893B36A + D_0893B36E - 0x16), &D_0893B220,
                          func_0885151C(D_089CC438, D_089AC588[*(u8 *)(arg0 + 0x537)]));
        }
    }
    if (*(u8 *)(arg0 + 0x57E) == 10) {
        *(u8 *)(arg0 + 0x589) = 1;
        func_08829B58(arg0, 1);
    } else if (*(u8 *)(arg0 + 0x57E) < 10) {
        func_0882DCA8(D_089CBBEC, 0x138, 0x88, 0xA0, 0x20, 0xFF);
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        func_08892148(D_08A631A8, 0x142, 0x92, 0, &D_0893B220, func_09A7B790(D_09B22D70, D_09B05560));
    }
}
