#ifndef __HISI_FB_H_
#define __HISI_FB_H_


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "3531/hifb.h"

static struct fb_bitfield g_r16 = {16, 8, 0};
static struct fb_bitfield g_g16 = {8, 8, 0};
static struct fb_bitfield g_b16 = {0, 8, 0};
static struct fb_bitfield g_a16 = {24, 8, 0};

int g_fb_fd = -1;

void qt_run_env()
{
  system("umount /tmp");
  system( "mount -t tmpfs -o size=32m none /tmp" );
}



int init_fb(int w, int h)
{
  struct fb_fix_screeninfo fix;
  struct fb_var_screeninfo var;
  HIFB_POINT_S stPoint = {0, 0};

  char file[12] = "/dev/fb0";

  /* 1. open framebuffer device overlay 0 */
  g_fb_fd = open(file, O_RDWR, 0);
  if(g_fb_fd < 0)
  {
    printf("open %s failed!\n",file);
    return -1;
  }

  // 2. set the screen original position
  if (ioctl(g_fb_fd, FBIOPUT_SCREEN_ORIGIN_HIFB, &stPoint) < 0)
  {
    printf("set screen original show position failed!\n");
    close(g_fb_fd);
    return -1;
  }
  /* 3.set alpha */
  HIFB_ALPHA_S stAlpha;
  stAlpha.bAlphaEnable = HI_TRUE;
  stAlpha.bAlphaChannel = HI_FALSE;
  stAlpha.u8Alpha0 = 0x0;
  stAlpha.u8Alpha1 = 0xff;
  stAlpha.u8GlobalAlpha = 0xff;
  if (ioctl( g_fb_fd, FBIOPUT_ALPHA_HIFB,  &stAlpha) < 0)
  {
    printf("Set alpha failed!\n");
    close( g_fb_fd );
    return HI_NULL;
  }

  /* 4. get the variable screen info */
  if (ioctl(g_fb_fd, FBIOGET_VSCREENINFO, &var) < 0)
  {
    printf("Get variable screen info failed!\n");
    close(g_fb_fd);
    return -1;
  }

  /* 5. modify the variable screen info
    the screen size: IMAGE_WIDTH*IMAGE_HEIGHT
    the virtual screen size: VIR_SCREEN_WIDTH*VIR_SCREEN_HEIGHT
    (which equals to VIR_SCREEN_WIDTH*(IMAGE_HEIGHT*2))
    the pixel format: ARGB1555
    */
  var.xres_virtual = w;
  var.yres_virtual = h;
  var.xres = w;
  var.yres = h;

  var.transp= g_a16;
  var.red = g_r16;
  var.green = g_g16;
  var.blue = g_b16;
  var.bits_per_pixel = 32;
  var.activate = FB_ACTIVATE_FORCE;
  /* 6. set the variable screeninfo */
  int rr = ioctl(g_fb_fd, FBIOPUT_VSCREENINFO, &var);
  if (rr < 0)
  {
    printf("Put variable screen info failed!     %d \n",rr);
    close(g_fb_fd);
    return -1;
  }
  return 0;
}




#endif
