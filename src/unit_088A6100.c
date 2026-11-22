/* unit_088A6100: 0x088A6100-0x088A658C (ULES01213)
 *
 * Bounds (hypothesis): 1 function after func_088A6088 (now in C)
 * and before unit_088A658C. Speed setting with loop unrolling off: the
 * byte-wise clear stays one store per pass while the register allocation
 * spills arg0, arg1 and ret as in the original. The record type switch
 * (cases 0-12) uses a jump table, the original's jtbl_08931F68.
 */

#pragma optimize_for_size off
#pragma opt_unroll_loops off

#include "unk_msg.h"

typedef struct {
    u8 type;
    char pad1[3];
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    s16 unkE;
    s32 unk10;
    u8 unk14;
    char pad15;
    u16 next;
    u16 unk18;
} Rec;

typedef struct {
    u32 flags;
    s32 unk4;
    s32 v8;
    s32 vC;
    s32 v10;
    s32 v14;
    s32 v18;
    s32 v1C;
    s32 v20;
    s32 v24;
    s32 v28;
    s32 v2C;
    s32 v30;
    s32 v34;
    s32 v38;
} Ovr;

typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    s32 unk14;
    s32 unk18;
} Buf;

extern Rec *func_088A6040(s32, u32);
extern s32 func_088A6088(Rec *, Buf *, s32);
extern s32 func_088A678C(Buf *);
extern s32 func_088A6780(Buf *);

s32 func_088A6100(u16 arg0, u16 arg1, Ovr *arg2) {
    Buf b;
    Rec *rec;
    s32 ret;
    s32 t;
    u32 mask;
    u32 bit;
    s8 mode;

    clear((char *) &b, sizeof(Buf));
    ret = 0;
    for (;;) {
        rec = func_088A6040(arg0, arg1);
        if (rec == 0) {
            return 0;
        }
        b.unk0 = rec->unk4;
        b.unk4 = arg0;
        b.unk5 = rec->unk7;
        b.unk8 = rec->unkC;
        b.unkA = rec->unkD;
        b.unkC = rec->unkE;
        b.unk3 = rec->unk9;
        b.unk6 = rec->unkA;
        b.unk7 = rec->unkB;
        b.unk14 = rec->unk10;
        b.unk2 = rec->unk8;
        b.unk10 = rec->unk14;
        b.unk11 = rec->unk18;
        b.unk5 += arg2->v8;
        b.unk6 += arg2->vC;
        b.unk7 += arg2->v10;
        b.unk3 += arg2->v1C;
        b.unk8 += arg2->v20;
        b.unkA += arg2->v24;
        b.unkC += arg2->v28;
        b.unk14 += arg2->v14;
        b.unk10 += arg2->v18;
        b.unk13 += arg2->v30;
        b.unk2 |= arg2->v34;
        t = b.unk11 + arg2->v38;
        if (t < 0) {
            b.unk11 = 0;
        } else if (t > 0xFF) {
            b.unk11 = 0xFF;
        } else {
            b.unk11 = t;
        }
        mode = (arg2->flags & 0x80000000) != 0;
        mask = arg2->flags & 0x7FFFFFFF;
        bit = 1;
        if (mask != 0) do {
            switch (mask & bit) {
            case 2:
                b.unk5 = (mode == 1) ? arg2->v8 : b.unk5;
                break;
            case 4:
                b.unk6 = (mode == 1) ? arg2->vC : b.unk6;
                break;
            case 8:
                b.unk7 = (mode == 1) ? arg2->v10 : b.unk7;
                break;
            case 0x40:
                b.unk3 = (mode == 1) ? arg2->v1C : b.unk3;
                break;
            case 0x80:
                b.unk8 = (mode == 1) ? arg2->v20 : b.unk8;
                break;
            case 0x100:
                b.unkA = (mode == 1) ? arg2->v24 : b.unkA;
                break;
            case 0x200:
                b.unkC = (mode == 1) ? arg2->v28 : b.unkC;
                break;
            case 0x10:
                b.unk14 = (mode == 1) ? arg2->v14 : b.unk14;
                break;
            case 0x20:
                b.unk10 = (mode == 1) ? arg2->v18 : b.unk10;
                break;
            case 0x800:
                b.unk13 = (mode == 1) ? arg2->v30 : b.unk13;
                break;
            case 0x1000:
                b.unk2 = (mode == 1) ? arg2->v34 : b.unk2;
                break;
            case 0x2000:
                if (mode == 1) {
                    t = arg2->v38;
                }
                if (t < 0) {
                    b.unk11 = 0;
                } else if (t > 0xFF) {
                    b.unk11 = 0xFF;
                } else {
                    b.unk11 = t;
                }
                break;
            }
            mask &= ~bit;
            bit <<= 1;
        } while (mask != 0);
        switch (rec->type) {
        case 1:
            ret = func_088A6088(rec, &b, rec->unk6 + arg2->unk4);
            break;
        case 2:
            ret = func_088A678C(&b);
            break;
        case 3:
            ret = func_088A6780(&b);
            break;
        case 0:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            break;
        }
        if (rec->next == 0xFFFF) {
            break;
        }
        if (rec->next == arg1) {
            break;
        }
        arg1 = rec->next;
    }
    return ret;
}
