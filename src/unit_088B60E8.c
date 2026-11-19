/* unit_088B60E8: 0x088B60E8-0x088B6338 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B60E8 asm piece, 3 functions
 * between unit_088B608C and unit_088B6338.
 *
 * Message builders on the buffer of func_088AFE78 (kinds 0x1A and 0x1B),
 * as func_088B4950; func_088B60E8 answers the sender of the current
 * message of func_088AFE84 with status 0 and the value of func_088B68FC.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    s8 b[0x14];
} Id;

extern char D_09A2887C[];

extern void func_0880C464(void *, s32, s32);
extern void func_088AEF64(Addr8 *);
extern s32 func_088AFE78(void);
extern char *func_088AFE84(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFBC(s32, u16);
extern void func_088AFFD0(s32);
extern void func_088AFFE8(s32, u8);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, Addr8 *);
extern void func_088B0240(s32, char *);
extern char *func_088B03CC(u16 *, char *);
extern s32 func_088B68FC(void);

void func_088B614C(Id *arg0, Addr8 *arg1, u16 arg2, u8 arg3);

void func_088B60E8(void) {
    u16 port;
    Addr8 own;
    Id id;
    char *src;

    src = func_088AFE84();
    func_0880C464(&own, 0, sizeof(own));
    func_088AEF64(&own);
    func_088B03CC(&port, src);
    func_088B614C(&id, &own, 0, (u8) func_088B68FC());
}

void func_088B614C(Id *arg0, Addr8 *arg1, u16 arg2, u8 arg3) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x1A);
    func_088AFFBC(h, arg2);
    func_088AFFE8(h, arg3);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}

void func_088B624C(Id *arg0, u8 arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    func_0880C464(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 0x1B);
    func_088B0240(h, D_09A2887C);
    func_088AFFE8(h, arg1);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
