/* unit_088B1CA8: 0x088B1CA8-0x088B1DB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1C34 and unit_088B1DB0.
 *
 * Request 0x1C for arg1 with the 16-bit value arg2 and the byte arg3, then
 * returns through arg0 the 20 bytes at +4 of the reply when func_088B012C
 * returns 0, zeroes otherwise (as func_088B1204).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 func_088AFE78(void);
extern void func_0880C464(void *, s32, s32);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, char *);
extern void func_088B0010(s32, u16);
extern void func_088AFFE8(s32, u8);

void func_088B1CA8(Id *arg0, char *arg1, u16 arg2, u8 arg3) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x1C);
    func_088B0010(h, arg2);
    func_088AFFE8(h, arg3);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
