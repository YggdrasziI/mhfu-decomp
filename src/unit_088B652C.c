/* unit_088B652C: 0x088B652C-0x088B6A08 (ULES01213)
 *
 * Bounds (hypothesis): the first 9 functions of the text_088B652C asm
 * piece, between unit_088B650C and func_088B6A08.
 *
 * The tables at D_09A2851C: four 0x64-byte records at + 0xCB8
 * (D_09A291D4) and four 0xC8-byte records at + 0xE48 (D_09A29364):
 * count, find, add and remove.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    s32 w[0x19];
} Blk64;

typedef struct {
    s32 w[0x32];
} BlkC8;

typedef struct {
    s16 h[0x52];
} PartA4;

extern char D_09A2851C[];
extern char D_09A291D4[];
extern char D_09A29364[];

extern void func_0880C464(void *, s32, s32);
extern s32 func_088B04B4(void *);
extern s32 func_088B0514(void *, void *);

u8 func_088B652C(void) {
    s32 i;
    u8 n;
    char *p;

    n = 0;
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B04B4(p + 0xCB8)) {
            n++;
        }
        i++;
        p += 0x64;
    } while (i < 4);
    return n;
}

s32 func_088B6594(void *arg0) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(arg0, p + 0xCB8) == 0) {
            return 0;
        }
        i++;
        p += 0x64;
    } while (i < 4);
    return 1;
}

s32 func_088B65FC(Blk64 *arg0) {
    s32 i;
    char *p;
    char *q;
    s32 j;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(arg0, p + 0xCB8) == 0) {
            return 0;
        }
        i++;
        p += 0x64;
    } while (i < 4);
    j = 0;
    q = D_09A2851C;
    do {
        if (func_088B04B4(q + 0xCB8) == 0) {
            *(Blk64 *) (D_09A291D4 + j * 0x64) = *arg0;
            return 0;
        }
        j++;
        q += 0x64;
    } while (j < 4);
    return 0;
}

s32 func_088B66D0(void *arg0) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(arg0, p + 0xCB8) == 0) {
            func_0880C464(D_09A2851C + i * 0x64 + 0xCB8, 0, 0x64);
            return 1;
        }
        i++;
        p += 0x64;
    } while (i < 4);
    return 0;
}

s32 func_088B6768(void *arg0) {
    s32 i;
    char *p;

    p = D_09A29364;
    i = 0;
    do {
        if (func_088B0514(p, arg0) == 0) {
            return 0;
        }
        i++;
        p += 0xC8;
    } while (i < 4);
    return 1;
}

s32 func_088B67D0(BlkC8 *arg0) {
    s32 i;
    char *q;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        q = p + 0xE48;
        if (func_088B04B4(q) == 0) {
            *(BlkC8 *) q = *arg0;
            break;
        }
        i++;
        p += 0xC8;
    } while (i < 4);
    return 0;
}

s32 func_088B6864(void *arg0) {
    s32 i;
    char *p;

    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B0514(p + 0xE48, arg0) == 0) {
            func_0880C464(D_09A2851C + i * 0xC8 + 0xE48, 0, 0xC8);
            return 1;
        }
        i++;
        p += 0xC8;
    } while (i < 4);
    return 0;
}

u8 func_088B68FC(void) {
    s32 i;
    u8 n;
    char *p;

    n = 0;
    i = 0;
    p = D_09A2851C;
    do {
        if (func_088B04B4(p + 0xE48)) {
            n++;
        }
        i++;
        p += 0xC8;
    } while (i < 4);
    return n;
}

void func_088B6964(void *arg0, PartA4 *arg1) {
    s32 i;
    char *p;
    char *q;

    i = 0;
    p = D_09A2851C;
    do {
        q = p + 0xE48;
        if (func_088B0514(q, arg0) == 0) {
            *(PartA4 *) (q + 0x20) = *arg1;
            return;
        }
        i++;
        p += 0xC8;
    } while (i < 4);
}
