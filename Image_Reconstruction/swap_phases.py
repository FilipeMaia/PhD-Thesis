#!/usr/bin/python

from pylab import *
from matplotlib import *
from spimage import *
import sys

if(len(sys.argv) < 3):
    print "You must specify the two images you wish to swap!"
    exit(1)
a = sp_image_read(sys.argv[1],0);
#b = sp_image_read(sys.argv[2],0);
#fa = sp_image_fftw3(a);
#fb = sp_image_fftw3(b);
sp_image_write(a,"fa.h5",0);
#sp_image_write(b,"fb.h5",0);
#exit(0)
#ab = sp_image_ifftw3(sp_proj_module(fa,fb, SpOutOfPlace));
#ba = sp_image_ifftw3(sp_proj_module(fb,fa, SpOutOfPlace));
