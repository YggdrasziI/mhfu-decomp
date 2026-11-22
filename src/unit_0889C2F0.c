/* unit_0889C2F0: 0x0889C2F0-0x0889C48C (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float x, y;
} Vec2;

typedef struct {
    Vec3 a;
    Vec2 b;
} Msg;

extern char *D_089CBBEC;
extern void func_088B0D2C(void *);
extern void func_0883D184(char *, char *, s32);
extern void memcpy(void *, void *, s32);

void func_0889C2F0(Msg *arg0) {
    Msg m;
    char *base;
    u8 buf[0xAC];
    s32 i;
    s32 j;
    s32 r;
    u8 old;
    s32 off;
    u8 c;
    u8 e;

    m.a = arg0->a;
    m.b = arg0->b;
    base = *(char **) &m.a.z;
    func_088B0D2C(buf);
    for (i = 0; i < *(s8 *) (base + 0xEE3); i++) {
        for (j = 0; j < 6; j++) {
            c = buf[j];
            e = (base + i * 200)[j + 0x57C];
            if (e < c) {
                r = -1;
                goto done;
            }
            if (c < e) {
                r = 1;
                goto done;
            }
        }
        r = 0;
    done:
        if (r == 0) {
            off = i * 200;
            old = base[off + 0x63B];
            if (old != buf[0xA7]) {
                if (buf[0xA7] == 5) {
                    func_0883D184(D_089CBBEC, base + (u8) i * 200 + 0x584, 1);
                }
                if (old == 5) {
                    func_0883D184(D_089CBBEC, base + (u8) i * 200 + 0x584, 2);
                }
            }
            memcpy(base + off + 0x59C, buf + 8, 0xA4);
            return;
        }
    }
}
