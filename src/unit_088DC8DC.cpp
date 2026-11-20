/* unit_088DC8DC: 0x088DC8DC-0x088DCD94 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088DC774 and unit_088DCD94.
 *
 * func_088DC8DC removes the object of slot 1 (as func_088DBA0C does for any
 * slot): clears the slot, takes the object out of its list of D_08A62C5C,
 * destroys it through its first virtual function and frees it.
 * func_088DCA10 is a two-step sequence of a slot: step 0 sends two pairs of
 * 16-bit values (fixed ones and those of the table at 0x089ABFE8 for the id
 * of func_09A730E0) to func_08880A70, step 1 waits for func_08881970.
 * func_088DCB00 returns a colour: the entries `n` and `n + 1` (of eight,
 * four bytes each) of the table at 0x089B657C blended by the low four bits
 * of the 16-bit counter at +0x1C of D_089CC438, alpha 0xFF.
 *
 * C++: virtual call. Optimized for speed (float constants as immediates).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Obj {
    virtual void vfunc_08(s32);
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
};

#define NEXT(o) (*(Obj **)((char *) (o) + 0x1C4))
#define PREV(o) (*(Obj **)((char *) (o) + 0x1C8))
#define LIST(o) (*(s32 *)((char *) (o) + 0x1C0))
#define HEAD(g, k) ((g)->head[k])
#define TAIL(g, k) ((g)->tail[k])
#define COUNT(g) ((g)->count)

struct Heap {
    char pad0[0x80000];
    char alloc[0x28];
    Obj *head[15];
    Obj *tail[15];
    s32 count;
};

struct Group {
    char pad0[0xC];
    Obj *slot[6];
    s32 state[6];
};

union Color {
    u8 c[4];
    u32 v;
};

extern "C" {

extern char *D_089CC438;
extern Heap *D_08A62C5C;
extern s32 D_08A62D8C;
extern u16 D_089ABFE8[];
extern u16 D_089ABFEA[];
extern u8 D_089B657C[];

extern int func_08859C40(void *, Obj *);
extern void func_08880A70(s32, s32, u16 *, u16 *, s32, s32);
extern s32 func_08881970(s32);
extern void func_088DB49C(Group *, Obj *);
extern void func_088DC76C(Group *, Obj *);
extern s32 func_09A730E0(Obj *);

static inline void unlink(Heap *g, Obj *obj) {
    Obj *next = NEXT(obj);
    Obj *prev = PREV(obj);

    if (next == 0 && prev == 0) {
        if (HEAD(g, LIST(obj)) != obj) {
            return;
        }
        HEAD(g, LIST(obj)) = 0;
    }
    if (next != 0) {
        if (prev != 0) {
            PREV(next) = prev;
        } else {
            HEAD(g, LIST(obj)) = next;
            PREV(next) = 0;
        }
    }
    if (prev != 0) {
        if (next != 0) {
            NEXT(prev) = next;
        } else {
            NEXT(prev) = 0;
            TAIL(g, LIST(obj)) = prev;
        }
    }
    COUNT(g)--;
}

void func_088DC8DC(Group *arg0) {
    Obj *obj = arg0->slot[1];
    Heap *g;

    func_088DB49C(arg0, obj);
    arg0->slot[1] = 0;
    func_088DC76C(arg0, obj);
    unlink(D_08A62C5C, obj);
    g = D_08A62C5C;
    if (obj != 0) {
        obj->vfunc_08(1);
    }
    func_08859C40(g->alloc, obj);
}

s32 func_088DCA10(Group *arg0, s32 arg1) {
    u16 a[2];
    u16 b[2];
    s32 id = (s16) func_09A730E0(arg0->slot[1]);

    switch (arg0->state[arg1]) {
    case 0:
        a[0] = 0x159A;
        b[0] = 0x1599;
        a[1] = D_089ABFE8[id * 2];
        b[1] = D_089ABFEA[id * 2];
        func_08880A70(D_08A62D8C, arg1 + 2, a, b, 0x159B, 2);
        arg0->state[arg1]++;
        break;
    case 1:
        if (func_08881970(D_08A62D8C) != 0) {
            break;
        }
        arg0->state[arg1] = 0;
    default:
        return 1;
    }
    return 0;
}

#define BLEND(k) \
    v = (float) (u32) p[k] * g + (float) (u32) q[k] * f; \
    if (v > 255.0f) { \
        v = 255.0f; \
    } \
    col.c[k] = (u32) v

u32 func_088DCB00(void) {
    Color col;
    u16 t;
    float f;
    float g;
    s32 n;
    u8 *p;
    u8 *q;
    float v;

    t = *(u16 *)(D_089CC438 + 0x1C);
    n = (t >> 4) & 7;
    p = &D_089B657C[n * 4];
    f = 0.0625f * (float) (t & 0xF);
    g = 1.0f - f;
    q = &D_089B657C[((n + 1) & 7) * 4];
    BLEND(0);
    BLEND(1);
    BLEND(2);
    col.c[3] = 0xFF;
    return col.v;
}

}
