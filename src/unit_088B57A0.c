/* unit_088B57A0: 0x088B57A0-0x088B5AC8 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between unit_088B5568 (NonMatching) and
 * unit_088B5AC8 (NonMatching).
 *
 * Message builders on the buffer of func_088AFE78 (kinds 0x12 and 0x13),
 * as func_088B4950. func_088B5968 reads the record list of a message from
 * func_088AFE84 into D_09A28E54 (count at D_09A28863) and, while not
 * hosting in state 2, copies it to D_09A29364 for an unknown sender.
 * func_088B5A70 answers with error 0x8014 unless D_09A28876 is set.
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

extern char D_09A28E54[];
extern char D_09A29364[];
extern u8 D_09A28863;
extern u8 D_09A28876;
extern s32 D_09A2886C;

extern void func_0880C084(void *, void *, s32);
extern void memset(void *, s32, s32);
extern void func_088AEF64(Addr8 *);
extern s32 func_088AEFE4(s32);
extern s32 func_088AFE78(void);
extern char *func_088AFE84(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFBC(s32, u16);
extern void func_088AFFD0(s32);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, Addr8 *);
extern char *func_088B0318(char *, char *);
extern char *func_088B0324(char *, char *);
extern char *func_088B0370(char *, char *);
extern char *func_088B03BC(u8 *, char *);
extern void func_088B6B14(s32);
extern s32 func_088B7A10(Addr8 *);
extern void func_088B7D78(s32, Addr8 *, Id *);

void func_088B5AC8(Id *arg0, Addr8 *arg1, u16 arg2);

void func_088B57A0(Id *arg0, Addr8 *arg1, u16 arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x12);
    func_088AFFBC(h, arg2);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
        func_088B7D78(1, arg1, &id);
    }
    *arg0 = id;
}

void func_088B5898(Id *arg0, Addr8 *arg1) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x13);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}

void func_088B5968(void) {
    Addr8 own;
    u8 n;
    char *src;
    s32 i;
    char *p;

    src = func_088AFE84();
    if (func_088AEFE4(0) == 0) {
        func_088AEF64(&own);
        src = func_088B03BC(&n, src);
        D_09A28863 = n;
        p = D_09A28E54;
        i = 0;
        if (n > 0) {
            do {
                src = func_088B0318(p, src);
                src = func_088B0324(p + 8, src);
                src = func_088B0370(p + 0x20, src);
                src = func_088B03BC((u8 *) (p + 0xC5), src);
                i++;
                p += 0xC8;
            } while (i < n);
        }
        if (D_09A28876 == 0 && D_09A2886C == 2 && func_088B7A10(&own) == 0) {
            func_0880C084(D_09A29364, D_09A28E54, 0x320);
        }
    }
    func_088B6B14(0);
}

void func_088B5A70(void) {
    Addr8 own;
    Id id;
    u16 err;

    err = 0;
    func_088AFE84();
    if (D_09A28876 == 0) {
        err = 0x8014;
    }
    func_088AEF64(&own);
    func_088B5AC8(&id, &own, err);
}
