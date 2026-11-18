/* unit_088AF848: 0x088AF848-0x088AF978 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AF7E0 and unit_088AF978.
 *
 * Stores the 0xC8-byte record arg0 in one of the four slots at
 * D_09A1FDE0 + 0xB8: over the slot that func_088B0514 refuses against it
 * (returns 2), otherwise in the first slot that func_088B04B4 refuses
 * (returns 1, then func_088B7AF4 when D_09A1FDE0 is not 2; also when no
 * slot was taken, returning 0). The stored slot gets +0xC6 set.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 unk0;
    char unk4[0xC2];
    u8 used;
    u8 unkC7;
} Rec;

extern char D_09A1FDE0[];

extern s32 func_088B0514(Rec *, Rec *);
extern s32 func_088B04B4(Rec *);
extern void func_088B7AF4(Rec *);

s32 func_088AF848(Rec *arg0) {
    s32 stored;
    s32 i;
    char *b;
    char *c;
    s32 j;
    Rec *r;

    i = 0;
    b = D_09A1FDE0;
    do {
        r = (Rec *) (b + 0xB8);
        if (!func_088B0514(r, arg0)) {
            *r = *arg0;
            r->used = 1;
            return 2;
        }
        i++;
        b += 0xC8;
    } while (i < 4);
    stored = 0;
    j = 0;
    c = D_09A1FDE0;
    do {
        r = (Rec *) (c + 0xB8);
        if (!func_088B04B4(r)) {
            *r = *arg0;
            stored = 1;
            r->used = stored;
            break;
        }
        j++;
        c += 0xC8;
    } while (j < 4);
    if ((u8) D_09A1FDE0[0] != 2) {
        func_088B7AF4(arg0);
    }
    return stored;
}
