from rtlsdr import RtlSdr
import matplotlib.pyplot

# open device
sdr = RtlSdr()

# configure device
sdr.sample_rate = 2.048e6  # 2048 khz
sdr.center_freq = 95e6     # 95 Mhz
sdr.gain = 4

samples = sdr.read_samples(256*1024)
sdr.close()

matplotlib.pyplot.psd(samples, NFFT=1024, Fs=sdr.sample_rate/1e6, Fc=sdr.center_freq/1e6)
matplotlib.pyplot.xlabel('Frequency (Mhz)')
matplotlib.pyplot.ylabel('Relative Power (dB)')
