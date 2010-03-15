#include <spimage.h>

int main(int argc, char ** argv){
  Image * a = sp_image_read(argv[1],0);
  sp_image_write(a,"fa.h5",0);
  Image * b = sp_image_read(argv[2],0);
  Image * fa = sp_image_fft(a);
  Image * fb = sp_image_fft(b);
  for(int i = 0;i<sp_image_size(fa);i++){
    fa->mask->data[i] = 1;
    fb->mask->data[i] = 1;
  }
  Image * fab = sp_proj_module(fa,fb, SpOutOfPlace);
  Image * fba = sp_proj_module(fb,fa, SpOutOfPlace); 
  sp_image_write(sp_image_ifft(fab),"ab.png",SpColormapGrayScale);
  sp_image_write(sp_image_ifft(fba),"ba.png",SpColormapGrayScale);
  return 0;
}
