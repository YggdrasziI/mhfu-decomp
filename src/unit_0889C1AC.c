/* unit_0889C1AC: 0x0889C1AC-0x0889C214 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef float f32;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} F3;

typedef struct {
    f32 x;
    f32 y;
} F2;

typedef struct {
    F3 a;
    F2 b;
} Msg_0889C1AC;

extern void func_088B3A3C(void *);
extern void func_0889CA88(char *, void *);

void func_0889C1AC(Msg_0889C1AC *arg0) {
    char *p;
    Msg_0889C1AC m;
    char buf[0x64];

    m.a = arg0->a;
    m.b = arg0->b;
    p = *(char **) ((char *) &m + 8);
    func_088B3A3C(buf);
    func_0889CA88(p, buf);
    *(s32 *) (p + 0x12C4) |= 0x1000;
}
