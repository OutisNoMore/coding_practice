from matplotlib import pyplot
from rtlsdr import rtlsdr, RtlSdr
import sox

try:
    sdr = RtlSdr()
    sdr.sample_rate = 2.56e6
    sdr.center_freq = 91.5e6
    sdr.gain = 'auto'

    samples = sdr.read_samples(256*1024)

except rtlsdr.LibUSBError as err:
    print(err)
    quit()

