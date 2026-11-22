/* unit_0889D0E0: 0x0889D0E0-0x0889D244 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern char *D_08A631A0;
extern u8 *func_0889C518(char *);
extern void memcpy(void *, void *, s32);
extern void func_088B0C8C(void *);

void func_0889D0E0(char *arg0, void *src, s32 size) {
    u8 *key;
    char *found;
    s32 i;
    s32 j;
    s32 r;
    u8 k;
    u8 *ent;

    if ((u8)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 0) {
        return;
    }
    k = *(u8 *)(arg0 + 0x12D5);
    if (k == 0 || k == 1 || k == 5) {
        return;
    }
    key = func_0889C518(arg0);
    for (i = 0; i < *(s8 *)(arg0 + 0xEE3); i++) {
        ent = (u8 *)(arg0 + i * 200 + 0x57C);
        for (j = 0; j < 6; j++) {
            if (key[j] < ent[j]) {
                r = -1;
                goto done;
            }
            if (ent[j] < key[j]) {
                r = 1;
                goto done;
            }
        }
        r = 0;
    done:
        if (r == 0) {
            found = arg0 + i * 200 + 0x57C;
            goto end;
        }
    }
    found = 0;
end:
    if (found != 0) {
        memcpy(found + 0x20, src, size);
        func_088B0C8C(found + 0x20);
    }
    *(s32 *)(arg0 + 0x12D0) = 60;
}
