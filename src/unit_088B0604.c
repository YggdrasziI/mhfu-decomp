/* unit_088B0604: 0x088B0604-0x088B06C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B05B8 and unit_088B06C0.
 *
 * Reads the peer list of the ad hoc network (at most 0xAB0 bytes):
 * returns through arg1 the number of peers, writes their addresses to
 * arg0 (func_088B05B8) and synchronises the peer table with the list
 * (func_088AD708). Returns the result of sceNetAdhocctlGetPeerList, 0 when
 * the size query fails. The buffer is 8-byte aligned (a `u64` array): a
 * `char` array is placed 4 bytes higher.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Entry Entry;

extern s32 sceNetAdhocctlGetPeerList(u32 *, void *);
extern void memset(void *, s32, s32);
extern s32 func_088B059C(void *);
extern s32 func_088B05B8(char *, void *);
extern s32 func_088AD708(void *, u32);

s32 func_088B0604(char *arg0, s32 *arg1) {
    u32 len;
    u64 buf[0xAB0 / 8];
    s32 ret;

    len = 0;
    ret = sceNetAdhocctlGetPeerList(&len, 0);
    if (ret < 0) {
        return 0;
    }
    if (len != 0) {
        if (len >= 0xAB0) {
            len = 0xAB0;
        }
        memset(buf, 0, sizeof(buf));
        ret = sceNetAdhocctlGetPeerList(&len, buf);
        *arg1 = func_088B059C(buf);
        func_088B05B8(arg0, buf);
    }
    func_088AD708(buf, len);
    return ret;
}
