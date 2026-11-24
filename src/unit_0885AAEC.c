/* unit_0885AAEC: 0x0885AAEC-0x0885AC8C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885AAEC: allocates an object with func_08859B44 and runs its
 * inlined constructor. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct { f32 a, b; } F2;
typedef struct { f32 a, b, c; } F3;

/* layout of ScePspDateTime in pspsdk (psptypes.h) */
typedef struct {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u32 microsecond;
} ScePspDateTime;

extern int sceRtcGetCurrentClockLocalTime(ScePspDateTime *);
extern void func_08890080(char *, u8);
extern void func_08852C20(char *, s32);
extern void func_088572E8(char *);
extern void func_088689F4(char *);
extern void *func_08859B44(void *, s32, s32);
extern char *func_08897290(s32, void *);
extern s32 __ptmf_test(f32 *);

extern char *D_08A631A0;
extern char *D_089CC438;
extern char *D_08A62C60;
extern char *D_08A8B1E8;
extern char *D_089CC01C;
extern F2 D_0899D170;
extern f32 D_0899D178;
extern f32 D_0899D17C;
extern F2 D_0899D188;
extern f32 D_0899D190;
extern f32 D_0899D194;
extern char D_089BAB98;
extern char D_089BAA94;

void func_0885AAEC(char *arg0) {
    ScePspDateTime t;
    F3 w;
    F3 v;
    char *g;
    char *p;
    void *mem;

    sceRtcGetCurrentClockLocalTime(&t);
    func_08890080(D_08A631A0, t.second);
    func_08852C20(D_089CC438, 1);
    func_088572E8(D_089CC438);
    func_088689F4(D_08A62C60);
    g = D_08A8B1E8;
    mem = func_08859B44(g + 0x14010, 0x34, 16);
    if (mem != 0) {
        p = func_08897290(0x34, mem);
        if (p != 0) {
            *(char **)p = &D_089BAB98;
            v.a = D_0899D170.b;
            v.b = D_0899D178;
            v.c = D_0899D17C;
            if (__ptmf_test((f32 *)&v) != 0) {
                *(F3 *)(p + 0x4) = v;
            }
            D_089CC01C = (char *)((s32)(p + 0x1C) - 0x1C);
            *(char **)p = &D_089BAA94;
        }
        *(char **)(g + 8) = p;
        if (p != 0) {
            p[0x10] = 2;
            *(s32 *)(*(char **)(g + 8) + 0x14) = 12;
            p = *(char **)(g + 8);
            p[0x11] = 2;
            p[0x12] = 0;
        }
    }
    *(s32 *)(arg0 + 0x1C) = 0;
    w.a = D_0899D188.b;
    w.b = D_0899D190;
    w.c = D_0899D194;
    if (__ptmf_test((f32 *)&w) != 0) {
        *(F3 *)(arg0 + 0x4) = w;
    }
}
