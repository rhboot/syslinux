#include <inttypes.h>
#include <sys/io.h>
#include <sys/pci.h>

void pci_writew(uint16_t v, pciaddr_t a)
{
  uint32_t oldcf8 = inl(0xcf8);

  outl(a, 0xcf8);
  outw(v, 0xcfc + (a & 3));
  outl(oldcf8, 0xcf8);
}
