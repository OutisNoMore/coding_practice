import numpy
import matplotlib.pyplot

Fs = 1 # Sample rate = 1 Hz
N = 100 # 100 samples

# create time domain signal
t = numpy.arange(100)
t_domain = numpy.sin(0.15 * 2 * numpy.pi * t)

# create frequency domain using Fast Fourier Transform
f_domain = numpy.fft.fftshift(numpy.fft.fft(t_domain))
f_domain_mag = numpy.abs(f_domain) # magnitude of f-domain signale
f_domain_phase = numpy.angle(f_domain) # phase of f-domain signal

span = numpy.arange(-Fs/2, Fs/2, Fs/N) # span or range of frequency domain

# create display to plot magnitude
matplotlib.pyplot.figure(0) 
matplotlib.pyplot.plot(span, f_domain_mag, '.-')
#create dispaly for phase
matplotlib.pyplot.figure(1)
matplotlib.pyplot.plot(span, f_domain_phase, '.-')
# show graphs
matplotlib.pyplot.show()
