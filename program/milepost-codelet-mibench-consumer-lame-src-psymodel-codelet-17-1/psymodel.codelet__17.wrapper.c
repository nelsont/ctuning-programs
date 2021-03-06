/* 
 Codelet from MILEPOST project: http://cTuning.org/project-milepost
 Updated by Grigori Fursin to work with Collective Mind Framework

 3 "./psymodel.codelet__17.wrapper.c" 3 4
*/

#include <stdio.h>

int __astex_write_message(const char * format, ...);
int __astex_write_output(const char * format, ...);
void __astex_exit_on_error(const char * msg, int code, const char * additional_msg);
void * __astex_fopen(const char * name, const char * mode);
void * __astex_memalloc(long bytes);
void __astex_close_file(void * file);
void __astex_read_from_file(void * dest, long bytes, void * file);
int __astex_getenv_int(const char * var);
void * __astex_start_measure();
double __astex_stop_measure(void * _before);
typedef float  FLOAT;
typedef double  FLOAT8;
typedef enum sound_file_format_e  {
sf_unknown, sf_wave, sf_aiff, sf_mp3, sf_raw}
sound_file_format;
typedef struct   {
  unsigned long  num_samples;
  int  num_channels;
  int  in_samplerate;
  int  out_samplerate;
  int  gtkflag;
  int  bWriteVbrTag;
  int  quality;
  int  silent;
  int  mode;
  int  mode_fixed;
  int  force_ms;
  int  brate;
  int  copyright;
  int  original;
  int  error_protection;
  int  padding_type;
  int  extension;
  int  disable_reservoir;
  int  experimentalX;
  int  experimentalY;
  int  experimentalZ;
  int  VBR;
  int  VBR_q;
  int  VBR_min_bitrate_kbps;
  int  VBR_max_bitrate_kbps;
  int  lowpassfreq;
  int  highpassfreq;
  int  lowpasswidth;
  int  highpasswidth;
  sound_file_format  input_format;
  int  swapbytes;
  char  *inPath;
  char  *outPath;
  int  ATHonly;
  int  noATH;
  float  cwlimit;
  int  allow_diff_short;
  int  no_short_blocks;
  int  emphasis;
  long int  frameNum;
  long  totalframes;
  int  encoder_delay;
  int  framesize;
  int  version;
  int  padding;
  int  mode_gr;
  int  stereo;
  int  VBR_min_bitrate;
  int  VBR_max_bitrate;
  float  resample_ratio;
  int  bitrate_index;
  int  samplerate_index;
  int  mode_ext;
  float  lowpass1, lowpass2;
  float  highpass1, highpass2;
  int  lowpass_band;
  int  highpass_band;
  int  filter_type;
  int  quantization;
  int  noise_shaping;
  int  noise_shaping_stop;
  int  psymodel;
  int  use_best_huffman;
} lame_global_flags;
typedef FLOAT8  D576[576];
typedef FLOAT8  D192_3[192][3];
typedef struct   {
  FLOAT8  l[21 + 1];
  FLOAT8  s[12 + 1][3];
} III_psy_xmin;
void  astex_codelet__17(lame_global_flags *gfp, FLOAT8 minval[63], FLOAT8 qthr_l[63], FLOAT8 qthr_s[63], FLOAT8 nb_1[4][63], FLOAT8 nb_2[4][63], FLOAT8 s3_s[63 + 1][63 + 1], FLOAT8 s3_l[63 + 1][63 + 1], III_psy_xmin thm[4], III_psy_xmin en[4], FLOAT energy_s[3][129], FLOAT8 eb[63], FLOAT8 cb[63], FLOAT8 thr[63], FLOAT8 w1_l[21], FLOAT8 w2_l[21], FLOAT8 w1_s[12], FLOAT8 w2_s[12], int bu_l[21], int bo_l[21], int bu_s[12], int bo_s[12], int npart_l, int npart_s, int npart_s_orig, int s3ind[63][2], int s3ind_s[63][2], int numlines_s[63], int numlines_l[63], FLOAT8 pe[4], int uselongblock[2], int chn, int __astex_addr__b[1], int __astex_addr__j[1], int __astex_addr__k[1], int __astex_addr__sb[1], int __astex_addr__sblock[1]);
int main(int argc, const char **argv)
{
  lame_global_flags  *gfp;
  FLOAT8  *minval;
  FLOAT8  *qthr_l;
  FLOAT8  *qthr_s;
  FLOAT8  *nb_1;
  FLOAT8  *nb_2;
  FLOAT8  *s3_s;
  FLOAT8  *s3_l;
  III_psy_xmin  *thm;
  III_psy_xmin  *en;
  FLOAT  *energy_s;
  FLOAT8  *eb;
  FLOAT8  *cb;
  FLOAT8  *thr;
  FLOAT8  *w1_l;
  FLOAT8  *w2_l;
  FLOAT8  *w1_s;
  FLOAT8  *w2_s;
  int  *bu_l;
  int  *bo_l;
  int  *bu_s;
  int  *bo_s;
  int  npart_l = 62;
  int  npart_s = 39;
  int  npart_s_orig = 39;
  int  *s3ind;
  int  *s3ind_s;
  int  *numlines_s;
  int  *numlines_l;
  FLOAT8  *pe;
  int  *uselongblock;
  int  chn = 0;
  int  *__astex_addr__b;
  int  *__astex_addr__j;
  int  *__astex_addr__k;
  int  *__astex_addr__sb;
  int  *__astex_addr__sblock;
  void * codelet_data_file_descriptor = (void *) 0;

#ifdef OPENME
  openme_init(NULL,NULL,NULL,0);
  openme_callback("PROGRAM_START", NULL);
#endif

  if (argc < 2)
    __astex_exit_on_error("Please specify data file in command-line.", 1, argv[0]);
  codelet_data_file_descriptor = __astex_fopen(argv[1], "rb");
  
  char * gfp__region_buffer = (char *) __astex_memalloc(0);
  gfp = (lame_global_flags *) (gfp__region_buffer + 0l);
  char * minval__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading minval value from %s\n", argv[1]);
  __astex_read_from_file(minval__region_buffer, 504, codelet_data_file_descriptor);
  minval = (FLOAT8 *) (minval__region_buffer + 0l);
  char * qthr_l__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading qthr_l value from %s\n", argv[1]);
  __astex_read_from_file(qthr_l__region_buffer, 504, codelet_data_file_descriptor);
  qthr_l = (FLOAT8 *) (qthr_l__region_buffer + 0l);
  char * qthr_s__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading qthr_s value from %s\n", argv[1]);
  __astex_read_from_file(qthr_s__region_buffer, 504, codelet_data_file_descriptor);
  qthr_s = (FLOAT8 *) (qthr_s__region_buffer + 0l);
  char * nb_1__region_buffer = (char *) __astex_memalloc(2016);
  __astex_write_message("Reading nb_1 value from %s\n", argv[1]);
  __astex_read_from_file(nb_1__region_buffer, 2016, codelet_data_file_descriptor);
  nb_1 = (FLOAT8 *) (nb_1__region_buffer + 0l);
  char * nb_2__region_buffer = (char *) __astex_memalloc(2016);
  __astex_write_message("Reading nb_2 value from %s\n", argv[1]);
  __astex_read_from_file(nb_2__region_buffer, 2016, codelet_data_file_descriptor);
  nb_2 = (FLOAT8 *) (nb_2__region_buffer + 0l);
  char * s3_s__region_buffer = (char *) __astex_memalloc(32768);
  __astex_write_message("Reading s3_s value from %s\n", argv[1]);
  __astex_read_from_file(s3_s__region_buffer, 32768, codelet_data_file_descriptor);
  s3_s = (FLOAT8 *) (s3_s__region_buffer + 0l);
  char * s3_l__region_buffer = (char *) __astex_memalloc(32768);
  __astex_write_message("Reading s3_l value from %s\n", argv[1]);
  __astex_read_from_file(s3_l__region_buffer, 32768, codelet_data_file_descriptor);
  s3_l = (FLOAT8 *) (s3_l__region_buffer + 0l);
  char * thm__region_buffer = (char *) __astex_memalloc(1952);
  __astex_write_message("Reading thm value from %s\n", argv[1]);
  __astex_read_from_file(thm__region_buffer, 1952, codelet_data_file_descriptor);
  thm = (III_psy_xmin *) (thm__region_buffer + 0l);
  char * en__region_buffer = (char *) __astex_memalloc(1952);
  __astex_write_message("Reading en value from %s\n", argv[1]);
  __astex_read_from_file(en__region_buffer, 1952, codelet_data_file_descriptor);
  en = (III_psy_xmin *) (en__region_buffer + 0l);
  char * energy_s__region_buffer = (char *) __astex_memalloc(1548);
  __astex_write_message("Reading energy_s value from %s\n", argv[1]);
  __astex_read_from_file(energy_s__region_buffer, 1548, codelet_data_file_descriptor);
  energy_s = (FLOAT *) (energy_s__region_buffer + 0l);
  char * eb__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading eb value from %s\n", argv[1]);
  __astex_read_from_file(eb__region_buffer, 504, codelet_data_file_descriptor);
  eb = (FLOAT8 *) (eb__region_buffer + 0l);
  char * cb__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading cb value from %s\n", argv[1]);
  __astex_read_from_file(cb__region_buffer, 504, codelet_data_file_descriptor);
  cb = (FLOAT8 *) (cb__region_buffer + 0l);
  char * thr__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading thr value from %s\n", argv[1]);
  __astex_read_from_file(thr__region_buffer, 504, codelet_data_file_descriptor);
  thr = (FLOAT8 *) (thr__region_buffer + 0l);
  char * w1_l__region_buffer = (char *) __astex_memalloc(168);
  __astex_write_message("Reading w1_l value from %s\n", argv[1]);
  __astex_read_from_file(w1_l__region_buffer, 168, codelet_data_file_descriptor);
  w1_l = (FLOAT8 *) (w1_l__region_buffer + 0l);
  char * w2_l__region_buffer = (char *) __astex_memalloc(168);
  __astex_write_message("Reading w2_l value from %s\n", argv[1]);
  __astex_read_from_file(w2_l__region_buffer, 168, codelet_data_file_descriptor);
  w2_l = (FLOAT8 *) (w2_l__region_buffer + 0l);
  char * w1_s__region_buffer = (char *) __astex_memalloc(96);
  __astex_write_message("Reading w1_s value from %s\n", argv[1]);
  __astex_read_from_file(w1_s__region_buffer, 96, codelet_data_file_descriptor);
  w1_s = (FLOAT8 *) (w1_s__region_buffer + 0l);
  char * w2_s__region_buffer = (char *) __astex_memalloc(96);
  __astex_write_message("Reading w2_s value from %s\n", argv[1]);
  __astex_read_from_file(w2_s__region_buffer, 96, codelet_data_file_descriptor);
  w2_s = (FLOAT8 *) (w2_s__region_buffer + 0l);
  char * bu_l__region_buffer = (char *) __astex_memalloc(84);
  __astex_write_message("Reading bu_l value from %s\n", argv[1]);
  __astex_read_from_file(bu_l__region_buffer, 84, codelet_data_file_descriptor);
  bu_l = (int *) (bu_l__region_buffer + 0l);
  char * bo_l__region_buffer = (char *) __astex_memalloc(84);
  __astex_write_message("Reading bo_l value from %s\n", argv[1]);
  __astex_read_from_file(bo_l__region_buffer, 84, codelet_data_file_descriptor);
  bo_l = (int *) (bo_l__region_buffer + 0l);
  char * bu_s__region_buffer = (char *) __astex_memalloc(48);
  __astex_write_message("Reading bu_s value from %s\n", argv[1]);
  __astex_read_from_file(bu_s__region_buffer, 48, codelet_data_file_descriptor);
  bu_s = (int *) (bu_s__region_buffer + 0l);
  char * bo_s__region_buffer = (char *) __astex_memalloc(48);
  __astex_write_message("Reading bo_s value from %s\n", argv[1]);
  __astex_read_from_file(bo_s__region_buffer, 48, codelet_data_file_descriptor);
  bo_s = (int *) (bo_s__region_buffer + 0l);
  char * s3ind__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading s3ind value from %s\n", argv[1]);
  __astex_read_from_file(s3ind__region_buffer, 504, codelet_data_file_descriptor);
  s3ind = (int *) (s3ind__region_buffer + 0l);
  char * s3ind_s__region_buffer = (char *) __astex_memalloc(504);
  __astex_write_message("Reading s3ind_s value from %s\n", argv[1]);
  __astex_read_from_file(s3ind_s__region_buffer, 504, codelet_data_file_descriptor);
  s3ind_s = (int *) (s3ind_s__region_buffer + 0l);
  char * numlines_s__region_buffer = (char *) __astex_memalloc(252);
  __astex_write_message("Reading numlines_s value from %s\n", argv[1]);
  __astex_read_from_file(numlines_s__region_buffer, 252, codelet_data_file_descriptor);
  numlines_s = (int *) (numlines_s__region_buffer + 0l);
  char * numlines_l__region_buffer = (char *) __astex_memalloc(252);
  __astex_write_message("Reading numlines_l value from %s\n", argv[1]);
  __astex_read_from_file(numlines_l__region_buffer, 252, codelet_data_file_descriptor);
  numlines_l = (int *) (numlines_l__region_buffer + 0l);
  char * pe__region_buffer = (char *) __astex_memalloc(32);
  __astex_write_message("Reading pe value from %s\n", argv[1]);
  __astex_read_from_file(pe__region_buffer, 32, codelet_data_file_descriptor);
  pe = (FLOAT8 *) (pe__region_buffer + 0l);
  char * uselongblock__region_buffer = (char *) __astex_memalloc(8);
  __astex_write_message("Reading uselongblock value from %s\n", argv[1]);
  __astex_read_from_file(uselongblock__region_buffer, 8, codelet_data_file_descriptor);
  uselongblock = (int *) (uselongblock__region_buffer + 0l);
  char * __astex_addr__b__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__b value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__b__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__b = (int *) (__astex_addr__b__region_buffer + 0l);
  char * __astex_addr__j__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__j value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__j__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__j = (int *) (__astex_addr__j__region_buffer + 0l);
  char * __astex_addr__k__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__k value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__k__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__k = (int *) (__astex_addr__k__region_buffer + 0l);
  char * __astex_addr__sb__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__sb value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__sb__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__sb = (int *) (__astex_addr__sb__region_buffer + 0l);
  char * __astex_addr__sblock__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__sblock value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__sblock__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__sblock = (int *) (__astex_addr__sblock__region_buffer + 0l);
  void * _astex_timeval_before = __astex_start_measure();
  int _astex_wrap_loop = __astex_getenv_int("CT_REPEAT_MAIN");
  if (! _astex_wrap_loop)
    _astex_wrap_loop = 1;

#ifdef OPENME
  openme_callback("KERNEL_START", NULL);
#endif

  while (_astex_wrap_loop > 0)
  {
    --_astex_wrap_loop;
  astex_codelet__17(gfp, minval, qthr_l, qthr_s, nb_1, nb_2, s3_s, s3_l, thm, en, energy_s, eb, cb, thr, w1_l, w2_l, w1_s, w2_s, bu_l, bo_l, bu_s, bo_s, npart_l, npart_s, npart_s_orig, s3ind, s3ind_s, numlines_s, numlines_l, pe, uselongblock, chn, __astex_addr__b, __astex_addr__j, __astex_addr__k, __astex_addr__sb, __astex_addr__sblock);

  }

#ifdef OPENME
  openme_callback("KERNEL_END", NULL);
#endif

  __astex_write_output("Total time: %lf\n", __astex_stop_measure(_astex_timeval_before));


#ifdef OPENME
  openme_callback("PROGRAM_END", NULL);
#endif

  return 0;
}

