/* unit_08876FCC: 0x08876FCC-0x08877100 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
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
    u8 pad0[0x10];
    s32 total;
    s32 unk14;
    u8 pad18[8];
    s32 unk20;
    s32 count;
    Entry e[1];
} Obj;

extern char *D_08A62CB4;
extern Item18 D_0899D198[];
extern s32 func_0887E9AC(s32, s32, s32);

void func_08876FCC(Obj *arg0) {
    s32 sum;
    Entry *p;
    s32 i;
    s32 id;

    *(s16 *)((char *)arg0 + 0xA4) = 0;
    *(s16 *)((char *)arg0 + 0xA6) = 0;
    *(s16 *)((char *)arg0 + 0xAA) = 0xE10;
    *(s32 *)(D_08A62CB4 + 0x14) = 0;
    *(u8 *)(D_08A62CB4 + 0x1C) = 0;
    *(s16 *)((char *)arg0 + 0xA8) = 10;
    sum = 0;
    p = arg0->e;
    for (i = 0; i < arg0->count; i++, p++) {
        id = p->id;
        if (id == 0) {
            break;
        }
        sum += p->qty * D_0899D198[id].price;
    }
    arg0->unk14 = func_0887E9AC((s32)D_08A62CB4, sum, 1);
    sum = 0;
    p = arg0->e;
    for (i = 0; i < arg0->count; i++, p++) {
        id = p->id;
        if (id == 0) {
            break;
        }
        sum += p->qty * D_0899D198[id].price;
    }
    arg0->total = sum;
    *(u8 *)(D_08A62CB4 + 0x1D) = *(u8 *)(D_08A62CB4 + 0x1C);
    arg0->unk20 = 0;
}
