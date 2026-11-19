/* unit_088B3DE4: 0x088B3DE4-0x088B40B8 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B3DE4 asm piece, 4 functions
 * between unit_088B3BE4 and unit_088B40B8.
 *
 * func_088B3DE4 answers a request for the address arg0 with a status code
 * through func_088B6A08 (0 after copying the 0x320-byte record block
 * D_09A29364 into D_09A28E54, else 0x8000 / 0x8007 / 0x8002 / 0x8003) or
 * queues a 0x14-byte result with func_088B6BFC. func_088B3F60 copies the
 * accepted 0xC8-byte records at D_09A2851C + 0x938. func_088B403C dispatches
 * the phase of the record D_09A44094 (as func_088B3130).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad[0x11];
} Res14;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    s32 w[0x32];
} Blk;



typedef struct {
    char unk0[0x20];
    u8 unk20;
    u8 unk21;
} State;

extern char D_09A2851C[];
extern char D_09A28E54[];
extern char D_09A29364[];
extern u8 D_09A28876;
extern u8 D_09A28863;
extern char D_09A2887C[];
extern Addr8 D_09A29174;
extern u8 D_09A2917E;
extern char D_09A44094[];

extern void func_0880C464(void *, s32, s32);
extern void func_0880C084(void *, void *, s32);
extern s32 func_088AFB48(char *);
extern s32 func_088B04B4(void *);
extern s32 func_088B0514(void *, void *);
extern void func_088B5898(Res14 *, char *);
extern u8 func_088B68FC(void);
extern void func_088B6A08(s32, s32, s32);
extern s32 func_088B6BC4(void);
extern void func_088B6BFC(Res14 *, s32, s32);
extern void func_088B40B8(char *);
extern void func_088B41E0(char *);
extern void func_088B41EC(char *);

s32 func_088B3DE4(char *arg0, s32 arg1, s32 arg2) {
    Res14 res;

    func_0880C464(D_09A28E54, 0, 0x320);
    if (D_09A28876 != 0) {
        if (func_088B0514(D_09A2887C, arg0) == 0 || func_088B04B4(arg0) == 0) {
            D_09A28863 = func_088B68FC();
            func_0880C084(D_09A28E54, D_09A29364, 0x320);
            func_088B6A08(0, arg1, arg2);
            return 0;
        }
    }
    if (func_088B04B4(arg0) == 0) {
        func_088B6A08(0x8000, arg1, arg2);
        return 0;
    }
    if (func_088AFB48(arg0) != 0) {
        func_088B6A08(0x8007, arg1, arg2);
        return 0;
    }
    if (func_088B6BC4() != 0) {
        func_088B5898(&res, arg0);
        if (res.unk2 != 0) {
            func_088B6BFC(&res, arg1, arg2);
            return 0;
        }
        func_088B6A08(0x8003, arg1, arg2);
        return 0;
    }
    func_088B6A08(0x8002, arg1, arg2);
    return 0;
}

s32 func_088B3F60(u8 *arg0, char *arg1) {
    s32 i;
    char *p;
    Blk *dst;

    *arg0 = D_09A28863;
    dst = (Blk *) arg1;
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B04B4(p + 0x938)) {
            *dst = *(Blk *) (p + 0x938);
            dst++;
        }
        i++;
        p += 0xC8;
    } while (i < 4);
    return 0;
}

s32 func_088B3FFC(Addr8 *arg0, u8 *arg1) {
    *arg0 = D_09A29174;
    *arg1 = D_09A2917E;
    return 0;
}

void func_088B403C(void) {
    State *p = (State *) D_09A44094;

    if (p->unk20 != 0) {
        switch (p->unk21) {
        case 0:
            func_088B40B8((char *) p);
            break;
        case 1:
            func_088B41E0((char *) p);
            break;
        case 2:
            func_088B41EC((char *) p);
            break;
        }
    }
}
