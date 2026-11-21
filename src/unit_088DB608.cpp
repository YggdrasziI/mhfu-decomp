/* unit_088DB608: 0x088DB608-0x088DB990 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DB5D8 and unit_088DB990.
 *
 * Creates the object of slot `arg1` (the first free slot for -1): 0x1120,
 * 0x10F0 or 0x11C0 bytes from the allocator at +0x80000 of D_08A62C5C,
 * with the constructor chosen by the global mode bits, appends it to list 2
 * of that structure (heads at +0x80028, tails at +0x80064, count at
 * +0x800A0), gives it the value of entry `arg1 + 1` of the table of
 * D_09A4F0D0 (0xC-byte entries, when their bit 2 is set) and its index,
 * then runs its virtual functions at 0x10 and 0x48.
 *
 * The index `arg1 + 1` of the table lookup goes through the function-level
 * local `r` (it also holds the func_088DB5D8 result) and the inline helper
 * indexes the table with no copy of the index: a fresh index local swaps the
 * table and index registers, no local at all folds the `+ 1` into the
 * offsets.
 *
 * C++: bool conversions and virtual calls.
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

struct Entry {
    u16 flags;
    s32 value;
    s32 unk8;
};

struct Group {
    char pad0[0xC];
    Obj *slot[6];
};

extern "C" {

extern char *D_089CC438;
extern Heap *D_08A62C5C;
extern Entry *D_09A4F0D0;

extern int memset(void *, s32, s32);
extern Obj *func_08859B44(void *, s32, s32);
extern int func_08859C40(void *, Obj *);
extern Obj *func_08864544(s32, Obj *);
extern Obj *func_09AA9218(Obj *);
extern Obj *func_088DCF3C(Obj *);
extern Obj *func_09A652A0(Obj *);
extern s32 func_088DB5D8(Group *);
extern void func_08867EC8(Heap *, Obj *, u8);
extern void func_08868234(Heap *, Obj *, u8);
extern void func_08868498(Heap *, Obj *);
extern void func_08868680(Heap *, Obj *);
extern void func_088CEAB8(Obj *);
extern void func_088D3A84(Obj *);
extern void func_088DB488(Group *, Obj *, s32);
extern void func_088DB49C(Group *, Obj *);

#define CREATE(var, size, ctor) \
    { \
        Heap *g = D_08A62C5C; \
        Obj *tmp = func_08859B44(g->alloc, size, 0x10); \
        Obj *v; \
        Obj *r; \
        if (tmp != 0) { \
            memset(tmp, 0, size); \
            v = func_08864544(size, tmp); \
            if (v != 0) { \
                v = ctor(v); \
            } \
            if (v == 0) { \
                func_08859C40(g->alloc, tmp); \
            } \
            r = v; \
        } else { \
            r = 0; \
        } \
        var = r; \
    }

static inline s32 entry_value(Entry *tbl, s32 i) {
    if (tbl[i].flags & 2) {
        return tbl[i].value;
    }
    return 0;
}

Obj *func_088DB608(Group *arg0, s32 arg1) {
    Obj *obj;
    s32 flags;
    s32 v;
    Heap *g;
    s32 r;

    if (arg1 == -1) {
        r = func_088DB5D8(arg0);
        arg1 = r;
        if (r == -1) {
            return 0;
        }
    }
    flags = *(s32 *)(D_089CC438 + 0x6AF14);
    if ((bool) (flags & 1) != 0) {
        CREATE(obj, 0x1120, func_09AA9218);
    } else if ((bool) (flags & 8) == 1 || (bool) (flags & 0x20) == 1 || (bool) (flags & 0x40) == 1) {
        CREATE(obj, 0x10F0, func_088DCF3C);
    } else {
        CREATE(obj, 0x11C0, func_09A652A0);
    }
    if (obj != 0) {
        g = D_08A62C5C;
        if (HEAD(g, 2) == 0) {
            HEAD(g, 2) = obj;
        } else {
            NEXT(TAIL(g, 2)) = obj;
            PREV(obj) = TAIL(g, 2);
        }
        LIST(obj) = 2;
        TAIL(g, 2) = obj;
        COUNT(g)++;
        func_08867EC8(D_08A62C5C, obj, arg1);
        func_08868234(D_08A62C5C, obj, arg1);
        r = arg1 + 1;
        v = entry_value(D_09A4F0D0, r);
        if (v != 0) {
            *(s32 *)((char *) obj + 0x1AC) = v;
        }
        *(s16 *)((char *) obj + 0x1E6) = arg1;
        obj->vfunc_10();
        obj->vfunc_48();
        func_088CEAB8(obj);
        func_088D3A84(obj);
        func_088DB488(arg0, obj, arg1);
    }
    return obj;
}

}
