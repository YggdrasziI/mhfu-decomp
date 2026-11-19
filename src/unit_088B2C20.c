/* unit_088B2C20: 0x088B2C20-0x088B2D74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2BC0 and unit_088B2D74.
 *
 * Starts phase 1 of the record arg0 (timer +0xC = 0x3C), then for each of
 * the four 0xC8-byte records of D_09A29364 that func_088B04B4 accepts:
 * when its byte at +0xC5 is set and func_088B34AC finds a slot, copies its
 * two parts there and either replies with func_088B2300 or calls
 * func_088B3594, counting them in D_09A299A9; when the byte is clear,
 * replies with func_088B25B4 if func_088B04EC accepts it.
 * When func_088B34AC finds no slot the loop goes on without advancing to
 * the next record (as in the original code).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    s16 h[0xB];
} Part16;

typedef struct {
    s16 h[0x52];
} PartA4;

typedef struct {
    char unk0[8];
    Part16 unk8;
    char pad1E[2];
    PartA4 unk20;
    u8 unkC4;
    u8 unkC5;
    char padC6[2];
} Rec;

extern Rec D_09A29364[];
extern u16 D_09A28BF0;
extern u8 D_09A299A9;

extern s32 func_088B04B4(Rec *);
extern s32 func_088B04EC(Rec *);
extern Rec *func_088B34AC(Rec *);
extern void func_088B2300(Id *, Rec *, u16);
extern void func_088B25B4(Id *, Rec *, u16);
extern void func_088B3594(Rec *);

void func_088B2C20(u8 *arg0) {
    Id a;
    Id b;
    Rec *slot;
    s32 i;
    u8 n;
    Rec *rec;

    arg0[0x22]++;
    *(s32 *) (arg0 + 0x10) = 0;
    arg0[0x23] = 0;
    *(s32 *) (arg0 + 0xC) = 0x3C;
    n = 0;
    rec = D_09A29364;
    for (i = 0; i < 4; i++) {
        if (func_088B04B4(rec)) {
            if (rec->unkC5 != 0) {
                slot = func_088B34AC(rec);
                if (slot == 0) {
                    continue;
                }
                slot->unk8 = rec->unk8;
                slot->unk20 = rec->unk20;
                if (func_088B04EC(rec)) {
                    func_088B2300(&a, rec, D_09A28BF0);
                } else {
                    func_088B3594(rec);
                }
                n++;
            } else if (func_088B04EC(rec)) {
                func_088B25B4(&b, rec, D_09A28BF0);
            }
        }
        rec++;
    }
    D_09A299A9 = n;
}
