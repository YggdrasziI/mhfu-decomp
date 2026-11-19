/* unit_088B20C4: 0x088B20C4-0x088B21D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B2058 and unit_088B21D0.
 *
 * Request 0x22 for arg1 with the 16-bit code arg2 (plus func_088B32B8() when it is 0), then returns through arg0 the 20 bytes
 * at +4 of the reply when func_088B012C returns 0, zeroes otherwise (as
 * func_088B1204).
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
extern void func_088AFFE8(s32, u8);
extern void func_088AFFBC(s32, u16);
extern u8 func_088B32B8(void);

void func_088B20C4(Id *arg0, char *arg1, u16 arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x22);
    func_088AFFBC(h, arg2);
    if (arg2 == 0) {
        func_088AFFE8(h, func_088B32B8());
    }
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
