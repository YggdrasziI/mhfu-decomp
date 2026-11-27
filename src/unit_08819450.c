/* unit_08819450: 0x08819450-0x088197A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed (sets the saved registers of x, y and the record).
 * The two early "mode = 0" exits are one || guard; the 4-slot loop is a
 * do/while entered without a guard.
 */

#pragma optimize_for_size off
typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0[0x16];
    u16 unk16;
} Item;

typedef struct {
    u8 kind;
    s8 count;
} Slot;

typedef struct {
    u8 unk0;
    u8 unk1[7];
    Slot slot[4];
} Rec;

typedef struct {
    s16 x;
    s16 y;
} Pos;

extern char *D_089CC438;
extern char *D_08A631A8;
extern Item D_0899D198[];
extern Rec D_089779D4[];
extern Pos D_0893AF54[];
extern u16 D_089ACC70[];
extern u16 D_089AC87C;
extern u16 D_089AC87E;
extern u16 D_089AC880;
extern u16 D_089AC882;
extern u16 D_089AC9D2;
extern char D_08938478;

extern char *func_0885151C(char *, u16);
extern char *func_08851534(char *, u16);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern void func_08890DFC(char *, s16, s16);
extern void func_08892004(char *, char *, ...);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern int func_0889134C(char *, char *, ...);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_08819450(s32 arg0, u16 id, s16 x, s16 y, u8 mode) {
    Item *item;
    Rec *rec;
    Slot *slot;
    s32 i;
    Pos *pos;

    func_08890DE8(D_08A631A8, 14, 14);
    item = &D_0899D198[id];
    if (item->unk16 == 0 || (s8)mode < 0) {
        mode = 0;
    } else {
        mode = (s8)mode & 3;
        func_08890E38(D_08A631A8, 0);
        func_08890DFC(D_08A631A8, x + 0x8C, y + 0x1C);
        if ((u8)mode == 0) {
            func_08892004(D_08A631A8, &D_08938478, func_0885151C(D_089CC438, D_089AC880));
        } else {
            func_08892004(D_08A631A8, &D_08938478, func_0885151C(D_089CC438, D_089AC882));
        }
    }
    func_08890E38(D_08A631A8, 0);
    switch ((u8)mode) {
    case 0:
        func_088920A8(D_08A631A8, x, y, &D_08938478, func_08851534(D_089CC438, id));
        break;
    case 1:
        rec = &D_089779D4[item->unk16];
        slot = rec->slot;
        i = 0;
        pos = D_0893AF54;
        do {
            func_08890DFC(D_08A631A8, x + pos->x, y + pos->y);
            if (slot->kind == 0) {
                if (i == 0) {
                    func_0889134C(D_08A631A8, &D_08938478, func_0885151C(D_089CC438, D_089AC9D2));
                }
                break;
            }
            func_08890DE8(D_08A631A8, 12, 14);
            func_0889134C(D_08A631A8, &D_08938478, func_0885151C(D_089CC438, D_089ACC70[slot->kind]));
            if (slot->kind != 1) {
                func_08890DE8(D_08A631A8, 14, 14);
                func_08890DFC(D_08A631A8, x + pos->x + 0x3C, y + pos->y);
                func_0889134C(D_08A631A8, func_0885151C(D_089CC438, D_089AC87E), slot->count);
            }
            i++;
            pos++;
            slot++;
        } while (i < 4);
        func_088915B0(D_08A631A8, x, y + 0x1C, 5, func_0885151C(D_089CC438, D_089AC87C), rec->unk0);
        break;
    }
}
