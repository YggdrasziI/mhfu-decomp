/* unit_088B0554: 0x088B0554-0x088B059C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B04EC and unit_088B059C.
 *
 * Copies the 6-byte wireless address of the console to arg0; returns the
 * error of sceWlanGetEtherAddr, 0 on success.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 sceWlanGetEtherAddr(u8 *);
extern void func_0880C084(void *, void *, s32);

s32 func_088B0554(u8 *arg0) {
    u8 mac[8];
    s32 ret;

    ret = sceWlanGetEtherAddr(mac);
    if (ret < 0) {
        return ret;
    }
    func_0880C084(arg0, mac, 6);
    return 0;
}
