/* unit_0890CD14: 0x0890CD14-0x0890D4C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890CD14 (hypothesis: exception action interpreter of the C++
 * runtime, runs the actions of the frames until the given catch action).
 *
 * Optimized for speed, opt_propagation off (keeps the advanced action pointer
 * in a saved register). The catch case owns a two-word local: the original
 * leaves one unused stack word above it.
 */

#pragma optimize_for_size off
#pragma opt_propagation off

typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef void (*Dtor)(char *, s32);
typedef void (*Del)(char *);

typedef struct {
    u32 unk0;
    u32 unk4;
    u8 *unk8;
} Iter;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Catch;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    char *unk18;
    s32 unk1C;
    s32 unk20[1];
} Ctx;

extern u8 *func_0890C490(u8 *, s32 *);
extern u8 *func_0890C3F4(u8 *, s32 *);
extern u32 func_0890DC24(Ctx *, Iter *);
extern void func_0890D7BC(u32, Iter *);
extern void func_0890C224(void);
extern void func_0890DB88(Ctx *, Iter *);

#define RD32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
#define REG8(f, x) ((f) ? (s8) ctx->unk20[x] : *(s8 *) (ctx->unk18 + (x)))
#define REGP(f, x) ((f) ? (char *) ctx->unk20[x] : *(char **) (ctx->unk18 + (x)))

void func_0890CD14(Ctx *ctx, Iter *it, u8 *stop) {
    u8 *a;
    u32 b;

    for (;;) {
        do {
            if ((a = it->unk8) != 0) {
                break;
            }
            func_0890D7BC(func_0890DC24(ctx, it), it);
            if (it->unk4 == 0) {
                func_0890C224();
            }
            func_0890DB88(ctx, it);
        } while ((a = it->unk8) == 0);
        b = *a;
        switch (b & 0x1F) {
        case 1: {
            s32 off;
            func_0890C490(a + 1, &off);
            it->unk8 = it->unk8 + off;
            break;
        }
        case 2: {
            s32 off;
            u8 *p = func_0890C490(a + 1, &off);
            ((Dtor) RD32(p))(ctx->unk18 + off, -1);
            it->unk8 = p + 4;
            break;
        }
        case 3: {
            s32 cond;
            s32 off;
            u32 f = b & 0x40;
            u8 *p = func_0890C490(a + 1, &cond);
            Dtor dt;
            p = func_0890C490(p, &off);
            dt = (Dtor) RD32(p);
            p += 4;
            if (REG8(f, cond)) {
                dt(ctx->unk18 + off, -1);
            }
            it->unk8 = p;
            break;
        }
        case 4: {
            s32 ptr;
            u32 f = b & 0x20;
            u8 *p = func_0890C490(a + 1, &ptr);
            Dtor dt;
            dt = (Dtor) RD32(p);
            p += 4;
            dt(REGP(f, ptr), -1);
            it->unk8 = p;
            break;
        }
        case 5: {
            s32 off;
            s32 n;
            s32 size;
            u8 *p = func_0890C490(a + 1, &off);
            Dtor dt;
            s32 i;
            char *q;
            p = func_0890C3F4(p, &n);
            p = func_0890C3F4(p, &size);
            dt = (Dtor) RD32(p);
            p += 4;
            i = n;
            q = ctx->unk18 + off + i * size;
            while (i != 0) {
                q -= size;
                dt(q, -1);
                i--;
            }
            it->unk8 = p;
            break;
        }
        case 6: {
            s32 ptr;
            s32 off;
            u32 f = b & 0x20;
            u8 *p = func_0890C490(a + 1, &ptr);
            Dtor dt;
            p = func_0890C490(p, &off);
            dt = (Dtor) RD32(p);
            p += 4;
            dt(REGP(f, ptr) + off, 0);
            it->unk8 = p;
            break;
        }
        case 7: {
            s32 ptr;
            s32 off;
            u32 f = b & 0x20;
            u8 *p = func_0890C490(a + 1, &ptr);
            Dtor dt;
            p = func_0890C490(p, &off);
            dt = (Dtor) RD32(p);
            p += 4;
            dt(REGP(f, ptr) + off, -1);
            it->unk8 = p;
            break;
        }
        case 8: {
            s32 cond;
            s32 ptr;
            s32 off;
            u32 f = b & 0x20;
            u8 *p = func_0890C490(a + 1, &cond);
            Dtor dt;
            p = func_0890C490(p, &ptr);
            p = func_0890C490(p, &off);
            dt = (Dtor) RD32(p);
            p += 4;
            if (REG8(b & 0x40, cond)) {
                dt(REGP(f, ptr) + off, -1);
            }
            it->unk8 = p;
            break;
        }
        case 9: {
            s32 ptr;
            s32 off;
            s32 n;
            s32 size;
            u32 f = b & 0x20;
            u8 *p = func_0890C490(a + 1, &ptr);
            Dtor dt;
            s32 i;
            char *q;
            p = func_0890C490(p, &off);
            p = func_0890C3F4(p, &n);
            p = func_0890C3F4(p, &size);
            dt = (Dtor) RD32(p);
            p += 4;
            if (f) {
                q = (char *) ctx->unk20[ptr] + off;
            } else {
                q = *(char **) (ctx->unk18 + ptr) + off;
            }
            i = n;
            q += i * size;
            while (i != 0) {
                q -= size;
                dt(q, -1);
                i--;
            }
            it->unk8 = p;
            break;
        }
        case 10: {
            s32 ptr;
            u32 f = b & 0x20;
            u8 *p = func_0890C490(a + 1, &ptr);
            Del dt;
            dt = (Del) RD32(p);
            p += 4;
            dt(REGP(f, ptr));
            it->unk8 = p;
            break;
        }
        case 11: {
            s32 cond;
            s32 ptr;
            u32 f = b & 0x20;
            u8 *p = func_0890C490(a + 1, &cond);
            Del dt;
            p = func_0890C490(p, &ptr);
            dt = (Del) RD32(p);
            p += 4;
            if (REG8(b & 0x40, cond)) {
                dt(REGP(f, ptr));
            }
            it->unk8 = p;
            break;
        }
        case 12: {
            s32 pc[2];
            s32 info;
            u8 *p;
            if (stop == a) {
                return;
            }
            p = func_0890C3F4(a + 5, pc);
            it->unk8 = func_0890C490(p, &info);
            break;
        }
        case 13: {
            s32 off;
            u8 *p = func_0890C490(a + 1, &off);
            Catch *c = (Catch *) (ctx->unk18 + off);
            if (c->unk8 != 0) {
                if (ctx->unk4 == c->unk0) {
                    ctx->unk8 = c->unk8;
                } else {
                    ((Dtor) c->unk8)((char *) c->unk0, -1);
                }
            }
            it->unk8 = p;
            break;
        }
        case 15: {
            s32 n;
            s32 x1;
            s32 x2;
            u8 *p;
            if (stop == a) {
                return;
            }
            p = func_0890C3F4(a + 1, &n);
            p = func_0890C3F4(p, &x1);
            p = func_0890C490(p, &x2);
            it->unk8 = p + n * 4;
            break;
        }
        case 0:
        case 14:
        default:
            func_0890C224();
            break;
        }
        if (b & 0x80) {
            it->unk8 = 0;
        }
    }
}
