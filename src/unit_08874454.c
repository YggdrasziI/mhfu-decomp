/* unit_08874454: 0x08874454-0x08874A94 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u8 id;
    u8 type;
    u16 val;
} Entry;

typedef struct {
    s32 count;
    Entry e[10];
} List;

typedef struct {
    char pad[0xCC];
    List list;
} Obj;

extern char *D_089CC438;
extern char *D_08A62C7C;
extern char *D_089CBBEC;

extern u16 func_0884FFB8(char *, u16);
extern u16 func_0884FFCC(char *, u16);
extern u8 func_0884FC74(char *, u8);
extern void func_0884FFE0(char *, u16, s32);
extern void func_08850010(char *, u16, u16);
extern u16 func_0885028C(char *, u8, s32);
extern u16 func_08850338(char *, u8, s32);
extern char *func_0882FD68(char *, u8);
extern float func_08850238(char *, u8, u16);
extern void func_088585E8(char *, char *, s32, s32, s32);

static inline void List_init(List *l) {
    s32 k;
    Entry *e;
    l->count = 0;
    for (k = 0; k < 10; k++) {
        e = &l->e[k];
        e->id = e->type = e->val = 0;
    }
}

static inline void List_add(List *l, u8 id, u8 type, u16 val) {
    s32 k;
    for (k = 0; k < 10; k++) {
        if (l->e[k].id == 0) {
            l->e[k].id = id;
            l->e[k].val = val;
            l->e[k].type = type;
            l->count++;
            return;
        }
    }
}

void func_08874454(Obj *obj) {
    u16 c[90];
    u16 b[90];
    u8 a[90];
    u16 *pc;
    u16 *pb;
    u8 *pa;
    s32 i5;
    s32 d1;
    s32 d2;
    char *q;
    u16 v;
    u16 *x;
    u16 *y;
    s32 i3;
    s32 t;
    char *p;
    s32 i2;
    u8 r;
    s32 i1;

    for (i1 = 1; i1 <= 89; i1++) {
        c[i1] = func_0884FFB8(D_089CC438, i1);
        b[i1] = func_0884FFCC(D_089CC438, i1);
    }
    for (i2 = 1; i2 <= 89; i2++) {
        r = func_0884FC74(D_089CC438, i2);
        if (r != (u8)i2) {
            if (c[r] < c[i2]) {
                c[r] = c[i2];
            }
            if (b[r] == 0 || (b[i2] != 0 && b[i2] < b[r])) {
                b[r] = b[i2];
            }
            a[i2] = 0;
        } else {
            a[i2] = 1;
        }
    }
    p = D_08A62C7C;
    x = (u16 *)(p + 0x136);
    y = (u16 *)(p + 0x1EA);
    for (i3 = 1; i3 <= 89; i3++, x++, y++) {
        if ((t = *x) != 0) {
            if (func_0884FFB8(D_089CC438, i3) < t) {
                func_0884FFE0(D_089CC438, i3, t);
            }
        }
        if ((t = *y) != 0) {
            if (t < func_0884FFCC(D_089CC438, i3) || func_0884FFCC(D_089CC438, i3) == 0) {
                func_08850010(D_089CC438, i3, *y);
            }
        }
    }
    List_init(&obj->list);
    pc = &c[1];
    pb = &b[1];
    for (i5 = 1, pa = &a[1]; i5 <= 89; i5++, pc++, pb++, pa++) {
        if (*pa == 0) {
            continue;
        }
        d1 = *pc != func_0885028C(D_089CC438, i5, 0);
        d2 = *pb != func_08850338(D_089CC438, i5, 0);
        if (!d1 && !d2) {
            continue;
        }
        if (d1 && d2) {
            if (func_0885028C(D_089CC438, i5, 0) == func_08850338(D_089CC438, i5, 0)) {
                List_add(&obj->list, i5, 0, *pc);
            } else {
                List_add(&obj->list, i5, 1, *pc);
                List_add(&obj->list, i5, 2, *pb);
            }
        } else if (d1) {
            List_add(&obj->list, i5, 1, *pc);
        } else {
            List_add(&obj->list, i5, 2, *pb);
        }
        q = func_0882FD68(D_089CBBEC, i5);
        if (d1) {
            v = func_0885028C(D_089CC438, i5, 0);
            if (v >= *(s16 *)(q + 4)) {
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 8, i5,
                              (u32)((func_08850238(D_089CC438, i5, v) + 0.05f) * 10.0f));
            }
        }
        if (d2) {
            v = func_08850338(D_089CC438, i5, 0);
            if (v <= *(s16 *)(q + 8)) {
                func_088585E8(D_089CC438, D_08A62C7C + 0x684, 9, i5,
                              (u32)((func_08850238(D_089CC438, i5, v) + 0.05f) * 10.0f));
            }
        }
    }
}
