/* unit_0889AEF4: 0x0889AEF4-0x0889AF48 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;
typedef struct { F3 p0; F2 p1; } C3_2;

extern s32 func_088B1A04(void *);

void func_0889AEF4(char *arg0) {
    C3_2 cp1C;

    cp1C.p0 = ((C3_2 *)arg0)->p0;
    cp1C.p1 = ((C3_2 *)arg0)->p1;
    *(s32 *)((*(char * *)&cp1C.p0.c) + 0x12C4) = (s32) (*(s32 *)((*(char * *)&cp1C.p0.c) + 0x12C4) | 2);
    func_088B1A04((*(char * *)&cp1C.p0.c) + 0x146C);
}
