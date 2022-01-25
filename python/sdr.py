import time
import rtlsdr 
import matplotlib.pyplot

# open device
try:
    sdr = rtlsdr.RtlSdr()

    # configure device
    sdr.sample_rate = 3.2e6  # Max sample rate of rtl-sdr is 3.2 Mhz
                             # Only reliable up to 2.56 Mhz
    sdr.center_freq = 91.5e6 # Center 95 Mhz
    sdr.gain = 'auto'

    matplotlib.pyplot.ion()                         # set interactive mode on - allows for updating graph
    fig = matplotlib.pyplot.figure()                # pyplot figure to draw on
    matplotlib.pyplot.xlabel('Frequency (Mhz)')     # label x axis
    matplotlib.pyplot.ylabel('Relative Power (dB)') # label y axis
    matplotlib.pyplot.show()

    while True:
        matplotlib.pyplot.clf()
        samples = sdr.read_samples(256*1024) # read samples from sdr
        matplotlib.pyplot.psd(samples, NFFT=1024, Fs=sdr.sample_rate/1e6, Fc=sdr.center_freq/1e6)
        fig.canvas.draw()

        fig.canvas.flush_events()

    sdr.close()

except rtlsdr.rtlsdr.LibUSBError as err:
    print(f"Error: {err}")
    quit()
