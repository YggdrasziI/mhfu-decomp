/* unit_0889E1E0: 0x0889E1E0-0x0889E368 (ULES01213)
 *
 * Starts from the 8-byte record returned by func_0889C518(arg0) and, over the
 * 0xC8-byte entries at +0x57C (count at +0xEE3) whose byte +0xBF is neither 4
 * nor 5, keeps the one whose first six bytes compare lowest; returns it.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct { s8 b[6]; } Id6;
typedef struct { u8 b[2]; } B2;
typedef struct { Id6 id; B2 x; } Key;

extern Key *func_0889C518(u8 *);

static inline u8 *get(u8 *base, u8 idx) {
    return base + idx * 200 + 0x57C;
}

static inline s32 cmp6(u8 *a, u8 *b) {
    s32 k;
    for (k = 0; k < 6; k++) {
        if (a[k] < b[k]) {
            return -1;
        }
        if (b[k] < a[k]) {
            return 1;
        }
    }
    return 0;
}

Key func_0889E1E0(u8 *arg0) {
    Key key;
    s32 i;
    u8 *p;

    key = *func_0889C518(arg0);
    for (i = 0; i < *(s8 *)(arg0 + 0xEE3); i++) {
        if (get(arg0, i) != 0 && get(arg0, i)[0xBF] != 4 && get(arg0, i)[0xBF] != 5) {
            p = get(arg0, i);
            if (cmp6((u8 *)&key, p) > 0) {
                key.id = ((Key *)p)->id;
                key.x = ((Key *)p)->x;
            }
        }
    }
    return key;
}
