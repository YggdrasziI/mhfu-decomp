/* unit_088B7A5C: 0x088B7A5C-0x088B7F5C (ULES01213)
 *
 * Bounds (hypothesis): the first 7 functions of the text_088B7A5C asm
 * piece, between unit_088B7A38 and func_088B7F5C.
 *
 * The 16 0xA8-byte address entries at D_09A2851C + 0x1BC18 (D_09A44134):
 * an 8-byte address and eight 0x14-byte identifiers (D_09A4413C); fill
 * from the records at D_09A1FDE0 + 0xB8, add, remove, match and store an
 * identifier. func_088B7E74 handles a status code from the network
 * library.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    s8 b[6];
    u8 unk6;
    u8 unk7;
    s8 pad[0xC];
} Info14;

extern char D_09A1FDE0[];
extern char D_09A2851C[];
extern char D_09A44134[];
extern char D_09A4413C[];
extern u32 D_09A1FE04;
extern char D_09A1FE08[];

extern void memset(void *, s32, s32);
extern void func_088AEF64(Addr8 *);
extern s32 func_088AEDA0(Addr8 *, char *);
extern s32 func_088AF7E0(Addr8 *);
extern void func_088AFAD0(Addr8 *);
extern s32 func_088B04B4(void *);
extern s32 func_088B0514(void *, void *);

void func_088B7A5C(void) {
    s32 i;
    char *p;
    char *q;

    i = 0;
    p = D_09A1FDE0;
    q = D_09A2851C;
    do {
        if (func_088B04B4(p + 0xB8)) {
            *(Addr8 *) (q + 0x1BC18) = *(Addr8 *) (p + 0xB8);
            q += 0xA8;
        }
        i++;
        p += 0xC8;
    } while (i < 4);
}

void func_088B7AF4(Addr8 *arg0) {
    s32 i;
    char *p;
    char *q;
    s32 j;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0x1BC18, arg0) == 0) {
            return;
        }
        i++;
        p += 0xA8;
    } while (i < 4);
    j = 0;
    q = D_09A2851C;
    do {
        if (func_088B04B4(q + 0x1BC18) == 0) {
            *(Addr8 *) (D_09A44134 + j * 0xA8) = *arg0;
            return;
        }
        j++;
        q += 0xA8;
    } while (j < 4);
}

void func_088B7BD8(Addr8 *arg0) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0x1BC18, arg0) == 0) {
            memset(D_09A2851C + i * 0xA8 + 0x1BC18, 0, 0xA8);
            return;
        }
        i++;
        p += 0xA8;
    } while (i < 4);
}

s32 func_088B7C7C(u16 idx, Addr8 *arg1, Info14 *arg2) {
    Info14 info;
    u8 k6;
    u8 k7;
    s32 i;
    char *p;
    char *q;

    info = *arg2;
    k6 = info.unk6;
    k7 = info.unk7;
    i = 0;
    p = D_09A2851C;
    q = D_09A2851C + idx * 0x14;
    do {
        if (func_088B0514(p + 0x1BC18, arg1) == 0) {
            if (*(u8 *) (q + 0x1BC26) == k6 && *(u8 *) (q + 0x1BC27) == k7) {
                return 1;
            }
        }
        i++;
        p += 0xA8;
        q += 0xA8;
    } while (i < 0x10);
    return 0;
}

void func_088B7D78(u16 idx, Addr8 *arg1, Id *arg2) {
    Id id;
    s32 i;
    char *p;

    id = *arg2;
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0x1BC18, arg1) == 0) {
            *(Id *) (D_09A4413C + i * 0xA8 + idx * 0x14) = id;
            return;
        }
        i++;
        p += 0xA8;
    } while (i < 0x10);
}

void func_088B7E74(u16 code) {
    Addr8 own;
    s32 t;

    memset(&own, 0, sizeof(own));
    func_088AEF64(&own);
    switch (code) {
    case 0x6001:
    case 0x6002:
    case 0x6003:
    case 0x6004:
    case 0x6005:
    case 0x6201:
    case 0x6202:
    case 0x6205:
        return;
    }
    t = D_09A1FE04 != 0;
    if (t) {
        t = func_088AEDA0(&own, D_09A1FE08) == 0;
    }
    if (t && func_088AF7E0(&own) == 0) {
        func_088AFAD0(&own);
    }
}
