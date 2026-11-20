/* unit_088DB990: 0x088DB990-0x088DBB5C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between func_088DB608, still in assembly
 * (text_088DB608), and unit_088DBB5C.
 *
 * func_088DB990 runs func_088DB608 for the six slots whose 0x8C-byte record
 * of D_089CC438 (+0x30) starts with a non-zero byte. func_088DBA0C removes
 * the object of a slot: clears the slot, takes the object out of its list
 * of D_08A62C5C (heads at +0x80028, tails at +0x80064, count at +0x800A0),
 * destroys it through its first virtual function and frees it.
 *
 * C++: bool conversion and virtual call.
 */

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
};

extern "C" {

extern char *D_089CC438;
extern Heap *D_08A62C5C;

extern int func_08859C40(void *, Obj *);
extern void func_08868498(Heap *, Obj *);
extern void func_08868680(Heap *, Obj *);
extern void func_088DB49C(Group *, Obj *);
extern Obj *func_088DB608(Group *, s32);

void func_088DB990(Group *arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if ((bool) *(u8 *)(D_089CC438 + (u8) i * 0x8C + 0x30) != 0) {
            func_088DB608(arg0, i);
        }
    }
}

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

void func_088DBA0C(Group *arg0, s32 arg1) {
    Obj *obj = arg0->slot[arg1];
    Heap *g;

    func_088DB49C(arg0, obj);
    arg0->slot[arg1] = 0;
    func_08868498(D_08A62C5C, obj);
    func_08868680(D_08A62C5C, obj);
    unlink(D_08A62C5C, obj);
    g = D_08A62C5C;
    if (obj != 0) {
        obj->vfunc_08(1);
    }
    func_08859C40(g->alloc, obj);
}

}
