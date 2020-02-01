#include <uspi/usbgamepaddecoders.h>
#include <uspios.h>

#define REPORT_LEN 64

void USBGamePadDeviceReportDecoder_PS4(TUSBGamePadDevice *d)
{
    u8 *report = d->m_pReportBuffer;
    DebugHexdump(report, REPORT_LEN, "ds4 controller");

    d->m_nReportSize = REPORT_LEN;
}
