/* unit_08819CF8: 0x08819CF8-0x08819E10 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08819CF8: a framed label (optional box) at the position of entry
 * `idx` of a table of three halfwords (x, y, flags).
 *
 * D_08938564 is declared const: it moves the `sw s0` prologue save after
 * its load (as in the original); const on the other tables breaks it. */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089ACA00;
extern u16 D_08938560[];
extern u16 D_08938562[];
extern const u16 D_08938564[];
extern char D_08938478[];

extern void func_0882DCA8(char *, u16, u16, s32, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern char *func_0885151C(char *, u16);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_08819CF8(char *a0, u8 idx)
{
    if (D_08938564[idx * 3] & 1) {
        func_0882DCA8(a0, D_08938560[idx * 3] - 12, D_08938562[idx * 3] - 8, 0x50, 0x20, 0xFF);
    }
    func_0882A9DC(a0, D_08938560[idx * 3], D_08938562[idx * 3], 0x3A);
    func_08890DE8(D_08A631A8, 14, 14);
    func_088915B0(D_08A631A8, D_08938560[idx * 3] + 22, D_08938562[idx * 3] + 1, 0, D_08938478,
                  func_0885151C(D_089CC438, D_089ACA00));
}
