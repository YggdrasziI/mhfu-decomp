/* unit_088B4E54: 0x088B4E54-0x088B4FA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B4D78 and unit_088B4FA4.
 *
 * Message builder (kind 0xF) to the address arg1: the 16-bit value arg3,
 * the data arg2 with its length at +0x12 (a zero word when it is empty),
 * then D_09A28884 and D_09A2889C; as func_088B4950.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern char D_09A28884[];
extern char D_09A2889C[];

extern void func_0880C464(void *, s32, s32);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern void func_088B0010(s32, s32);
extern void func_088B00DC(s32, char *, u16);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, s32);
extern void func_088B0284(s32, char *);
extern void func_088B02C8(s32, char *);

void func_088B4E54(Id *arg0, s32 arg1, char *arg2, s32 arg3) {
    s32 h;
    Id id;
    char zero[4];

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0xF);
    func_088B0010(h, arg3);
    if (*(u16 *) (arg2 + 0x12) == 0) {
        func_0880C464(zero, 0, sizeof(zero));
        func_088B00DC(h, zero, 0);
    } else {
        func_088B00DC(h, arg2, *(u16 *) (arg2 + 0x12));
    }
    func_088B0284(h, D_09A28884);
    func_088B02C8(h, D_09A2889C);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
