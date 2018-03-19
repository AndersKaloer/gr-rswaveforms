/* -*- c++ -*- */
/* 
 * Copyright 2018 Anders Kalør <anders@kaloer.com>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H
#define INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H

#include <rswaveforms/smu_waveform_sink.h>
#include <cstdint>


// Maximum length of printed unsigned long
#if ULONG_MAX <= 4294967295UL
#define ULONG_MAX_LEN 10
#elif ULONG_MAX <= 18446744073709551615ULL
#define ULONG_MAX_LEN 20
#endif

namespace gr {
  namespace rswaveforms {

    class smu_waveform_sink_impl : public smu_waveform_sink
    {
     private:
      FILE *d_fp = NULL;
      unsigned int d_f_level_offs_field_width = 8;
      unsigned int d_f_level_offs_field_prec = 6;
      unsigned int d_f_samples_field_width = ULONG_MAX_LEN;
      unsigned int d_f_waveform_field_width = ULONG_MAX_LEN;
      unsigned int d_f_level_offs_pos = 0;
      unsigned int d_f_samples_pos = 0;
      unsigned int d_f_waveform_pos = 0;
      float d_peak_power_dBfs = 0.0f;
      float d_acc_power = 0.0f;
      unsigned long d_num_samples = 0.0;
      unsigned int d_sample_rate = 0.0;
      float *d_float_buf = NULL;
      uint16_t *d_uint16_buf = NULL;
      float *d_float_arr_buf = NULL;
      int16_t *d_i_buf = NULL;
      int16_t *d_q_buf = NULL;
      int d_alloc_buf_size = 0;

    protected:
      void open_file(const char *filename);
      void write_header();
      void update_header(float rms, float peak, int num_samples);
      void write_samples(const gr_complex *data, int len);
      void close_file();

     public:
      smu_waveform_sink_impl(const char *filename, unsigned int sample_rate);
      ~smu_waveform_sink_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace rswaveforms
} // namespace gr

#endif /* INCLUDED_RSWAVEFORMS_SMU_WAVEFORM_SINK_IMPL_H */

