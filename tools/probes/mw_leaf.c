/* Metrowerks probe: small leaf functions of ULES01213 BOOT.BIN, written from their
 * assembly. python tools/psp/compiler_probe.py tools/probes/mw_leaf.c --cc <mwccpsp.exe> -- -O4
 */

typedef struct {
    int a;
    char pad[8];
    short c;
    char pad2[10];
} S24;

typedef struct {
    float v;
    char pad[0x3C];
} F64;

extern int D_09A0FD84[];
extern unsigned short D_0893AACC[][56];
extern void func_088A2378(int, int);

/* strlen */
int func_0880EDF8(const unsigned char *s) {
    const unsigned char *start = s + 1;
    while (*s++) {
    }
    return s - start;
}

int func_088A6024(int i, int v) {
    D_09A0FD84[i] = v;
    return 0;
}

void func_08886850(S24 *s, int i, int v) {
    S24 *e = &s[i];
    e->c = v;
    func_088A2378(e->a, v);
}

int func_08822990(int unused, unsigned char *p) {
    if (p[0x4E9] == 6) {
        return 1;
    }
    return !(p[0x5F2] < 1);
}

int func_088303B8(int unused, unsigned short i, unsigned char j) {
    return D_0893AACC[j][i];
}

int func_08866284(unsigned char *p) {
    int r;
    int m = p[0x1E9];
    switch (m) {
    case 2:
        r = 0x40;
        break;
    case 1:
        r = 0x40;
        break;
    case 0:
        r = 0x20;
        break;
    default:
        r = 0xE0;
        break;
    }
    return r | p[0x1E4];
}

int func_08864408(char *p, int i, float x) {
    if (p[0x3E]) {
        return 0;
    }
    return x <= ((F64 *)(p + 0x10))[i].v;
}
