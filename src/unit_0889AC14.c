/* unit_0889AC14: 0x0889AC14-0x0889ADE8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    f32 a, b, c;
} F3;
typedef struct {
    f32 a, b;
} F2;
typedef struct {
    F3 a;
    F2 b;
} Arg;

typedef struct {
    u8 b[6];
} Id;

extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern void func_088B19CC(char *);
extern void func_0889C81C(char *);
extern void func_0889CF34(char *, s32);
extern void func_0889D6EC(char *);
extern s32 func_0889ADE8(char *);

/* The u8 * parameters copied into Id * locals keep the per-index sums
 * (no strength reduction of the key pointer). */
static inline s32 cmp6(u8 *arg0, u8 *arg1) {
    Id *a = (Id *)arg0;
    Id *b = (Id *)arg1;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (a->b[i] < b->b[i]) {
            return -1;
        }
        if (a->b[i] > b->b[i]) {
            return 1;
        }
    }
    return 0;
}

static inline char *find(char *p, u8 *key) {
    s32 j;

    for (j = 0; j < *(s8 *)(p + 0xEE3); j++) {
        if (cmp6(key, (u8 *)(p + j * 200 + 0x57C)) == 0) {
            return p + j * 200 + 0x57C;
        }
    }
    return 0;
}

void func_0889AC14(Arg *arg) {
    Arg copy;
    char *p;
    char *e;
    char *src;
    char *dst;
    u32 i;
    u32 n;

    copy.a = arg->a;
    copy.b = arg->b;
    p = *(char **)&copy.a.c;
    *(u32 *)(p + 0x12C0) &= ~0x4000;
    *(u8 *)(p + 0x1AF4) = *(s8 *)&copy.b.a == 0;
    *(u32 *)(p + 0x1AF8) = *(u16 *)&copy.b.b;
    if (*(u8 *)(p + 0x1AF4)) {
        if (*(u8 *)(p + 0x12D5) == 4) {
            memset(p + 0xBBC, 0, 0x324);
            func_088B19CC(p + 0xBBC);
            func_0889C81C(p);
            func_0889CF34(p, 5);
            func_0889D6EC(p);
            n = *(u8 *)(p + 0xBBD);
            dst = p + 0xBC0;
            for (i = 0; i < n; i++, dst += 200) {
                e = find(p, (u8 *)dst);
                src = e ? e + 0x20 : 0;
                if (src) {
                    memcpy(dst + 0x20, src, 0xA4);
                }
            }
            if (!func_0889ADE8(p)) {
                *(u8 *)(p + 0x1AFC) = 1;
            }
        }
    } else {
        *(u8 *)(p + 0x1AFC) = 1;
    }
}
