/* Probe for the non-Metrowerks code at the start of .text (notes/SPLITS.md):
 * small functions of ULES01213 BOOT.BIN, written from their assembly.
 * python tools/psp/compiler_probe.py tools/probes/lib_leaf.c --cc <compiler> -- <flags>
 */
typedef struct N { struct N *next; int key; } N;
typedef struct { char pad[0x4C]; N **tbl; } H;
extern int D_08933658;
extern int D_089CBAD8;
extern int D_089CBAD4;
extern int sceKernelCpuSuspendIntr(void);
extern void sceKernelCpuResumeIntr(int);

int func_0880B420(void) { return D_08933658; }

int func_0880EDF8(const unsigned char *s) {
    const unsigned char *start = s + 1;
    while (*s++) {
    }
    return s - start;
}

void func_0880C53C(void) {
    int s = sceKernelCpuSuspendIntr();
    if (D_089CBAD8 == 0) {
        D_089CBAD4 = s;
    }
    D_089CBAD8++;
}

void func_0880C578(void) {
    if (--D_089CBAD8 == 0) {
        sceKernelCpuResumeIntr(D_089CBAD4);
    }
}

void func_0880D97C(H *h, N *n) {
    if (n) {
        N **b = &h->tbl[n->key];
        n->next = *b;
        *b = n;
    }
}
