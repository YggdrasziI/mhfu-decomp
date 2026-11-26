/* unit_088262B0: 0x088262B0-0x088264F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 pad0[2];
    s16 h2;
    u8 pad4[3];
    u8 b7;
} Entry;

typedef struct {
    u8 pad0[4];
    u16 f4;
    u8 n6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 bA;
} Page;

extern s32 D_08A62C50;
extern Entry *func_0885C13C(s32, u8 *, s32, u16 *, u16 *, s32);
extern u8 func_0885B718(s32, Entry *, s32, s32);

s32 func_088262B0(char *arg0) {
    Page *pg;
    s32 i;
    s32 page;
    s32 start;
    s32 end;
    s16 prev;
    s32 count;
    u16 *out;
    s32 j;
    Entry *e;
    u8 key;
    u16 ab[2];
    s32 n;

    pg = (Page *)(arg0 + 0x5BC);
    out = (u16 *)(arg0 + 0x5C8);
    for (i = 0; i < pg->n6; i++) {
        out[i] = 0;
    }
    arg0[0x5D8] = 0;
    if (func_0885C13C(D_08A62C50, (u8 *)(arg0 + 0x5D8), -1, &ab[0], &ab[1], 1) == 0) {
        *(Entry **)(arg0 + 0x5A8) = 0;
        return 0;
    }
    n = pg->n6;
    page = pg->f4 / n;
    prev = -1;
    key = *(u8 *)(arg0 + 0x5D8);
    count = 0;
    j = 0;
    start = n * page;
    end = start + n;
    for (; j < 0xAC; j++, count++) {
        e = func_0885C13C(D_08A62C50, &key, 1, &ab[0], &ab[1], 1);
        if (!(prev < key)) {
            break;
        }
        prev = key;
        if (count >= start && count < end) {
            if (pg->f4 == count) {
                *(Entry **)(arg0 + 0x5A8) = e;
                arg0[0x5BB] = key;
                *(u16 *)(arg0 + 0x5AC) = ab[0];
                *(u16 *)(arg0 + 0x5AE) = ab[1];
            }
            *out = e->h2;
            if (func_0885B718(D_08A62C50, e, 1, 0) == 1) {
                if (e->b7 & 1) {
                    *out |= 0x8000;
                }
            } else {
                *out |= 0x4000;
            }
            out++;
        }
    }
    if (pg->f4 >= count) {
        pg->f4 = count - 1;
    }
    pg->b9 = (count + (pg->n6 - 1)) / pg->n6;
    pg->bA = count - pg->n6 * (pg->b9 - 1);
    pg->b8 = page;
    pg->b7 = pg->f4 % pg->n6;
    return 1;
}
