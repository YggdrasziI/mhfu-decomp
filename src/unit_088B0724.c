/* unit_088B0724: 0x088B0724-0x088B089C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B06C0 and unit_088B089C.
 *
 * Builds the 24 network names (the group name D_09A28528 followed by a
 * two-digit number) in the 16-byte records at D_09A28950, copies them to
 * arg1 (24 networks, *arg0 = 0x18), then scans the ad hoc networks
 * (sceNetAdhocctlGetScanInfo into D_09A28534) and flags (+0xC) the
 * records whose name was found. Returns 0.
 *
 * NonMatching (96.17 %): only the end of the scan loop differs; the
 * original leaves with `beqzl s0` to the return and jumps back with `b`,
 * ours loops with `bnez`. Tried: `while (1)` with return / break, `do`
 * `while (s != 0)`, `goto`, `for (;;)` with `continue`, a test at the top
 * (94 %), and each `opt_*` / `peephole` / `scheduling` pragma off.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct Scan {
    struct Scan *next;
    s32 channel;
    char name[8];
} Scan;

typedef struct {
    char unk0[0x440];
    struct {
        u8 flag;
        char unk1[0xF];
    } tbl[0x18];
} Net;

extern Net D_09A2851C;
extern char D_09A28528[];
extern Scan D_09A28534;
extern char D_09A28950[];
extern char D_089B2A3C[];

extern s32 sceNetAdhocctlGetScanInfo(u32 *, void *);
extern void memset(void *, s32, s32);
extern void memcpy(void *, void *, s32);
extern int func_0880E8F0(char *, char *, ...);
extern u32 func_0880EDF8(char *);
extern int func_0880BFF0(void *, void *, int);

s32 func_088B0724(u8 *arg0, char *arg1) {
    u32 len;
    char num[0x20];
    s32 i;
    char *p;
    Scan *s;

    len = 0;
    *arg0 = 0x18;
    memset(D_09A28950, 0, 0x180);
    p = D_09A28950;
    i = 0;
    do {
        memcpy(p, D_09A28528, 6);
        func_0880E8F0(num, D_089B2A3C, i);
        if (func_0880EDF8(num) == 1) {
            p[6] = '0';
            p[7] = num[0];
        } else {
            p[6] = num[0];
            p[7] = num[1];
        }
        i++;
        p += 0x10;
    } while (i < 0x18);
    memcpy(arg1, D_09A28950, 0x180);
    len = 0x32C;
    if (sceNetAdhocctlGetScanInfo(&len, &D_09A28534) < 0) {
        return 0;
    }
    if (len == 0) {
        return 0;
    }
    s = &D_09A28534;
    while (1) {
        p = D_09A28950;
        i = 0;
        do {
            if (!func_0880BFF0(p, s->name, 8)) {
                D_09A2851C.tbl[i].flag = 1;
                break;
            }
            i++;
            p += 0x10;
        } while (i < 0x18);
        s = s->next;
        if (s == 0) {
            return 0;
        }
    }
}
