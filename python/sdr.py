from rtlsdr import rtlsdr, RtlSdr
from matplotlib import pyplot

# open device
try:
    sdr = RtlSdr()

    # configure device
    sdr.sample_rate = 3.2e6  # Max sample rate of rtl-sdr is 3.2 Mhz
                             # Only reliable up to 2.56 Mhz
    sdr.center_freq = 91.5e6 # Center 95 Mhz
    sdr.gain = 'auto'

    pyplot.ion()                         # set interactive mode on - allows for updating graph
    fig = pyplot.figure()                # pyplot figure to draw on
    pyplot.xlabel('Frequency (Mhz)')     # label x axis
    pyplot.ylabel('Relative Power (dB)') # label y axis
    pyplot.show()                        # show psd graph

    while True:
        pyplot.clf()
        samples = sdr.read_samples(256*1024) # read samples from sdr
        pyplot.psd(samples, NFFT=1024, Fs=sdr.sample_rate/1e6, Fc=sdr.center_freq/1e6) # create power spectral density graph
        fig.canvas.draw() # update figure

        fig.canvas.flush_events()
    sdr.close()
except rtlsdr.LibUSBError as err:
    print(err)
