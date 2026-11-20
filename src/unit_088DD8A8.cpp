/* unit_088DD8A8: 0x088DD8A8-0x088DDF50 (ULES01213)
 *
 * Bounds (hypothesis): 6 functions between unit_088DD868 and func_088DDE20,
 * which is still in assembly (text_088DDE20).
 *
 * Table of 43 loaded resources (12-byte entries: flags, id, address, a
 * word written by the loader) followed by a bump area (+0x204 start,
 * +0x208 base, +0x20C next address, +0x210 bytes left) and three state
 * bytes. Entries 0x15-0x2A take their memory from the bump area, the
 * others from func_08898694. Flag 1: load requested; flag 2: loaded.
 *
 * C++: virtual calls. Optimized for speed (unrolled loop; the loop over
 * entries 0x15-0x2A is written `i <= 42`).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Mgr {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual s32 vfunc_18(u16);
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34(u16, s32, s32, s32, s32 *, s32);
    virtual s32 vfunc_38();
    virtual s32 vfunc_3C(u16);
};

struct Entry {
    u16 flags;
    u16 id;
    s32 ptr;
    s32 unk8;
};

struct Table {
    Entry e[43];
    u32 unk204;
    u32 unk208;
    u32 unk20C;
    u32 unk210;
    u8 unk214;
    u8 unk215;
    u8 unk216;
};

extern "C" {

extern Mgr *D_089CC434;
extern char *D_089CC438;
extern char *D_08A62C7C;
extern s32 D_09A0B540;

extern s32 func_08898694(s32, s32, s32);
extern void func_088B87B0(Mgr *, u8);
extern void func_088DD7C4(Entry *);
extern s32 func_088DE4BC(Table *);
extern void func_088DE520(Table *);
extern void sceKernelDcacheWritebackInvalidateAll(void);
extern s32 sceDmacMemcpy(s32, s32, s32);

void func_088DDCF4(Table *arg0, s32 arg1, s32 arg2);

static inline void table_clear(Table *t) {
    Entry *e = t->e;
    s32 i;

    for (i = 0; i < 43; i++, e++) {
        func_088DD7C4(e);
    }
    t->unk204 = 0;
    t->unk208 = 0;
    t->unk20C = t->unk208;
    t->unk210 = t->unk204;
}

static inline void table_rewind(Table *t) {
    s32 i;

    t->unk210 = t->unk204;
    t->unk20C = t->unk208;
    for (i = 0x15; i <= 42; i++) {
        t->e[i].flags &= ~2;
    }
    func_088B87B0(D_089CC434, 1);
}

void func_088DD8A8(Table *arg0) {
    table_clear(arg0);
    arg0->unk216 = 1;
    arg0->unk214 = 0;
}

void func_088DD91C(Table *arg0) {
    if (arg0->unk214 != 0) {
        arg0->unk214 = 0;
        table_rewind(arg0);
        func_088DE520(arg0);
    }
    arg0->unk216 = 0;
    table_clear(arg0);
}

void func_088DDA44(Table *arg0) {
    Entry *e;
    s32 i;

    if (arg0->unk216 != 0 && *(u8 *)(D_089CC438 + 0x480) == 0 && arg0->unk215 != 0 && arg0->unk214 == 0
        && func_088DE4BC(arg0) != 0) {
        arg0->unk214 = 1;
        table_rewind(arg0);
    }
    for (i = 0; i < 43; i++) {
        e = &arg0->e[i];
        if (e->flags & 1) {
            if (!(e->flags & 2)) {
                if (D_089CC434->vfunc_3C(e->id) == 0) {
                    if (e->unk8 != 1) {
                        e->flags &= ~1;
                        e->flags |= 2;
                    } else {
                        e->flags = 0;
                    }
                }
            }
        }
    }
}

static inline u32 table_take(Table *t, u32 size) {
    if (t->unk210 >= size) {
        t->unk210 -= size;
        t->unk20C += size;
        return t->unk20C - size;
    }
    return 0;
}

void func_088DDBD8(Table *arg0, s32 arg1, u16 arg2, s32 arg3) {
    Entry *e;
    s32 size;
    s32 own;

    size = D_089CC434->vfunc_18(arg2);
    if (arg3 != 0) {
        size = arg3;
    }
    e = &arg0->e[arg1];
    if (arg1 >= 0x15 && arg1 < 43) {
        e->ptr = table_take(arg0, size);
        if (e->ptr == 0) {
            return;
        }
        own = 1;
    } else {
        e->ptr = func_08898694(D_09A0B540, 0x14, size);
        own = 0;
    }
    e->unk8 = 0;
    D_089CC434->vfunc_34(arg2, e->ptr, -1, own, &e->unk8, 1);
    e->flags |= 1;
    e->id = arg2;
}

void func_088DDCF4(Table *arg0, s32 arg1, s32 arg2) {
    Entry *dst = &arg0->e[arg1];
    Entry *src = &arg0->e[arg2];
    s32 size = D_089CC434->vfunc_18(src->id);

    dst->ptr = func_08898694(D_09A0B540, 0x14, size);
    sceKernelDcacheWritebackInvalidateAll();
    sceDmacMemcpy(dst->ptr, src->ptr, size);
    dst->flags |= 2;
    dst->id = src->id;
}

s32 func_088DDD9C(Table *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Entry *e = &arg0->e[arg2];

    if (arg3 == -1) {
        arg3 = D_089CC434->vfunc_18(e->id);
    }
    sceKernelDcacheWritebackInvalidateAll();
    sceDmacMemcpy(arg1, e->ptr, arg3);
    return arg3;
}

}
