/* unit_0889C144: 0x0889C144-0x0889C1AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef int s32;
typedef unsigned int u32;
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
    char pad[0x64];
} Buf;

extern void func_088B3A3C(Buf *);
extern void func_0889CA88(char *, Buf *);

void func_0889C144(Arg *arg) {
    Arg copy;
    char *p;
    Buf buf;

    copy.a = arg->a;
    copy.b = arg->b;
    p = *(char **)&copy.a.c;
    func_088B3A3C(&buf);
    func_0889CA88(p, &buf);
    *(u32 *)(p + 0x12C4) |= 0x800;
}
