/* unit_08838640: 0x08838640-0x08838894 (ULES01213) */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad0[0xA];
    u8 unkA;
    char padB;
    s16 x;
    s16 y;
    char pad10[0x18];
} Box;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u16 unkC;
    u16 unkE;
    s32 unk10;
} Rec;

extern char *D_09B22D70;
extern char *D_089CC438;
extern u16 D_089AC8CE;
extern u16 D_089AC8C6;
extern char D_0893B218[];
extern char D_0893B318[];
extern Rec D_0893B32C;

extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FC50(char *, Rec *, char *, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern void func_0881B9A0(char *, s16, s16, s32, u8, s32, u8);
extern void func_08838894(char *, s32, char *, s16, s16);

void func_08838640(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *p = D_09B22D70 + 0xA888;
    Box box;
    char text[0x40];
    Rec rec;
    s32 sel = arg4 & 0xF;
    u8 n;

    func_0880E8F0(text, D_0893B218, func_0885151C(D_089CC438, D_089AC8CE));
    func_0882FA24(&box, D_0893B318, text, arg2, arg3);
    if (*(u8 *)(p + 0x1E) == 0) {
        rec = D_0893B32C;
        box.unkA = 0xA;
        func_0882F580(arg0, &box, text, -1, 0xFF, 0);
        rec.unkA = 0xA;
        func_0882FC50(arg0, &rec, func_0885151C(D_089CC438, D_089AC8C6), 0xFF);
    } else {
        func_0882F580(arg0, &box, text, -1, 0xFF, 0);
        n = *(u8 *)(p + 0x20);
        if (n > 1) {
            func_0882FB38(arg0, &box, (u8)sel, n, 0, 0);
        }
        func_0881B9A0(arg0, box.x, box.y, sel, *(u8 *)(p + 0x1F), 9, *(u8 *)(p + 0x13));
        func_0882FC50(arg0, &D_0893B32C, func_0885151C(D_089CC438, D_089AC8C6), 0xFF);
        func_08838894(arg0, arg1, p + 0x12, (s16)D_0893B32C.unkC, D_0893B32C.unkE + D_0893B32C.unk10);
    }
}
