/* unit_088BEEC0: 0x088BEEC0-0x088BF26C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088BEEC0: state machine at 0xC. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern int memset(void *, s32, s32);
extern void func_088BF858(char *, s32);
extern void func_088C30B8(char *, s32, s32);
extern void func_088BFE54(char *, s32);
extern void func_088BA5BC(s16, s16, s16, s16);
extern void func_088BA494(s32, s32, s32);
extern char *func_08851680(char *, u16);
extern void func_088BFEF8(char *, char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088BA2E0(s32, s32, u8, s32);

static inline s32 read_choice(char *p) {
    s32 flags = D_08A62C6C;
    if (flags & 0x80) {
        if (*(u8 *)(p + 0x4) == 0) {
            *(u8 *)(p + 0x4) = 1;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if (flags & 0x20) {
        if (*(u8 *)(p + 0x4) != 0) {
            *(u8 *)(p + 0x4) = 0;
            func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        }
    } else if ((flags & 0x4000) && *(u8 *)(p + 0x4) != 0) {
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        return 2;
    } else if ((flags & 0x2000) || ((flags & 0x4000) && *(u8 *)(p + 0x4) == 0)) {
        func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

s32 func_088BEEC0(char *p) {
    s32 r = 0;
    s32 res;


    switch (*(s32 *)(p + 0xC)) {
    case 0:
        *(s32 *)(p + 0xC) = 1;
        memset(*(void **)(p + 0x94C), 0, 0x16A100);
        func_088BF858(p, 0);
    case 1:
        if (*(u8 *)(p + 0x970) == 0) {

            s32 m = *(s32 *)(p + 0x34);
            if (m == 0 || (m == 2 && *(s32 *)(p + 0x5E4) == 0)) {
                func_088C30B8(p, 0, 0);
                *(s32 *)(p + 0xC) = 2;
            } else if (m == 2 && *(s32 *)(p + 0x5E4) == 1) {
                memset(*(void **)(p + 0x94C), 0, 0x16A100);
                func_088BF858(p, 0);
            } else {
                func_088BFE54(p, m);
                *(s32 *)(p + 0xC) = 4;
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 2:
        if (*(u8 *)(p + 0x4A88) == 0) {
            if (*(u8 *)(p + 0x4A89) == 0) {
                func_088BFEF8(p, func_08851680(D_089CC438, 2));
                *(s32 *)(p + 0xC) = 4;
            } else {
                r = 1;
                func_08883988(D_08A62D8C, 0, 0x24, 0, 0, 0, 0, 0, 0);
            }
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x60, 0);
        break;
    case 4:
        if (*(u8 *)(p + 0x971) == 0) {
            *(u8 *)(p + 0x4) = 1;
            *(s32 *)(p + 0xC) = 3;
        }
        break;
    case 3:
        res = read_choice(p);
        if (res == 2) {
            r = 2;
            *(s32 *)(p + 0xC) = 0;
        } else if (res == 1) {
            *(s32 *)(p + 0xC) = 0;
        }
        func_088BA5BC(0x10, 0x54, 0x1C0, 0x68);
        func_088BA494(0xF0, 0x70, 0x1D);
        func_088BA2E0(0xB8, 0xA0, *(u8 *)(p + 0x4), 1);
        break;
    }
    return r;
}
