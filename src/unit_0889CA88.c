#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    s16 h[35];
} Half35;

typedef struct {
    u8 a;
    u8 b;
} Pair5A;

typedef struct {
    Addr8 addr;
    Half35 data;
    u32 w50;
    u8 b54;
    u8 b55;
    u8 b56;
    u8 b57;
    u16 h58;
    Pair5A p5A;
    Addr8 tail;
} Entry;

extern void memcpy(void *, void *, s32);
extern void func_0889C788(char *);

void func_0889CA88(char *obj, Entry *e) {
    s32 i;
    s32 j;
    s32 res;
    s32 n;
    Entry *dst;

    n = *(s8 *)(obj + 0x12D8);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            u8 x = (obj + i * 0x64 + j)[0x12DC];
            u8 y = e->addr.b[j];
            if (y < x) {
                res = -1;
                goto done;
            }
            if (x < y) {
                res = 1;
                goto done;
            }
        }
        res = 0;
done:
        if (res == 0) {
            memcpy(obj + i * 0x64 + 0x12DC, e, 0x64);
            return;
        }
    }
    if (n < 4) {
        dst = (Entry *)(obj + (s8)n * 0x64 + 0x12DC);
        dst->addr = e->addr;
        dst->data = e->data;
        dst->w50 = e->w50;
        dst->b54 = e->b54;
        dst->b55 = e->b55;
        dst->b56 = e->b56;
        dst->b57 = e->b57;
        dst->h58 = e->h58;
        dst->p5A = e->p5A;
        dst->tail = e->tail;
        (*(s8 *)(obj + 0x12D8))++;
        func_0889C788(obj);
    }
}
