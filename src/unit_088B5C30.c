/* unit_088B5C30: 0x088B5C30-0x088B5D3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B5AC8 (NonMatching) and
 * text_088B5D3C.
 *
 * Message builder (kind 0x17) with an address, a name and data, as
 * func_088B4950.
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern void func_0880C464(void *, s32, s32);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, s32);
extern void func_088B0240(s32, char *);
extern void func_088B0284(s32, char *);
extern void func_088B02C8(s32, char *);

void func_088B5C30(Id *arg0, char *arg1, char *arg2, char *arg3) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 0x17);
    func_088B0240(h, arg1);
    func_088B0284(h, arg2);
    func_088B02C8(h, arg3);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
