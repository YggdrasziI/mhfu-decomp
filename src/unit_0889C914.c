/* unit_0889C914: 0x0889C914-0x0889CA88 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef signed char s8;

typedef struct {
    s8 a[8];
} R0;

typedef struct {
    s16 a[11];
} R1;

typedef struct {
    s16 a[82];
} R2;

typedef struct {
    union {
        R0 r0;
        u8 key[6];
    };
    R1 r1;
    s16 pad1e;
    R2 r2;
    u8 c4;
    u8 c5;
    u8 c6;
    u8 c7;
} Rec;

typedef struct {
    u8 pad[0x57C];
    Rec recs[4];
    u8 pad2[0xEE3 - 0x57C - 4 * 0xC8];
    s8 count;
} Obj;

extern void func_0889C75C(char *);

void func_0889C914(Obj *arg0, Rec *arg1) {
    s32 n;
    u8 ok = 1;
    s32 i;
    s32 k;
    s32 r;
    u8 x;
    u8 y;

    n = arg0->count;
    for (i = 0; i < n; i++) {
        k = 0;
        do {
            x = arg0->recs[i].key[k];
            y = arg1->key[k];
            if (y < x) {
                r = -1;
                goto done;
            }
            if (x < y) {
                r = 1;
                goto done;
            }
            k++;
        } while (k < 6);
        r = 0;
    done:
        if (r == 0) {
            ok = 0;
        }
    }
    if (ok && n < 4) {
        Rec *d = &arg0->recs[(s8)n];

        d->r0 = arg1->r0;
        d->r1 = arg1->r1;
        d->r2 = arg1->r2;
        d->c4 = arg1->c4;
        d->c5 = arg1->c5;
        x = arg1->c6;
        y = arg1->c7;
        d->c6 = x;
        d->c7 = y;
        arg0->count++;
        func_0889C75C((char *)arg0);
    }
}
