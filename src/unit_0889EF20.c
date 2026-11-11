/* unit_0889EF20: 0x0889EF20-0x0889EF40 (ULES01213)
 *
 * Bounds (hypothesis): one function (waits on the semaphore of entry i) between unrelated code.
 */

typedef struct {
    int sema;
    char pad[12];
} Entry; /* 16 bytes */

extern Entry D_089B1FFC[];
extern int sceKernelWaitSema(int semaid, int signal, void *timeout);

void func_0889EF20(int i) {
    sceKernelWaitSema(D_089B1FFC[i].sema, 1, 0);
}
