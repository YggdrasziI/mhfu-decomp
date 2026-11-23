/* unit_0886F894: 0x0886F894-0x08870194 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 *
 * Optimized for speed (the space-filling loop is unrolled by 8).
 * The outer walk is a guarded do/while so that `off` (the slot offset) is
 * set after the guard. The sort reads the slots through `volatile`
 * pointers: a device that reproduces the field reloads after the
 * comparison, not a claim about the original source.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 id;
    u8 pad2;
    u8 n;
    s32 off;
} Ent;

typedef struct {
    u16 id;
    s16 v;
} Slot;

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A62C7C;
extern s32 D_09A4F0C4;
extern s8 D_089A7F64[];
extern s8 D_089A7F68[];
extern s8 D_089A7F84[];
extern char D_089A7D1C[];
extern s32 D_089A822C[];

extern char *func_088DCEBC(s32, u8);
extern s32 func_088D6A54(char *, u8);
extern s32 func_088D6A1C(char *, s32);
extern s32 func_088900C4(char *, s32);
extern s16 func_088701D8(char *);
extern s32 func_0886F78C(char *);
extern s32 func_0886A35C(char *, s32);
extern void func_08872444(char *);

void func_0886F894(char *arg0) {
    volatile Slot *a;
    s32 si;
    volatile Slot *b;
    s32 sj;
    char *obj;
    u8 flag;
    s32 i;
    Ent *e;
    s32 cnt;
    u16 *tbl;
    s32 off;
    s8 *chances;
    s32 j;
    u8 n;
    u8 k;
    s32 c;
    s8 v;
    u8 bit;
    s32 t;
    u16 sum;
    u16 r;
    u16 acc;
    u16 *p;
    u16 item;
    s32 idx;
    s32 w;
    u16 tid;
    s16 tv;
    u16 bid;

    obj = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
    flag = 0;
    *(s32 *)(D_089CC438 + 0x410) = 0;
    *(s32 *)(D_089CC438 + 0x414) = 0;
    for (i = 0; i < 32; i++) {
        *(u16 *)(D_089CC438 + i * 4 + 0x390) = 0;
        *(u16 *)(D_089CC438 + i * 4 + 0x392) = 0;
    }
    cnt = 0;
    e = *(Ent **)(arg0 + 0x5C);
    if (e->id != 0xFFFF) {
        off = 0;
        do {
            chances = D_089A7F64;
            if (e->id >= 0xF7 && e->id < 0x10C) {
                if ((u16)func_088701D8(arg0) >= e->id - 0xF7) {
                    goto roll;
                }
                goto next;
            } else {
                switch (e->id) {
                case 0x8000:
                    bit = (*(s32 *)(D_089CC438 + 0x70000 - 0x50EC) & 4) != 0;
                    if (bit == 1) {
                        chances = D_089A7F68;
                        break;
                    }
                    n = e->n;
                    if (func_088D6A54(obj, 0x13)) {
                        n++;
                    } else if (func_088D6A54(obj, 0x14)) {
                        if ((u16)func_088900C4(D_08A631A0, 1) & 1) {
                            n++;
                        }
                    }
                    for (k = 0; k < n; k++) {
                        arg0[k + 0x7C1] = ' ';
                    }
                    if (func_088D6A1C(obj, 0x90)) {
                        v = 0x1A;
                    } else if (func_088D6A1C(obj, 0x92)) {
                        v = 0x10;
                    } else if (func_088D6A1C(obj, 0x91)) {
                        v = 0x1D;
                    } else if (func_088D6A1C(obj, 0x93)) {
                        v = 8;
                    } else {
                        v = 0x16;
                    }
                    for (; k < 10; k++) {
                        arg0[k + 0x7C1] = (s8)v;
                    }
                    arg0[k + 0x7C1] = 0;
                    chances = (s8 *)(arg0 + 0x7C1);
                    break;
                case 0x8001:
                    break;
                case 1:
                    if (func_088701D8(arg0) <= 0) {
                        goto next;
                    }
                    chances = D_089A7F84;
                    break;
                case 0x10C: case 0x10D: case 0x10E: case 0x10F:
                case 0x110: case 0x111: case 0x112: case 0x113:
                case 0x114: case 0x115: case 0x116: case 0x117:
                case 0x118: case 0x119:
                    w = *(u16 *)(D_089CC438 + 0x70000 - 0x50EE);
                    if (func_0886F78C(arg0) < *(s32 *)(D_089A7D1C + w * 56 + e->id * 4 - 0x36F68)) {
                        goto next;
                    }
                    chances = D_089A7F64;
                    break;
                case 0x24: case 0x25: case 0x26: case 0x27:
                case 0x28: case 0x29: case 0x2A: case 0x2B:
                case 0x2C: case 0x2D: case 0x2E: case 0x2F:
                case 0x30: case 0x31: case 0x32: case 0x33:
                case 0x34: case 0x35:
                    t = func_0886A35C(D_08A62C7C, 1);
                    t = (t - func_0886A35C(D_08A62C7C, 0)) / 1800;
                    idx = e->id - 0x24;
                    if (flag) {
                        goto next;
                    }
                    if (t >= D_089A822C[idx]) {
                        goto next;
                    }
                    flag = 1;
                    chances = D_089A7F64;
                    break;
                }
            }
        roll:
            tbl = (u16 *)(e->off + *(s32 *)(arg0 + 0x50));
            for (j = 0;; j++) {
                c = chances[j];
                if ((s32)(u16)func_088900C4(D_08A631A0, 0) % 32 >= c) {
                    break;
                }
                sum = 0;
                for (p = tbl; *p != 0xFFFF; p += 3) {
                    sum += *p;
                }
                r = (u16)func_088900C4(D_08A631A0, 0) % sum;
                if (e->id == 0x8000 && j == 0) {
                    r = 0;
                }
                acc = 0;
                for (p = tbl; *p != 0xFFFF;) {
                    acc += *p++;
                    if (r < acc) {
                        break;
                    }
                    p += 2;
                }
                item = p[0];
                if (item != 0) {
                    cnt++;
                    *(u16 *)(D_089CC438 + off + 0x390) = item;
                    *(u16 *)(D_089CC438 + off + 0x392) = p[1];
                    off += 4;
                }
                if (cnt >= 16) {
                    break;
                }
            }
        next:
            if (cnt >= 16) {
                break;
            }
            e++;
        } while (e->id != 0xFFFF);
    }
    func_08872444(arg0);
    a = (Slot *)(D_089CC438 + 0x390);
    for (si = 0; si < 15; si++, a++) {
        b = (Slot *)(D_089CC438 + (si + 1) * 4 + 0x390);
        for (sj = si + 1; sj <= 15; sj++, b++) {
            bid = b->id;
            if (bid != 0 && bid < a->id) {
                tid = a->id;
                tv = a->v;
                a->id = b->id;
                a->v = b->v;
                b->id = tid;
                b->v = tv;
            }
        }
    }
    a = (Slot *)(D_089CC438 + 0x3D0);
    for (si = 16; si < 31; si++, a++) {
        b = (Slot *)(D_089CC438 + (si + 1) * 4 + 0x390);
        for (sj = si + 1; sj <= 31; sj++, b++) {
            bid = b->id;
            if (bid != 0 && bid < a->id) {
                tid = a->id;
                tv = a->v;
                a->id = b->id;
                a->v = b->v;
                b->id = tid;
                b->v = tv;
            }
        }
    }
}
