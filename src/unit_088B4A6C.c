/* unit_088B4A6C: 0x088B4A6C-0x088B4C64 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B4A6C asm piece, 3 functions
 * between unit_088B4A14 and unit_088B4C64.
 *
 * Message builders on the buffer of func_088AFE78 (kinds 0xE and 0x15, as
 * func_088B4950): each returns the 0x14-byte identifier in arg0, zero when
 * func_088B012C fails.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    s8 b[8];
} Addr8;

extern char D_09A28B98[];
extern u8 D_09A28876;

extern void memset(void *, s32, s32);
extern void func_088AEF64(Addr8 *);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFBC(s32, u16);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, Addr8 *);
extern void func_088B63A4(char *);

void func_088B4A94(Id *arg0, Addr8 *arg1);

void func_088B4A6C(void) {
    Addr8 addr;
    Id id;

    func_088AEF64(&addr);
    func_088B4A94(&id, &addr);
}

void func_088B4A94(Id *arg0, Addr8 *arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0xE);
    if (D_09A28876 != 0) {
        func_088B63A4(D_09A28B98);
    } else {
        func_088AFFBC(h, 0x8000);
    }
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}

void func_088B4B94(Id *arg0) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(0, 0);
    func_088AFE90(h, 0x15);
    func_088B63A4(D_09A28B98);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
