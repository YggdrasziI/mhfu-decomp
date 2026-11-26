/* unit_08821A10: 0x08821A10-0x08821ADC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct {
    s16 a;
    s16 b;
    s16 c;
} Triple;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    u16 h4;
    Triple t;
} Rec;

extern s32 func_08821B58(char *, char *, char *);
extern void func_08821CA8(char *, char *);
extern void func_088D897C(char *);
extern void func_088DAAA0(char *);
extern u8 func_088DAB94(char *, s16);

void func_08821A10(char *arg0, char *arg1, char *arg2) {
    Rec *dst;
    Rec *src;

    if ((u8)func_08821B58(arg0, arg1 + 0x4E8, arg2) != 0) {
        return;
    }
    dst = (Rec *)(arg1 + 0x4E8);
    src = (Rec *)arg2;
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->h2 = src->h2;
    dst->h4 = src->h4;
    dst->t = src->t;
    if (*(u8 *)(arg0 + 0x11BF) != src->b1) {
        func_08821CA8(arg0, arg1);
    }
    func_088D897C(arg1);
    func_088DAAA0(arg1);
    *(u8 *)(arg1 + 0x5F2) = func_088DAB94(arg1, *(s16 *)(arg1 + 0x60C));
    *(u8 *)(arg0 + 0x1206) = 1;
}
