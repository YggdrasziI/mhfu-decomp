/* unit_0888307C: 0x0888307C-0x08883268 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */
#pragma optimize_for_size off

typedef int s32;

typedef struct {
    s32 a;
    s32 b;
} Pair;

extern s32 D_08A62D84;
extern Pair D_089AC454[][16];

extern s32 func_0887FF1C(s32);
extern void func_0887FBC4(s32, s32);
extern void func_0887FC40(s32, s32, s32, s32);

void func_0888307C(char *arg0, s32 arg1, s32 arg2) {
    s32 sum;
    s32 n;
    s32 end;
    s32 idx;
    s32 i;
    s32 old;
    s32 mid;

    idx = func_0887FF1C(D_08A62D84);
    if (idx == -1) {
        return;
    }
    sum = (s32)(arg0 + 0x549BD0);
    n = arg1;
    end = arg2;
    for (i = 0; i < n; i++) {
        sum += D_089AC454[idx][i].a;
        sum += D_089AC454[idx][i].b;
    }
    for (; n <= end; n++) {
        func_0887FBC4(D_08A62D84, n);
        old = sum;
        mid = sum + D_089AC454[idx][n].a;
        sum = mid + D_089AC454[idx][n].b;
        func_0887FC40(D_08A62D84, n, old, mid);
    }
}
