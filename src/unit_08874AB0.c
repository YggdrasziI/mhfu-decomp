/* unit_08874AB0: 0x08874AB0-0x08874C58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 id;
    s16 count;
} Slot;

typedef struct {
    char pad0[4];
    u8 unk4;
    char pad5[0xB];
    u32 unk10;
    char pad14[4];
} Item18;

typedef struct {
    char pad0[0x1E];
    u8 unk1E;
    char pad1F[5];
    s32 unk24;
    Slot slots[30];
} Obj;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern Item18 D_0899D198[];

extern char *func_088DCEBC(s32, u8);
extern Slot *func_08856884(char *, s32);
extern s32 func_088D72A4(char *, u16, s16, s32);

s32 func_08874AB0(Obj *arg0) {
    Slot *r;
    Slot *p;
    s32 j;
    char *obj;
    s32 i;
    Slot *q;
    Slot *t;
    s32 k;
    s32 sum;

    obj = func_088DCEBC(D_09A4F0C4, *(u8 *) (D_089CC438 + 0x28));
    arg0->unk1E = 0;
    r = arg0->slots;
    for (j = 0; j < 30; j++, r++) {
        r->id = 0;
        r->count = 0;
    }
    p = func_08856884(D_089CC438, 0);
    arg0->unk24 = 0;
    q = arg0->slots;
    for (i = 0; i < 24; i++, p++) {
        if (p->id != 0 && (D_0899D198[p->id].unk4 & 2)) {
            q->id = p->id;
            q->count = p->count;
            func_088D72A4(obj, p->id, -p->count, 0);
            arg0->unk1E = 1;
            q++;
            arg0->unk24++;
        }
    }
    sum = 0;
    t = arg0->slots;
    for (k = 0; k < arg0->unk24; k++, t++) {
        if (t->id == 0) {
            break;
        }
        sum += t->count * D_0899D198[t->id].unk10;
    }
    return sum;
}
