/* unit_08821924: 0x08821924-0x08821A10 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    Vec3s v;
} Rec;

extern void func_088D897C(char *);
extern void func_088DAAA0(char *);
extern u8 func_088DAB94(char *, s16);

void func_08821924(char *arg0, char *arg1) {
    s32 i;
    Rec *src;
    Rec *dst;
    char *s;
    char *d;

    if (*(u8 *)(arg0 + 0x1206) == 1) {
        i = 0;
        s = arg0;
        d = arg1;
        for (; i < 5; i++, s += sizeof(Rec), d += sizeof(Rec)) {
            src = (Rec *)(s + 0x11CA);
            dst = (Rec *)(d + 0x4F4);
            dst->a = src->a;
            dst->b = src->b;
            dst->c = src->c;
            dst->d = src->d;
            dst->v = src->v;
        }
        dst = (Rec *)(arg1 + 0x4E8);
        src = (Rec *)(arg0 + 0x11BE);
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
        dst->v = src->v;
        func_088D897C(arg1);
        func_088DAAA0(arg1);
        *(u8 *)(arg1 + 0x5F2) = func_088DAB94(arg1, *(s16 *)(arg1 + 0x60C));
        *(u8 *)(arg0 + 0x1206) = 0;
    }
}
