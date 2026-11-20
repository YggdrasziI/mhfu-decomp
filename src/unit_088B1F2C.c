/* unit_088B1F2C: 0x088B1F2C-0x088B2024 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1DB0 and unit_088B2024.
 *
 * Request 0x1D for arg1 with the 16-bit value arg2; when func_088B012C
 * returns 0, takes the 20 bytes at +4 of the reply and passes them to
 * func_088B7D78(2, arg1, ...). Returns them through arg0 (zeroes on
 * failure).
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 func_088AFE78(void);
extern void memset(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, char *);
extern void func_088AFFBC(s32, u16);
extern void func_088B7D78(s32, char *, Id *);

void func_088B1F2C(Id *arg0, char *arg1, u16 arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x1D);
    func_088AFFBC(h, arg2);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
        func_088B7D78(2, arg1, &id);
    }
    *arg0 = id;
}
