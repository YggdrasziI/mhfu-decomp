/* unit_0889E6A4: 0x0889E6A4-0x0889E848 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern char *D_09A0B544;
extern void func_0889D8A8(char *, char *, s32, s32 *);
extern int func_0889E670(char *);

void func_0889E6A4(char *arg0) {
    char *base;
    char *found;
    s32 i;
    s32 j;
    s32 r;
    u8 *ent;

    switch (*(s32 *)(arg0 + 0xC)) {
    default:
        return;
    case 0:
        func_0889D8A8(D_09A0B544, arg0 + 3, *(s32 *)(arg0 + 0x18), *(s32 **)(arg0 + 0x1C));
        *(s32 *)(arg0 + 0x10) = 150;
        *(s8 *)(arg0 + 1) = 1;
        *(s8 *)(arg0 + 2) = 5;
        (*(s32 *)(arg0 + 0xC))++;
    case 1:
        break;
    }
    base = D_09A0B544;
    for (i = 0; i < *(s8 *)(base + 0xEE3); i++) {
        ent = (u8 *)(base + i * 200 + 0x57C);
        for (j = 0; j < 6; j++) {
            if ((u8)arg0[3 + j] < ent[j]) {
                r = -1;
                goto done;
            }
            if (ent[j] < (u8)arg0[3 + j]) {
                r = 1;
                goto done;
            }
        }
        r = 0;
    done:
        if (r == 0) {
            found = base + i * 200 + 0x57C;
            goto end;
        }
    }
    found = 0;
end:
    if (found == 0) {
        func_0889E670(arg0);
        *(s32 *)(arg0 + 0x14) = 2;
    }
    if (*(u8 *)(arg0 + 1) == 0) {
        func_0889E670(arg0);
        *(s32 *)(arg0 + 0x14) = 0;
        return;
    }
    if (--*(s32 *)(arg0 + 0x10) < 0) {
        if (--*(s8 *)(arg0 + 2) < 0) {
            func_0889E670(arg0);
            *(s32 *)(arg0 + 0x14) = 2;
        } else {
            func_0889D8A8(D_09A0B544, arg0 + 3, *(s32 *)(arg0 + 0x18), *(s32 **)(arg0 + 0x1C));
            *(s32 *)(arg0 + 0x10) = 150;
        }
    }
}
