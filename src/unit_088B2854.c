/* unit_088B2854: 0x088B2854-0x088B29A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B27C8 and unit_088B29A4.
 *
 * Request 0x20 for arg1 with the two bytes of arg2 and, for each of the
 * arg2[1] 0xC8-byte records of arg3, its byte at +0xC4 and its three parts
 * (func_088B0240, func_088B0284, func_088B02C8); then returns through arg0
 * the 20 bytes at +4 of the reply when func_088B012C returns 0, zeroes
 * otherwise (as func_088B1204).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    char unk0[0xC4];
    u8 unkC4;
    char padC5[3];
} Rec;

extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, char *);
extern void func_088AFFE8(s32, u8);
extern void func_088B0240(s32, char *);
extern void func_088B0284(s32, char *);
extern void func_088B02C8(s32, char *);

void func_088B2854(Id *arg0, char *arg1, u8 *arg2, Rec *arg3) {
    s32 i;
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x20);
    func_088AFFE8(h, arg2[0]);
    func_088AFFE8(h, arg2[1]);
    i = 0;
    if (arg2[1] > 0) {
        do {
            func_088AFFE8(h, arg3->unkC4);
            func_088B0240(h, arg3->unk0);
            func_088B0284(h, arg3->unk0 + 8);
            func_088B02C8(h, arg3->unk0 + 0x20);
            i++;
            arg3++;
        } while (i < arg2[1]);
    }
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
