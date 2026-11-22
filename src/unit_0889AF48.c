/* unit_0889AF48: 0x0889AF48-0x0889AFAC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;
typedef struct { F3 p0; F2 p1; } C3_2;

extern char *D_089CBBEC;

extern s32 func_088B0EC8(void *);
extern void func_0883D184(char *, void *, s32);
extern void func_0889C914(char *, void *);

void func_0889AF48(char *arg0) {
    C3_2 cp;
    char buf[200];

    cp.p0 = ((C3_2 *)arg0)->p0;
    cp.p1 = ((C3_2 *)arg0)->p1;
    func_088B0EC8(buf);
    func_0883D184(D_089CBBEC, buf + 8, 0);
    func_0889C914(*(char **)&cp.p0.c, buf);
}
