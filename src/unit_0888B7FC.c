/* unit_0888B7FC: 0x0888B7FC-0x0888B884 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    char pad0[0xC];
    float fC;
} Entry;

typedef struct {
    char pad0[0x20];
    Entry e[1];
} Ctx;

extern char *D_089CBBE4;
extern char D_08A62DA0[];

extern void func_0888C3AC(char *, Entry *, s32);
extern void func_0888B600(char *, char *, char *, float);

void func_0888B7FC(char *arg0, char *arg1, Ctx *arg2) {
    char *g = D_089CBBE4;
    u8 idx;

    func_0888C3AC(arg0, arg2->e, *(u8 *)((char *)arg2 + 0x280));
    idx = *(u8 *)(g + 0xAA0);
    func_0888B600(arg0, arg1, D_08A62DA0 + idx * 0x40,
                  *(float *)(g + 0xA9C) * arg2->e[idx].fC);
}
