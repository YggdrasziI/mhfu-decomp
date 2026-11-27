/* unit_0890C6C8: 0x0890C6C8-0x0890C9A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Hypothesis: C++ exception-handling runtime (walks the action list of a
 * function: action codes masked with 0x1F, case 12 looks like a catch block,
 * case 15 like an exception specification). Names are not proven.
 *
 * C++ (bool inline), optimized for speed (rotated spec loop).
 * Owns the jump table jtbl_0893319C (0x0893319C, 16 words, 0x40 bytes).
 * Spec.unk0 is never accessed: it only places the local at 0x30.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

typedef struct {
    char *unk0;
    char *unk4;
    char *unk8;
    char *unk0C;
    char *unk10;
    s32 unk14;
    char *unk18;
    s32 unk1C;
    s32 pad20[(0x138 - 0x20) / 4];
} Context;

typedef struct {
    char *unk0;
    char *unk4;
    u8 *unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
} Info;

typedef struct {
    Info info;
    Context ctx;
} Iter;

typedef struct {
    s32 unk0;
    u32 n;
    s32 b;
    s32 c;
    u8 *types;
} Spec;

extern "C" {

extern void func_0890C224(void);
extern s32 func_0890BFE0(char *, char *, s32 *);
extern u8 *func_0890C3F4(u8 *, s32 *);
extern u8 *func_0890C490(u8 *, s32 *);
extern s32 func_0890D4C4(Iter *);
extern void func_0890CD14(Context *, Info *, u8 *);
extern void func_0890D95C(Context *, Info *, char *);

static inline u32 read32(u8 *p) {
    return (p[3] << 24) | ((p[2] << 16) | ((u32)p[0] | (p[1] << 8)));
}

static inline u8 current(Iter *it) {
    return it->info.unk8 ? (u8)(*it->info.unk8 & 0x1F) : (u8)0;
}

static inline bool inspec(char *type, Spec *sp) {
    s32 tmp;
    u8 *p = sp->types;
    u32 i;
    for (i = 0; i < sp->n; i++, p += 4) {
        if (func_0890BFE0(type, (char *)read32(p), &tmp)) {
            return 1;
        }
    }
    return 0;
}

u8 *func_0890C6C8(Context *ctx, Info *info, s32 *off) {
    Iter it;
    struct { char *type; s32 a; s32 b; } cb;
    Spec sp;
    u8 action;

    it.info = *info;
    it.ctx = *ctx;
    for (action = current(&it);; action = func_0890D4C4(&it)) {
        switch (action) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
            continue;
        case 12: {
            u8 *p = it.info.unk8;
            u8 *q;
            cb.type = (char *)read32(p + 1);
            q = p + 5;
            cb.type = cb.type ? cb.type : 0;
            func_0890C490(func_0890C3F4(q, &cb.a), &cb.b);
            if (func_0890BFE0(ctx->unk0, cb.type, off) == 0) {
                continue;
            }
            break;
        }
        case 15:
            sp.types = func_0890C490(func_0890C3F4(func_0890C3F4(it.info.unk8 + 1, (s32 *)&sp.n), &sp.b), &sp.c);
            if (!inspec(ctx->unk0, &sp)) {
                u8 *a = it.info.unk8;
                char **d;
                func_0890CD14(ctx, info, a);
                d = (char **)(ctx->unk18 + sp.c);
                d[0] = ctx->unk4;
                d[1] = ctx->unk0;
                d[2] = ctx->unk8;
                d[5] = (char *)a;
                func_0890D95C(ctx, info, info->unk0 + sp.b);
            }
            continue;
        default:
            func_0890C224();
            break;
        }
        break;
    }
    return it.info.unk8;
}

}
