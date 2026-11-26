/* unit_0882A43C: 0x0882A43C-0x0882A660 (ULES01213)
 *
 * Bounds (hypothesis): 1 small state machine drawing a square and a diamond.
 *
 * The globals read in states 0 and 1 are declared const: it lets their loads
 * move above the byte stores, as in the original.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 state;
    u8 pad1;
    u8 unk2;
    u8 pad3;
    s16 x;
    s16 y;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} Obj;

extern const s16 D_089386FC;
extern const s16 D_089386FE;
extern s16 D_08938700;
extern const s16 D_08938702;
extern const s16 D_08938704;
extern s16 D_08938706;

extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);
extern void func_0882CC9C(char *, s16 *, s32, s32, s32, s32);

void func_0882A43C(char *arg0, Obj *o) {
    s16 pts[8];
    s32 w;

    switch (o->state) {
    case 0:
        if (o->unk8 <= 0) {
            o->state++;
            o->unk9 = D_089386FC;
            o->unkA = D_089386FE;
            o->unkB = D_08938702;
        } else {
            o->unk8--;
        }
        break;
    case 1:
        o->state++;
        o->unk8 = D_08938704;
        o->unkB += D_08938702;
        pts[0] = o->x - (o->unkB >> 1);
        pts[1] = o->y;
        pts[2] = o->x;
        pts[3] = o->y - (o->unkB >> 1);
        pts[4] = o->x;
        pts[5] = o->y + (o->unkB >> 1);
        pts[6] = o->x + (o->unkB >> 1);
        pts[7] = o->y;
        func_0882CC9C(arg0, pts, 0xF0, 0xF0, 0x80, 0x7F);
        break;
    case 2:
        if (o->unkA - D_08938700 <= 0) {
            o->state++;
        } else {
            o->unkA -= D_08938700;
            w = o->unk9;
            func_0882C11C(arg0, o->x - (w >> 1), o->y - (w >> 1), (s16)w, (s16)w,
                          0xF0, 0xF0, 0x80, o->unkA, 0x81);
            pts[0] = o->x - (o->unkB >> 1);
            pts[1] = o->y;
            pts[2] = o->x;
            pts[3] = o->y - (o->unkB >> 1);
            pts[4] = o->x;
            pts[5] = o->y + (o->unkB >> 1);
            pts[6] = o->x + (o->unkB >> 1);
            pts[7] = o->y;
            func_0882CC9C(arg0, pts, 0xF0, 0xF0, 0x80, 0x7F);
            if (o->unkB > D_08938706) {
                o->unkB -= D_08938706;
            }
        }
        break;
    case 3:
        o->state++;
        o->unk2 = 0;
        break;
    }
}
