/* unit_088B32B8: 0x088B32B8-0x088B3718 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B32B8 asm piece, 8 functions
 * between unit_088B32AC and unit_088B3718.
 *
 * Lookups in the two arrays of four 0xC8-byte records at D_09A2851C +
 * 0xE48 and + 0x116C, and in the four 0x64-byte records at + 0xCB8.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s8 b[8];
} Addr8;

typedef struct {
    Addr8 addr;
    char unk8[0xBD];
    u8 unkC5;
    char padC6[2];
} Rec;

extern char D_09A2851C[];
extern Rec D_09A29688[];
extern u8 D_09A29429[];
extern u8 D_09A2974D[];

extern s32 func_088B04B4(void *);
extern s32 func_088B0514(void *, void *);
extern s32 func_088B652C(void);
extern void func_088B403C(void);
extern s32 func_088B6F64(s32, void (*)(void), s32, s32);
extern void func_088B6A08(s32, s32, s32);

u8 func_088B32B8(void) {
    s32 i;
    s32 n;
    char *p;

    n = 0;
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B04B4(p + 0xE48)) {
            if (((Rec *) (p + 0xE48))->unkC5 != 0) {
                n++;
            }
        }
        i++;
        p += sizeof(Rec);
    } while (i < 4);
    return n;
}

s32 func_088B3328(void *arg0, u8 arg1) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0xE48, arg0) == 0) {
            D_09A29429[i * sizeof(Rec)] = arg1;
            break;
        }
        i++;
        p += sizeof(Rec);
    } while (i < 4);
    return 0;
}

s32 func_088B33BC(void *arg0) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0xE48, arg0) == 0) {
            return 0;
        }
        i++;
        p += sizeof(Rec);
    } while (i < 4);
    return 0x8000;
}

u8 func_088B3424(void *arg0) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0xE48, arg0) == 0) {
            return D_09A29429[i * sizeof(Rec)];
        }
        i++;
        p += sizeof(Rec);
    } while (i < 4);
    return 0;
}

Rec *func_088B34AC(Addr8 *arg0) {
    s32 i;
    char *p;
    char *q;
    s32 j;
    s32 off;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0x116C, arg0) == 0) {
            return 0;
        }
        i++;
        p += sizeof(Rec);
    } while (i < 4);
    j = 0;
    q = D_09A2851C;
    do {
        if (func_088B04B4(q + 0x116C) == 0) {
            off = j * sizeof(Rec);
            *(Addr8 *) ((char *) D_09A29688 + off) = *arg0;
            return (Rec *) ((D_09A2851C + off) + 0x116C);
        }
        j++;
        q += sizeof(Rec);
    } while (j < 4);
    return 0;
}

s32 func_088B3594(void *arg0) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0x116C, arg0) == 0) {
            D_09A2974D[i * sizeof(Rec)] = 1;
            break;
        }
        i++;
        p += sizeof(Rec);
    } while (i < 4);
    return 0;
}

s32 func_088B3620(s32 arg0, s32 arg1) {
    if (func_088B6F64(7, func_088B403C, arg0, arg1) == 0) {
        return 0;
    }
    func_088B6A08(0x8005, arg0, arg1);
    return 0;
}

s32 func_088B3684(u8 *arg0, char *arg1) {
    s32 i;
    char *p;
    s32 *src;
    s32 *dst;
    s32 j;

    *arg0 = func_088B652C();
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B04B4(p + 0xCB8)) {
            src = (s32 *) (p + 0xCB8);
            j = 0x19;
            dst = (s32 *) arg1;
            do {
                j -= 1;
                *dst = *src;
                src++;
                dst++;
            } while (j > 0);
            arg1 += 0x64;
        }
        i++;
        p += 0x64;
    } while (i < 4);
    return 0;
}
