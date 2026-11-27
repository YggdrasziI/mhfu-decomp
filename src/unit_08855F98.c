/* unit_08855F98: 0x08855F98-0x088564F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08855F98 (ULES01213): fills the five, five, three and three rows of
 * 16-bit slots at +0x6A240/+0x6A268/+0x6A290/+0x6A2C0 with weighted random
 * picks (rand % 100 walked down a {val, weight} table per row).
 *
 * Needs the speed setting with loop unrolling off. The {2, 3, 5} row counts
 * are three words copied onto the stack with lwc1/swc1 (union with floats).
 * Local declaration order and the for-init order of the last loop set the
 * saved registers (found by search).
 */
#pragma optimize_for_size off
#pragma opt_unroll_loops off
typedef int s32;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

typedef struct {
    u16 val;
    u16 weight;
} Ent;

extern char *D_08A631A0;
extern Ent D_0899C51C[];
extern Ent D_0899C60C[];
extern Ent D_0899C6E8[];
extern Ent D_0899C73C[];
typedef union { float f[3]; s32 v[3]; } Cnt3;
extern float D_0899CBFC;
extern float D_0899CC00;
extern float D_0899CC04;
extern u16 func_088900C4(char *, s32);

void func_08855F98(char *arg0) {
    s32 j;
    s32 *c3;
    Ent *e3;
    Ent *t;
    s32 m2;
    Ent *t3;
    Ent *t2;
    char *p3;
    s32 k;
    Ent *t1;
    char *p2;
    s32 ci;
    char *p0;
    u16 r;
    s32 n;
    char *d0;
    char *cp2;
    Cnt3 cnt;
    char *p1;
    Ent *e2;
    Ent *e1;
    char *d1;
    char *cp1;
    s32 i1;
    u16 r2;
    s32 i2;
    s32 k2;
    char *cp3;
    char *cp;
    Ent *e;
    char *d2;
    s32 i0;
    s32 i;

    for (ci = 0, cp = arg0; ci < 5; ci++, cp += 8) {
        *(s16 *)(cp + 0x6A240) = 0;
        *(s16 *)(cp + 0x6A242) = 0;
        *(s16 *)(cp + 0x6A244) = 0;
        *(s16 *)(cp + 0x6A246) = 0;
    }
    for (ci = 0, cp1 = arg0; ci < 5; ci++, cp1 += 8) {
        *(s16 *)(cp1 + 0x6A268) = 0;
        *(s16 *)(cp1 + 0x6A26A) = 0;
        *(s16 *)(cp1 + 0x6A26C) = 0;
        *(s16 *)(cp1 + 0x6A26E) = 0;
    }
    for (ci = 0, cp2 = arg0; ci < 3; ci++, cp2 += 16) {
        *(s16 *)(cp2 + 0x6A290) = 0;
        *(s16 *)(cp2 + 0x6A292) = 0;
        *(s16 *)(cp2 + 0x6A294) = 0;
        *(s16 *)(cp2 + 0x6A296) = 0;
        *(s16 *)(cp2 + 0x6A298) = 0;
        *(s16 *)(cp2 + 0x6A29A) = 0;
        *(s16 *)(cp2 + 0x6A29C) = 0;
        *(s16 *)(cp2 + 0x6A29E) = 0;
    }
    for (ci = 0, cp3 = arg0; ci < 3; ci++, cp3 += 12) {
        *(s16 *)(cp3 + 0x6A2C0) = 0;
        *(s16 *)(cp3 + 0x6A2C2) = 0;
        *(s16 *)(cp3 + 0x6A2C4) = 0;
        *(s16 *)(cp3 + 0x6A2C6) = 0;
        *(s16 *)(cp3 + 0x6A2C8) = 0;
        *(s16 *)(cp3 + 0x6A2CA) = 0;
    }
    for (i0 = 0, t = D_0899C51C, p0 = arg0; i0 < 5; i0++, t += 12, p0 += 8) {
        n = (func_088900C4(D_08A631A0, 1) & 1) + 3;
        j = 0;
        d0 = p0 + 0x6A240;
        do {
            r = func_088900C4(D_08A631A0, 1) % 100;
            for (k = 0, e = t; ; e++, k++) {
                if (r < e->weight) break;
                r -= e->weight;
            }
            *(u16 *)d0 = t[k].val;
            j++;
            d0 += 2;
        } while (j < n);
    }
    for (i1 = 0, t1 = D_0899C60C, p1 = arg0; i1 < 5; i1++, t1 += 11, p1 += 8) {
        n = (func_088900C4(D_08A631A0, 1) & 1) + 3;
        j = 0;
        d1 = p1 + 0x6A268;
        do {
            r = func_088900C4(D_08A631A0, 1) % 100;
            for (k = 0, e1 = t1; ; e1++, k++) {
                if (r < e1->weight) break;
                r -= e1->weight;
            }
            *(u16 *)d1 = t1[k].val;
            j++;
            d1 += 2;
        } while (j < n);
    }
    for (i2 = 0, m2 = 3, t2 = D_0899C6E8, p2 = arg0; i2 < 3; i2++, m2 += 2, t2 += 7, p2 += 16) {
        n = m2 + (func_088900C4(D_08A631A0, 1) & 1);
        j = 0;
        if (n > 0) {
        d2 = p2 + 0x6A290;
        do {
            r2 = func_088900C4(D_08A631A0, 1) % 100;
            for (k2 = 0, e2 = t2; ; e2++, k2++) {
                if (r2 < e2->weight) break;
                r2 -= e2->weight;
            }
            *(u16 *)d2 = t2[k2].val;
            j++;
            d2 += 2;
        } while (j < n);
        }
    }
    cnt.f[0] = D_0899CBFC;
    cnt.f[1] = D_0899CC00;
    cnt.f[2] = D_0899CC04;
    for (c3 = cnt.v, i = 0, t3 = D_0899C73C, p3 = arg0; i < 3; i++, c3++, t3 += 3, p3 += 12) {
        n = *c3 + (func_088900C4(D_08A631A0, 1) & 1);
        j = 0;
        if (n > 0) {
        do {
            r = func_088900C4(D_08A631A0, 1) % 100;
            for (k = 0, e3 = t3; ; e3++, k++) {
                if (r < e3->weight) break;
                r -= e3->weight;
            }
            ((u16 *)(p3 + 0x6A2C0))[j] = t3[k].val;
            j++;
        } while (j < n);
        }
    }
    if (func_088900C4(D_08A631A0, 1) & 1) {
        *(s16 *)(arg0 + 0x6A2E4) = 0x43;
    } else {
        *(s16 *)(arg0 + 0x6A2E4) = 0;
    }
    arg0[0x6A23F] = ((u8)arg0[0x6A239] + 1) * 3;
}
